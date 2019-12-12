#include "Bonnie.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Scene/GameScene/GameData.h"

void Ume::Init()
{
	CreateTexture("Res/Game/Enemy/Ume/KillAnimation/1_.png", m_AnimationTex.m_TextureData[0]);
	CreateTexture("Res/Game/Enemy/Ume/KillAnimation/2_.png", m_AnimationTex.m_TextureData[1]);
	CreateTexture("Res/Game/Enemy/Ume/KillAnimation/3_.png", m_AnimationTex.m_TextureData[2]);
}

void Ume::Update()
{
	m_iFrameCount++;

	if (m_IsActive == false && m_iFrameCount >= 5000) {

		m_iFrameCount = 0;
		m_IsActive	  = true;
		m_RoomId      = RoomID::ROOM_WORK;
	}

	if (m_IsActive == false) { return; }
	// アクティブじゃなかったらここより下の処理にはいかない

#pragma region ウメの移動
	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::ROOM_RECEPTION;
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::LEFT_CORRIDOR;
		}
		break;

	case RoomID::LEFT_CORRIDOR:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::LEFT_SHOJI;
		}
		break;

	case RoomID::LEFT_SHOJI:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::ROOM_LEFT_PRAYER;
		}
		break;
	}
#pragma endregion

	switch (m_RoomId)
	{
	case RoomID::LEFT_SHOJI:

		if (m_pPlayer->HasMask() == true) {

			m_iFrameCount = 0;
			m_IsActive = false;
		}
		break;

	case RoomID::ROOM_LEFT_PRAYER:

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

void Ume::LoadTex(SceneId id_)
{
	switch (id_)
	{
	case GameScene:
		LoadTexture("Res/Game/Enemy/Sakura/Chica_Look.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::BonnieLookTex);
		LoadTexture("Res/Game/Enemy/Sakura/Chica.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::EnemyBonnieTex);
		LoadTexture("Res/Game/Enemy/Sakura/sak_walk_rough.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::BonnieNearTex);
		break;

	case MonitorScene:
		LoadTexture("Res/Game/Enemy/Sakura/Chica_Spawn.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::BonnieSpawnTex);
		break;
	default:
		break;
	}
}

void Ume::Draw()
{
	if (m_IsActive == false)
	{
		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::WORKSHOP_VIEW) {

			DrawTexture(540.0f, 300.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::BonnieSpawnTex));
		}

		return;
	}

	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::WORKSHOP_VIEW) {

			DrawTexture(540.0f, 300.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::BonnieSpawnTex));
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::RECEPTION_ROOM_VIEW) {

			DrawTexture(50.0f, 400.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::BonnieSpawnTex));
		}
		break;

	case RoomID::LEFT_CORRIDOR:

		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::LEFT_CORRIDOR_VIEW) {

			DrawTexture(670.0f, 300.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::EnemyBonnieTex));
		}
		break;

	case RoomID::LEFT_SHOJI:

		if (GameView()->CurrentViewID() == GameData::SubGameScene::LEFT
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(820.0f, 490.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::BonnieLookTex));
		}
		break;

	case RoomID::ROOM_LEFT_PRAYER:

		if (GameView()->CurrentViewID() == GameData::SubGameScene::LEFT
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(1360.0f, 440.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::BonnieNearTex));
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