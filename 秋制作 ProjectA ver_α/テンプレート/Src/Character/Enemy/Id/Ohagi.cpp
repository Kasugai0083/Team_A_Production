#include "Ohagi.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../..//..//Data/GameData.h"
#include "../../../Object/Object.h"
#include "../../../Object/ObjectManager.h"
#include "../../../Engine/Input.h"
#include "../../../Engine/Audio/Audio.h"

void Ohagi::Init()
{
}

void Ohagi::Update()
{
	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());
	m_iFrameCount++;

	if (GetKeyDown(ONE_KEY)) {

		m_iFrameCount = 0;
		m_IsActive = true;
		m_RoomId = RoomID::ROOM_WORK;
	}

#if 0
	if (m_IsActive == false && m_iFrameCount >= 2000) {

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

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId      = RoomID::ROOM_RECEPTION;
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId      = RoomID::HALL_BACK;
		}
		break;

	case RoomID::HALL_BACK:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::HALL_FRONT;
		}
		break;

	case RoomID::HALL_FRONT:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::ROOM_PRAYER;
		}
		break;
	}
#pragma endregion

	switch (m_RoomId)
	{
	case RoomID::ROOM_PRAYER:

		if (m_pPlayer->HasMask() == true) {

			m_iFrameCount = 0;
			m_IsActive	  = false;
		}

		if (m_iFrameCount >= 300) {

			m_CanKill = true;

			static bool once = false;
			if (!once)
			{
				pAudio->Play("OhagiKillVoice");
				once = true;
			}
		}

		// キルアニメーションが終わったら殺す処理
		if (m_AnimationTex.m_Counter >= 2) {
			m_iFrameCount = 0;
			m_HasKill = true;
			m_CanKill = false;
		}

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

			DrawTexture(100.0f, 600.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_SPAWN_TEX));
		}
		break;

	case RoomID::HALL_BACK:

		if (pPlayer->CurrentViewID(SubGameScene::CENTER_VIEW)
			&& pCenterCandle->HasCaLight() == true) {

			DrawTexture(530.0f, 420.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_FAR_TEX));
		}
		break;

	case RoomID::HALL_FRONT:

		if (pPlayer->CurrentViewID(SubGameScene::CENTER_VIEW)
				&& pCenterCandle->HasCaLight() == true) {

			DrawTexture(650.0f, 550.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_PLAYER_TEX));
		}
		break;

	case RoomID::ROOM_PRAYER:

		if (pPlayer->CurrentViewID(SubGameScene::CENTER_VIEW)
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(1360.0f, 540.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_NEAR_TEX));
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
	}
}
