#include "Ohagi.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../..//..//Data/GameData.h"
#include "../../../Object/Object.h"
#include "../../../Object/ObjectManager.h"
#include "../../../Engine/Input.h"
#include "../../../Engine/Audio/Audio.h"
#include "../../../Utility/Probability.h"


void Ohagi::Init()
{
}

void Ohagi::Update()
{
	Probability Prob;
	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());
	m_iFrameCount++;

#if 1

	if (GetKeyDown(ONE_KEY)) {

		m_iFrameCount = 0;
		m_IsActive = true;
		m_RoomId = RoomID::HALL_BACK;
	}

#endif

#if 1
	if (m_IsActive == false && m_iFrameCount >= 100) {
		if (Prob.GetRandomValue(0,m_EnemyData.m_SpownJudge,0) == false) { 
			m_iFrameCount = 0;
			return; 
		}

		m_iFrameCount = 0;
		m_IsActive	  = true;
		m_RoomId	  = RoomID::ROOM_WORK;
	}
#endif

	if (m_IsActive == false) { return; }
	// アクティブじゃなかったらここより下の処理にはいかない

#pragma region オハギの移動
	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed){
			if (g_Manager.IsSameRoom(ROOM_RECEPTION) == true) {
				m_iFrameCount = 0;
				break;
			}

			m_iFrameCount = 0;
			m_RoomId      = RoomID::ROOM_RECEPTION;
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			if (g_Manager.IsSameRoom(HALL_BACK) == true) {
				m_iFrameCount = 0;
				break;
			}

			m_iFrameCount = 0;
			m_RoomId      = RoomID::HALL_BACK;
		}
		break;

	case RoomID::HALL_BACK:

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			if (g_Manager.IsSameRoom(HALL_FRONT) == true) {
				m_iFrameCount = 0;
				break;
			}

			m_iFrameCount = 0;
			m_RoomId = RoomID::HALL_FRONT;
		}
		break;

	case RoomID::HALL_FRONT:

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			if (g_Manager.IsSameRoom(ROOM_LEFT_PRAYER) == true
				|| g_Manager.IsSameRoom(ROOM_RIGHT_PRAYER) == true) {
				m_iFrameCount = 0;
				break;
			}

			m_iFrameCount = 0;
			m_RoomId = RoomID::ROOM_PRAYER;
		}
		break;
	}
#pragma endregion

	switch (m_RoomId)
	{
	case RoomID::ROOM_PRAYER:

		if (m_pPlayer->HasMask() == true
			&& m_pPlayer->CurrentViewID() == SubGameScene::CENTER_VIEW) {

			m_iFrameCount = 0;
			m_IsActive	  = false;
			m_RoomId	  = ROOM_WORK;
		}

		//// キルアニメーションが終わったら殺す処理
		//if (!m_CanKill && m_iFrameCount >= 400) {
		//	m_iFrameCount = 0;
		//	m_HasKill = true;
		//	m_CanKill = false;
		//}
		static bool once = false;

		// キルアニメーションが終わったら殺す処理
		if (m_CanKill && m_Color.a >= 1.5f) {
			m_iFrameCount = 0;
			m_HasKill = true;
			once = false;
			//m_CanKill = false;
		}

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {

			m_CanKill = true;
			if (!once)
			{
				pAudio->Play("OhagiKillVoice");
				once = true;
			}
		}

		if (m_CanKill) { m_Color.a += 0.01f; }

		break;
	}
}

void Ohagi::LoadTex()
{

}

void Ohagi::Draw()
{
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (m_IsActive == false)
	{
		if (pPlayer->CurrentViewID(SubGameScene::WORKSHOP_VIEW)) {

			DrawTexture(200.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_SPAWN_TEX));
		}

		return;
	}

	Object* pCenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);

	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (pPlayer->CurrentViewID(SubGameScene::WORKSHOP_VIEW)) {

			DrawTexture(200.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_SPAWN_TEX));
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (pPlayer->CurrentViewID(SubGameScene::RECEPTION_ROOM_VIEW)) {

			DrawTexture(190.0f, 360.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_SPAWN_TEX));
		}
		break;

	case RoomID::HALL_BACK:

		if (pPlayer->CurrentViewID(SubGameScene::CENTER_VIEW)
			&& pCenterCandle->HasCaLight() == true) {

			DrawTexture(800.0f, 520.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_FAR_TEX));
		}
		break;

	case RoomID::HALL_FRONT:

		if (pPlayer->CurrentViewID(SubGameScene::CENTER_VIEW)
				&& pCenterCandle->HasCaLight() == true) {

			DrawTexture(650.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_PLAYER_TEX));
		}
		break;

	case RoomID::ROOM_PRAYER:

		if (pPlayer->CurrentViewID(SubGameScene::CENTER_VIEW)
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(1400.0f, 640.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_NEAR_TEX));
		}
		break;
	default:
		break;
	}
}

void Ohagi::KillAnimation()
{
	if (m_CanKill == true)
	{
		DrawAnimation(0.0f, 0.0f, &m_AnimationTex);
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_KILLANIME_TEX));
		DrawFade(false, m_Color);
		//if (DrawBlood(0.f, 0.f) == true) { m_CanKill = false; }
	}
}
