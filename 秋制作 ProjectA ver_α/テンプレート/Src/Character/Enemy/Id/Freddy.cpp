#include "Freddy.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Scene/GameScene/GameData.h"

void Ohagi::Init()
{
}

void Ohagi::Update()
{
	m_iFrameCount++;

	if (m_IsDeath == true && m_iFrameCount >= 200) {

		m_iFrameCount = 0;
		m_IsDeath	  = false;
		m_RoomId	  = RoomID::ROOM_WORK;
	}

	if (m_IsDeath == true) { return; }
	// 死んでたらここより下の処理にはいかない

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
			m_IsDeath	  = true;
		}

		if (m_iFrameCount >= 300) {

			m_HasKill     = true;
		}
		break;
	}
}

void Ohagi::LoadTex(SceneId id_)
{
	switch (id_)
	{
	case GameScene:
		LoadTexture("Res/Game/Enemy/Freddy.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterFreddy);
		break;

	case MonitorScene:
		LoadTexture("Res/Game/Enemy/Freddy.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorFreddy);
		break;
	default:
		break;
	}
}

void Ohagi::Draw()
{
	// 参照用変数
	//GameData* pGamedate = &g_GameData;
	//if (pGamedate == nullptr) {

	//	return;
	//}

	if (m_IsDeath == true) { return; }
	// 死んでたらここより下の処理にはいかない

	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (GetCurrentSceneId() == SceneId::MonitorScene 
			&& MonitorFunc()->Get() == MonitorTransition::Id::Spown) {

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorFreddy));
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(960.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterFreddy));
		}
		break;

	case RoomID::ROOM_PRAYER:

		if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(960.0f, 540.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterFreddy));
		}
		break;
	default:
		break;
	}
}
