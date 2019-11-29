#include "Chica.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../CharacterManager.h"
#include "../../../Scene/GameScene/GameData.h"

void Sakura::Init()
{
	CreateTexture("Res/Game/Enemy/Sakura/KillAnimation/1_.png", m_AnimationTex.m_TextureData[0]);
	CreateTexture("Res/Game/Enemy/Sakura/KillAnimation/2_.png", m_AnimationTex.m_TextureData[1]);
	CreateTexture("Res/Game/Enemy/Sakura/KillAnimation/3_.png", m_AnimationTex.m_TextureData[2]);
}

void Sakura::Update()
{
	m_iFrameCount++;

	if (m_IsActive == false && m_iFrameCount >= 3000) {

		m_iFrameCount = 0;
		m_IsActive	  = true;
	}

	if (m_IsActive == false) { return; }
	// アクティブじゃなかったらここより下の処理にはいかない

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
			m_IsActive	  = false;
		}
		break;

	case RoomID::ROOM_RIGHT_PRAYER:

		if (m_iFrameCount >= 300) {
			// ゲームオーバー処理
			m_CanKill = true;
		}

		// キルアニメーションが終わったら殺す処理
		if (m_AnimationTex.m_Counter >= 2) {
			m_iFrameCount = 0;
			m_HasKill = true;
			m_CanKill = false;
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
	case GameScene:
		LoadTexture("Res/Game/Enemy/Sakura/Chica.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ChicaTex);
		LoadTexture("Res/Game/Enemy/Sakura/Chica_Look.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ChicaLookTex);
		break;

	case MonitorScene:
		LoadTexture("Res/Game/Enemy/Sakura/Chica_Spawn.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ChicaSpawnTex);
		break;
	default:
		break;
	}
}

void Sakura::Draw()
{
	if (m_IsActive == false)
	{
		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::WORKSHOP_VIEW) {

			DrawTexture(1040.0f, 300.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ChicaSpawnTex));
		}

		return;
	}

	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::WORKSHOP_VIEW) {

			DrawTexture(1040.0f, 300.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ChicaSpawnTex));
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (GetCurrentSceneId() == SceneId::MonitorScene 
			&& GameView()->CurrentMonitorID() == MonitorView::RECEPTION_ROOM_VIEW) {

			DrawTexture(540.0f, 300.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ChicaSpawnTex));
		}
		break;

	case RoomID::RIGHT_CORRIDOR:

		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::RIGHT_CORRIDOR_VIEW) {

			DrawTexture(1060.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ChicaSpawnTex));
		}
		break;

	case RoomID::RIGHT_SHOJI:

		if (GameView()->CurrentViewID() == GameData::SubGameScene::RIGHT
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(760.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ChicaLookTex));
		}
		break;

	case RoomID::ROOM_RIGHT_PRAYER:

		if (GameView()->CurrentViewID() == GameData::SubGameScene::RIGHT
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(200.0f, 540.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ChicaTex));
		}
		break;

	default:
		break;
	}


	if (m_CanKill == true)
	{
		DrawAnimation(0.0f, 0.0f, &m_AnimationTex);
	}
}