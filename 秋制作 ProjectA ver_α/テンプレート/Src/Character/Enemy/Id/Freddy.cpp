#include "Freddy.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Scene/GameScene/GameData.h"


void Freddy::Init()
{
	m_iFrameCount  = 0;
	m_IsDeath	   = true;
	m_HasKill	   = false;
	m_RoomId	   = RoomID::SPAWN_ROOM;
}

void Freddy::Update()
{
#pragma region 参照用変数
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);
	if (pPlayer == nullptr) {

		return;
	}

#pragma endregion

	m_iFrameCount++;

	if (m_IsDeath == true && m_iFrameCount >= 6000) {

		m_iFrameCount = 0;
		m_IsDeath	  = false;
		m_RoomId	  = RoomID::SPAWN_ROOM;
	}

	if (m_IsDeath == true) { return; }
	// 死んでたらここより下の処理にはいかない

#pragma region フレディの移動
	switch (m_RoomId)
	{
	case RoomID::SPAWN_ROOM:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId      = RoomID::CENTER_DUCT;
		}
		break;

	case RoomID::CENTER_DUCT:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId      = RoomID::PLAYER_ROOM;
		}
		break;
	default:
		break;
	}
#pragma endregion


	switch (m_RoomId)
	{
	case RoomID::CENTER_DUCT:

		if (pPlayer->HasLight() == true) {

			m_iFrameCount = 0;
		}
		break;

	case RoomID::PLAYER_ROOM:

		if (pPlayer->HasMask() == true) {

			m_iFrameCount = 0;
			m_IsDeath	  = true;
		}

		if (m_iFrameCount >= 300) {

			m_HasKill     = true;
		}
		break;
	default:
		break;
	}
}

void Freddy::LoadTex(SceneId id_)
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

void Freddy::Draw()
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
	case RoomID::SPAWN_ROOM:

		if (GetCurrentSceneId() == SceneId::MonitorScene 
			&& MonitorFunc()->Get() == MonitorTransition::Id::Spown) {

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorFreddy));
		}
		break;

	case RoomID::CENTER_DUCT:

		if (PepshiMan()->CurrentViewID() == GameData::SubGameScene::CENTER
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(960.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterFreddy));
		}
		break;

	case RoomID::PLAYER_ROOM:

		if (PepshiMan()->CurrentViewID() == GameData::SubGameScene::CENTER
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(960.0f, 540.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterFreddy));
		}
		break;
	default:
		break;
	}
}
