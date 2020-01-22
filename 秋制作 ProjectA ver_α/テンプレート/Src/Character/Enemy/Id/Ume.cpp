#include "Ume.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../CharacterManager.h"
#include "../..//..//Data/GameData.h"
#include "../../../Engine/Input.h"
#include "../../../Object/Object.h"
#include "../../../Object/ObjectManager.h"
#include "../../../Engine/Audio/Audio.h"
#include "../../../Utility/Probability.h"


void Ume::Init()
{
}

void Ume::Update()
{
	Probability Prob;
	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());
	m_iFrameCount++;

#if 1
	if (GetKeyDown(THREE_KEY)) {

		m_iFrameCount = 0;
		m_IsActive = true;
		m_RoomId = RoomID::ROOM_WORK;
	}
#endif

#if 1
	if (m_IsActive == false && m_iFrameCount >= 100) {
		if (Prob.GetRandomValue(0, m_EnemyData.m_SpownJudge, 1) == false) { 
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

#pragma region サクラの移動
	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			if (g_Manager.IsSameRoom(ROOM_RECEPTION) == true) {
				m_iFrameCount = 0;
				break;
			}

			m_iFrameCount = 0;
			m_RoomId = RoomID::ROOM_RECEPTION;
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			if (g_Manager.IsSameRoom(RIGHT_CORRIDOR) == true) {
				m_iFrameCount = 0;
				break;
			}

			m_iFrameCount = 0;
			m_RoomId = RoomID::RIGHT_CORRIDOR;
		}
		break;

	case RoomID::RIGHT_CORRIDOR:

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			if (g_Manager.IsSameRoom(RIGHT_SHOJI) == true) {
				m_iFrameCount = 0;
				break;
			}

			m_iFrameCount = 0;
			m_RoomId = RoomID::RIGHT_SHOJI;
		}
		break;

	case RoomID::RIGHT_SHOJI:
	{
		static bool once = false;
		if (!once)
		{
			pAudio->Play("YukaKisimiSE", 0);
			once = true;
		}

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			if (g_Manager.IsSameRoom(ROOM_LEFT_PRAYER) == true
				|| g_Manager.IsSameRoom(ROOM_PRAYER) == true) {
				m_iFrameCount = 0;
				break;
			}
			once = false;
			m_iFrameCount = 0;
			m_RoomId = RoomID::ROOM_RIGHT_PRAYER;
		}
	}
		break;
	default:
		break;
	}
#pragma endregion

	switch (m_RoomId)
	{
	case RoomID::ROOM_RIGHT_PRAYER:
	{
		if (m_pPlayer->HasMask() == true
			&& m_pPlayer->CurrentViewID() == SubGameScene::RIGHT_VIEW) {

			m_iFrameCount = 0;
			m_IsActive = false;
			m_RoomId = ROOM_WORK;
		}
		static bool once = false;
		// キルアニメーションが終わったら殺す処理
		if (m_CanKill && m_Color.a >= 1.5f) {
			m_iFrameCount = 0;
			m_HasKill = true;
			once = false;
			//m_CanKill = false;
		}

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			// ゲームオーバー処理
			m_CanKill = true;

			if (!once)
			{
				pAudio->Play("UmeKillVoice", 0);
				once = true;
			}

			if (m_CanKill) { m_Color.a += 0.01f; }
		}
		break;
	}
	default:
		break;
	}
}

void Ume::LoadTex()
{
}

void Ume::Draw()
{
	Object* pRightCandle = ObjManager()->GetObj(ObjID::CANDLE_RIGHT);
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (m_IsActive == false)
	{
		if (pPlayer->CurrentViewID(SubGameScene::WORKSHOP_VIEW)) {

			DrawTexture(960.0f, 540.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::UME_SPAWN_TEX));
		}

		return;
	}

	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (pPlayer->CurrentViewID(SubGameScene::WORKSHOP_VIEW)) {

			DrawTexture(960.0f, 540.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::UME_SPAWN_TEX));
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (pPlayer->CurrentViewID(SubGameScene::RECEPTION_ROOM_VIEW)) {

			DrawTexture(750.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::UME_SPAWN_TEX));
		}
		break;

	case RoomID::RIGHT_CORRIDOR:

		if (pPlayer->CurrentViewID(SubGameScene::RIGHT_CORRIDOR_VIEW)) {

			DrawTexture(900.0f, 470.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::UME_WALK_TEX));
		}
		break;

	case RoomID::RIGHT_SHOJI:

		if (pPlayer->CurrentViewID(SubGameScene::RIGHT_VIEW)
				&& pRightCandle->HasCaLight() == true) {

			DrawTexture(740.0f, 700.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::UME_LOOK_TEX));
		}
		break;

	case RoomID::ROOM_RIGHT_PRAYER:

		if (pPlayer->CurrentViewID(SubGameScene::RIGHT_VIEW)) {

			DrawTexture(450.0f, 630.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::UME_PLAYER_TEX));
		}
		break;

	default:
		break;
	}
}

void Ume::KillAnimation()
{
	if (m_CanKill == true)
	{
		DrawAnimation(0.0f, 0.0f, &m_AnimationTex);
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::UME_KILLANIME_TEX));
		DrawFade(false, m_Color);
		//if (DrawBlood(0.f, 0.f) == true) { m_CanKill = false; }
	}
}

