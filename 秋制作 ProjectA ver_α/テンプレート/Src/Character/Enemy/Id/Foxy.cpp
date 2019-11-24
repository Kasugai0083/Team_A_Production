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

	if (m_IsDeath == true && m_iFrameCount >= 2000) {

		m_iFrameCount = 0;
		m_IsDeath     = false;
		m_RoomId      = RoomID::ROOM_STORAGE;
	}

	if (m_IsDeath == true) { return; }
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

		m_iFrameCount = 0;
		m_HasKill = true;
		break;
	default:
		break;
	}
}

void Ran::LoadTex(SceneId id_)
{
	switch (id_)
	{
	case GameScene:
		LoadTexture("Res/Game/Enemy/Ran.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanTex);
		LoadTexture("Res/Game/Enemy/Ran_Near.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanNearTex);
		LoadTexture("Res/Game/Enemy/Ran_Far.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanFarTex);
		break;

	case MonitorScene:
		LoadTexture("Res/Game/Enemy/Ran_Near.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanNearTex);
		break;
	default:
		break;
	}
}

void Ran::Draw()
{
	if (m_IsDeath == true) { return; }
	// 死んでたらここより下の処理にはいかない

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
