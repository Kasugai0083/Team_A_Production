#include "Foxy.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Scene/GameScene/GameData.h"

void Ran::Init()
{
}

void Ran::Update()
{
	m_iFrameCount++;

	if (m_IsActive == false && m_iFrameCount >= 2000) {

		m_iFrameCount = 0;
		m_IsActive    = true;
	}

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

		if (m_pPlayer->HasLight() == true) {

			m_iFrameCount = 0;
		}
		break;

	case RoomID::ROOM_PRAYER:

		if (m_iFrameCount >= 80)
		{
			m_iFrameCount = 0;
			m_HasKill = true;
		}

		break;
	default:
		break;
	}
}

void Ran::LoadTex(SceneId id_)
{
	for (int i = 0; i < 3; ++i) {
		KillAnimationTex[i] = new Texture();
	}
	CreateTexture("Res/Game/Enemy/Ran/KillAnimation/1_.png", KillAnimationTex[0]);
	CreateTexture("Res/Game/Enemy/Ran/KillAnimation/2_.png", KillAnimationTex[1]);
	CreateTexture("Res/Game/Enemy/Ran/KillAnimation/3_.png", KillAnimationTex[2]);

	switch (id_)
	{
	case GameScene:
		LoadTexture("Res/Game/Enemy/Ran/Ran.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanTex);
		LoadTexture("Res/Game/Enemy/Ran/Ran_Near.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanNearTex);
		LoadTexture("Res/Game/Enemy/Ran/Ran_Far.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanFarTex);
		break;

	case MonitorScene:
		LoadTexture("Res/Game/Enemy/Ran/Ran_Near.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanNearTex);
		break;
	default:
		break;
	}
}

void Ran::Draw()
{
	if (m_RoomId == RoomID::ROOM_PRAYER)
	{
		KillAnimation();
		return;
	}

	if (m_IsActive == false)
	{
		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::STORE_ROOM_VIEW) {

			DrawTexture(840.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanNearTex));
		}

		return;
	}

	switch (m_RoomId)
	{
	case RoomID::ROOM_STORAGE:

		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::STORE_ROOM_VIEW) {

			DrawTexture(840.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanNearTex));
		}
		break;

	case RoomID::HALL_BACK:

		if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(900.0f, 540.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanFarTex));
		}
		break;

	case RoomID::HALL_FRONT:

		if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(750.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanNearTex));
		}
		break;
	default:
		break;
	}

}

void Ran::KillAnimation()
{
	static int Timer = 0;
	static int Count = 0;
	++Timer;
	if (Timer > 5) {
		++Count;
		if (Count > 3 - 1) {
			Count = 0;
		}
		Timer = 0;
	}
	DrawTexture(0.0f, 0.0f, KillAnimationTex[Count]);
}
