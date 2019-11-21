#include "Chica.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../CharacterManager.h"

void Sakura::Init()
{

}

void Sakura::Update()
{
	m_iFrameCount++;

	if (m_IsDeath == true && m_iFrameCount >= 2900) {

		m_iFrameCount = 0;
		m_IsDeath	  = false;
		m_RoomId	  = RoomID::ROOM_WORK;
	}

	if (m_IsDeath == true) { return; }
	// 死んでたらここより下の処理にはいかない

#pragma region サクラの移動
	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId	  = RoomID::ROOM_RECEPTION;
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId	  = RoomID::RIGHT_CORRIDOR;
		}
		break;

	case RoomID::RIGHT_CORRIDOR:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::RIGHT_SHOJI;
		}
		break;

	case RoomID::RIGHT_SHOJI:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::ROOM_RIGHT_PRAYER;
		}
		break;
	}
#pragma endregion

	switch (m_RoomId)
	{
	case RoomID::RIGHT_SHOJI:

		if (m_pPlayer->HasMask() == true) {

			m_iFrameCount = 0;
			m_IsDeath	  = true;
		}

		if (m_iFrameCount >= 300) {
			// ゲームオーバー処理
			m_HasKill	 = true;
		}
		break;
	default:
		break;
	}
}

void Sakura::LoadTex(SceneId id_)
{
	switch (id_)
	{
	case RightScene:
		LoadTexture("Res/Game/Enemy/Chica.png", TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightChicaTex);
		break;

	case MonitorScene:
		LoadTexture("Res/Game/Enemy/Chica.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChicaTex);
		break;
	default:
		break;
	}
}

void Sakura::Draw()
{
	if (m_IsDeath == true) { return; }
	// 死んでたらここより下の処理にはいかない

	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& MonitorFunc()->Get() == MonitorTransition::Id::Spown) {

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChicaTex));
		}
		break;

	case RoomID::RIGHT_CORRIDOR:

		if (GetCurrentSceneId() == SceneId::MonitorScene 
			&& MonitorFunc()->Get() == MonitorTransition::Id::Right_Duct) {

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChicaTex));
		}
		break;

	case RoomID::RIGHT_SHOJI:

		if (GetCurrentSceneId() == SceneId::RightScene) {

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightChicaTex));
		}
		break;
	default:
		break;
	}
}