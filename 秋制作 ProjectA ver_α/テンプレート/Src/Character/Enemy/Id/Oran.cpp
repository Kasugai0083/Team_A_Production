#include "Oran.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../..//..//Data/GameData.h"
#include "../../../Object/ObjectManager.h"
#include "../../../Engine/Input.h"
#include "../../../Engine/Audio/Audio.h"

void Ran::Init()
{
}

void Ran::Update()
{
	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());
	m_iFrameCount++;
	
	//追加中！
	Object* pCenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);

	if (GetKeyDown(FOUR_KEY)) {

		m_iFrameCount = 0;
		m_IsActive = true;
		m_RoomId = RoomID::ROOM_STORAGE;
	}

#if 0
	if (m_IsActive == false && m_iFrameCount >= 2000) {

		m_iFrameCount = 0;
		m_IsActive    = true;
		m_RoomId = RoomID::ROOM_STORAGE;
	}
#endif

	if (m_IsActive == false) { return; }
	// 死んでたらここより下の処理にはいかない

#pragma region フォクシーの移動
	switch (m_RoomId)
	{
	case RoomID::ROOM_STORAGE:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::HALL_BACK;
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
	case RoomID::HALL_BACK:
	case RoomID::HALL_FRONT:
	{
		//ここ変えたい！//
		static int ActiveTimer = 0;
		if (pCenterCandle->HasCaLight() == true) {

			m_iFrameCount = 0;
		}
		if (ActiveTimer >= 1200) {

			m_IsActive = false;
		}
		ActiveTimer++;

		break;
		//ここ変えたい！//
	}

	case RoomID::ROOM_PRAYER:
	{
		m_CanKill = true;
		static bool once = false;
		if (!once)
		{
			pAudio->Play("OranKillVoice");
			once = true;
		}

		// キルアニメーションが終わったら殺す処理
		if (m_AnimationTex.m_Counter >= 2) {
			m_iFrameCount = 0;
			m_HasKill = true;
			m_CanKill = false;
		}
	}
		break;
	default:
		break;
	}
}

void Ran::LoadTex()
{
	LoadTexture("Res/Game/Enemy/Ran/ran_come_gray.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_SPAWN_TEX);
	LoadTexture("Res/Game/Enemy/Ran/ran_come.png",		TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_NEAR_TEX);
	LoadTexture("Res/Game/Enemy/Ran/Ran_Far.png",		TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_FAR_TEX);
	LoadTexture("Res/Game/Enemy/Ran/KillAnimation/ran_kill.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_KILLANIME_TEX);

	CreateTexture("Res/Game/Enemy/Ran/KillAnimation/1_.png", m_AnimationTex.m_TextureData[0]);
	CreateTexture("Res/Game/Enemy/Ran/KillAnimation/2_.png", m_AnimationTex.m_TextureData[1]);
	CreateTexture("Res/Game/Enemy/Ran/KillAnimation/3_.png", m_AnimationTex.m_TextureData[2]);
}

void Ran::Draw()
{
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (m_IsActive == false)
	{
		if (pPlayer->CurrentViewID(SubGameScene::STORE_ROOM_VIEW)) {

			DrawTexture(840.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_SPAWN_TEX));
		}

		return;
	}

	Object* pCenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);

	switch (m_RoomId)
	{
	case RoomID::ROOM_STORAGE:

		if (pPlayer->CurrentViewID(SubGameScene::STORE_ROOM_VIEW)) {

			DrawTexture(840.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_SPAWN_TEX));
		}
		break;

	case RoomID::HALL_BACK:

		if (pPlayer->CurrentViewID(SubGameScene::CENTER_VIEW)
				&& pCenterCandle->HasCaLight() == true) {

			DrawTexture(650.0f, 340.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_FAR_TEX));
		}
		break;

	case RoomID::HALL_FRONT:

		if (pPlayer->CurrentViewID(SubGameScene::CENTER_VIEW)
				&& pCenterCandle->HasCaLight() == true) {
				
			DrawTexture(880.0f, 550.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_NEAR_TEX));
		}
		break;
	default:
		break;
	}
}

void Ran::KillAnimation()
{
	if (m_CanKill == true)
	{
		DrawAnimation(0.0f, 0.0f, &m_AnimationTex);
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_KILLANIME_TEX));
	}
}
