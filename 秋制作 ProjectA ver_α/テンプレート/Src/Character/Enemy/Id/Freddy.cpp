#include "Freddy.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Scene/GameScene/GameData.h"
#include "../../../Object/Object.h"
#include "../../../Object/ObjectManager.h"

void Ohagi::Init()
{
	CreateTexture("Res/Game/Enemy/Ohagi/KillAnimation/1_.png", m_AnimationTex.m_TextureData[0]);
	CreateTexture("Res/Game/Enemy/Ohagi/KillAnimation/2_.png", m_AnimationTex.m_TextureData[1]);
	CreateTexture("Res/Game/Enemy/Ohagi/KillAnimation/3_.png", m_AnimationTex.m_TextureData[2]);
}

void Ohagi::Update()
{
	m_iFrameCount++;

	if (m_IsActive == false && m_iFrameCount >= 200) {

		m_iFrameCount = 0;
		m_IsActive	  = true;
		m_RoomId	  = RoomID::ROOM_WORK;
	}

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

void Ohagi::LoadTex(SceneId id_)
{
	switch (id_)
	{
	case GameScene:
		LoadTexture("Res/Game/Enemy/Ohagi/Freddy.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterFreddy);
		LoadTexture("Res/Game/Enemy/Ohagi/Freddy_Far.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::FredyFarTex);
		LoadTexture("Res/Game/Enemy/Ohagi/Freddy_Near.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::FredyNearTex);
		LoadTexture("Res/Game/Enemy/Ohagi/FreddyAAA.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::FredyPlayerTex);
		break;

	case MonitorScene:
		LoadTexture("Res/Game/Enemy/Ohagi/Freddy_Near.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::FredyNearTex);

		break;
	default:
		break;
	}
}

void Ohagi::Draw()
{
	if (m_IsActive == false)
	{
		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::WORKSHOP_VIEW) {

			DrawTexture(200.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterFreddy));
		}

		return;
	}

	Object* pCenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);

	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (GetCurrentSceneId() == SceneId::MonitorScene 
			&& GameView()->CurrentMonitorID() == MonitorView::WORKSHOP_VIEW) {

			DrawTexture(200.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterFreddy));
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::RECEPTION_ROOM_VIEW) {

			DrawTexture(100.0f, 600.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterFreddy));
		}
		break;

	case RoomID::HALL_BACK:

		if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER
			&& GetCurrentSceneId() == SceneId::GameScene
			&& pCenterCandle->HasCaLight() == true) {

			DrawTexture(530.0f, 420.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::FredyFarTex));
		}
		break;

	case RoomID::HALL_FRONT:

		if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER
			&& GetCurrentSceneId() == SceneId::GameScene
				&& pCenterCandle->HasCaLight() == true) {

			DrawTexture(850.0f, 350.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::FredyPlayerTex));
		}
		break;

	case RoomID::ROOM_PRAYER:

		if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(1360.0f, 540.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::FredyNearTex));
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
