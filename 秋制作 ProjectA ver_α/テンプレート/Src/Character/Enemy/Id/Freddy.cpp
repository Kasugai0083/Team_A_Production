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

	if (m_IsDeath == true && m_iFrameCount >= 2000) {

		m_iFrameCount = 0;
		m_IsDeath	  = false;
		m_RoomId	  = RoomID::ROOM_WORK;
	}

	if (m_IsDeath == true) { return; }
	// Ž€‚ñ‚Å‚½‚ç‚±‚±‚æ‚è‰º‚Ìˆ—‚É‚Í‚¢‚©‚È‚¢

#pragma region ƒIƒnƒM‚ÌˆÚ“®
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
		LoadTexture("Res/Game/Enemy/Freddy_Far.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::FredyFarTex);
		LoadTexture("Res/Game/Enemy/Freddy_Near.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::FredyNearTex);
		break;

	case MonitorScene:
		LoadTexture("Res/Game/Enemy/Freddy_Near.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::FredyNearTex);

		break;
	default:
		break;
	}
}

void Ohagi::Draw()
{
	if (m_IsDeath == true) { return; }
	// Ž€‚ñ‚Å‚½‚ç‚±‚±‚æ‚è‰º‚Ìˆ—‚É‚Í‚¢‚©‚È‚¢

	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (GetCurrentSceneId() == SceneId::MonitorScene 
			&& GameView()->CurrentMonitorID() == MonitorView::WORKSHOP_VIEW) {

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::FredyNearTex));
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::RECEPTION_ROOM_VIEW) {

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::FredyNearTex));
		}
		break;

	case RoomID::HALL_BACK:

		if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(700.0f, 530.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::FredyFarTex));
		}
		break;

	case RoomID::HALL_FRONT:

		if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(700.0f, 530.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::FredyNearTex));
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
