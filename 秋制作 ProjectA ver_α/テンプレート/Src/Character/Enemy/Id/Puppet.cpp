#include "Puppet.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Timer/Timer.h"
#include "../../../Object/Item/Id/PlayerItem.h"

void Margaret::Init()
{
	CreateTexture("Res/Game/Enemy/Margaret/KillAnimation/1_.png", m_AnimationTex.m_TextureData[0]);
	CreateTexture("Res/Game/Enemy/Margaret/KillAnimation/2_.png", m_AnimationTex.m_TextureData[1]);
	CreateTexture("Res/Game/Enemy/Margaret/KillAnimation/3_.png", m_AnimationTex.m_TextureData[2]);

	// 目のUI
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/UI_me_64.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MargaretEyeUITex);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_1.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MargaretPiza1);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_2.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MargaretPiza2);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_3.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MargaretPiza3);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_4.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MargaretPiza4);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_5.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MargaretPiza5);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_6.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MargaretPiza6);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_7.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MargaretPiza7);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_8.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MargaretPiza8);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_9.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MargaretPiza9);
}

void Margaret::Update()
{
	static bool CountFrag = false;
	if (GetKeyDown(DOWN_KEY)) {
		CountFrag = true;
		m_iFrameCount = 1600;
	}

	// モニターシーンかつ子供部屋を見ているとき
	if (m_pPlayer->HasMonitor() == true
		&& m_pPlayer->CurrentViewMonitorID() == MonitorView::CHILD_ROOM_VIEW) {

		m_iFrameCount += 2;
		// 上限値になったら上限値をいれる
		if (m_iFrameCount >= MAX_COUNT) {
			m_iFrameCount = MAX_COUNT;
		}
	}
	else if (CountFrag){
		m_iFrameCount--;
	}

	if (m_iFrameCount >= 3200) {
		m_TextureCategory = EnemyCategoryTextureList::MargaretPiza1;
	}
	else if (m_iFrameCount < 3200 && m_iFrameCount > 2800) {
		m_TextureCategory = EnemyCategoryTextureList::MargaretPiza2;
	}
	else if (m_iFrameCount < 2800 && m_iFrameCount > 2400) {
		m_TextureCategory = EnemyCategoryTextureList::MargaretPiza3;
	}
	else if (m_iFrameCount < 2400 && m_iFrameCount > 2000) {
		m_TextureCategory = EnemyCategoryTextureList::MargaretPiza4;
	}
	else if (m_iFrameCount < 2000 && m_iFrameCount > 1600) {
		m_TextureCategory = EnemyCategoryTextureList::MargaretPiza5;
	}
	else if (m_iFrameCount < 1600 && m_iFrameCount > 1200) {
		m_TextureCategory = EnemyCategoryTextureList::MargaretPiza6;
	}
	else if (m_iFrameCount < 1200 && m_iFrameCount > 800) {
		m_TextureCategory = EnemyCategoryTextureList::MargaretPiza7;
	}
	else if (m_iFrameCount < 800 && m_iFrameCount > 400) {
		m_TextureCategory = EnemyCategoryTextureList::MargaretPiza8;
	}
	else if (m_iFrameCount < 400 && m_iFrameCount > 0) {
		m_TextureCategory = EnemyCategoryTextureList::MargaretPiza9;
	}



	if (m_iFrameCount <= 0) {

		m_IsActive = true;
	}


	if (m_IsActive == false) { return; }
	// アクティブじゃなかったらここより下の処理にはいかない

	if (m_IsActive == true) {
		// ↓ゲームオーバー処理↓ //
		m_CanKill = true;
	}

	// キルアニメーションが終わったら殺す処理
	if (m_AnimationTex.m_Counter >= 2) {
		m_iFrameCount = 0;
		m_HasKill = true;
		m_CanKill = false;
	}

}

void Margaret::LoadTex(SceneId id_)
{
	switch (id_)
	{
	case CenterScene:
		LoadTexture("Res/Game/Enemy/Margaret/mag_camera_base.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterPuppet);
		break;

	case MonitorScene:
		LoadTexture("Res/Game/Enemy/Margaret/mag_camera_base.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterPuppet);
		LoadTexture("Res/Game/Enemy/Margaret/mag_camera_eye.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPuppetTex);


		break;
	default:
		break;
	}
}

void Margaret::Draw()
{
	if (m_IsActive == false)
	{
		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::CHILD_ROOM_VIEW) {

			DrawTexture(500.0f, 600.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPuppetTex));
			DrawTexture(500.0f, 600.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterPuppet));
		
			DrawTexture(1200.0f, 700.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MargaretEyeUITex));
			DrawTexture(1200.0f, 800.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, m_TextureCategory));
		}
	}
}

void Margaret::KillAnimation()
{
	if (m_CanKill == true)
	{
		DrawAnimation(0.0f, 0.0f, &m_AnimationTex);
	}
}
