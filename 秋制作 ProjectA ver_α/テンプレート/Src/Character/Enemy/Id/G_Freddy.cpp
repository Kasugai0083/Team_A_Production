#include "G_Freddy.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include <time.h>
//#include <iostream>
#include <stdlib.h>
#include "../../../Object/ObjectManager.h"

void Botan::Init()
{
	srand((unsigned)time(nullptr));
	CreateTexture("Res/Game/Enemy/Botan/KillAnimation/1_.png", m_AnimationTex.m_TextureData[0]);
	CreateTexture("Res/Game/Enemy/Botan/KillAnimation/2_.png", m_AnimationTex.m_TextureData[1]);
	CreateTexture("Res/Game/Enemy/Botan/KillAnimation/3_.png", m_AnimationTex.m_TextureData[2]);
}

void Botan::Update()
{
	if (m_pPlayer->HasGFreddySpown() == true) {
		if (SpawnJudgement(0.00) == true) {
			m_IsActive = true;
		}
		m_SpawnJudgement = true;
	}
	else {
		m_SpawnJudgement = false;
	}

	if (m_IsActive == false) { return; }
	// アクティブじゃなかったらここより下の処理にはいかない
	
	// ボタンの攻撃処理
	//if (m_pPlayer->HasLight() == true
	//	|| m_pPlayer->HasMonitor() == true) {
	//	m_HasKill = true;
	//}

	// ボタンの攻撃処理(仮)
	Object* pCenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);
	if (pCenterCandle->HasCaLight() == true
		|| m_pPlayer->HasMonitor() == true) {

		m_CanKill = true;
	}

	// もしプレイヤーがモニターを見たら
	// 死ぬ処理を入れる
	//
	///////////////////////
	
	// ボタンの死亡処理
	if (m_pPlayer->HasMask() == true) {
		m_IsActive = false;
	}

	// キルアニメーションが終わったら殺す処理
	if (m_AnimationTex.m_Counter >= 2) {
		m_iFrameCount = 0;
		m_HasKill = true;
		m_CanKill = false;
	}
}

bool Botan::SpawnJudgement(double probability_)
{
	static double Probability = probability_; // 確率

	if ((double)rand() / RAND_MAX < Probability) {
		return true;
	}

	return false;
}


void Botan::LoadTex(SceneId id_)
{
	switch (id_)
	{
	case GameScene:
		LoadTexture("Res/Game/Enemy/Botan/Botan.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::EnemyBotanTex);
		break;
	default:
		break;
	}
}

void Botan::Draw()
{
	if (m_IsActive == false) { return; }
	// 死んでいたらここより下の処理にはいかない

	if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER
		&& GetCurrentSceneId() == SceneId::GameScene) {

		DrawTexture(1000.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::EnemyBotanTex));
	}


	if (m_CanKill == true)
	{
		DrawAnimation(0.0f, 0.0f, &m_AnimationTex);
	}
}