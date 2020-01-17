#include "Botan.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include <time.h>
#include <stdlib.h>
#include "../../../Object/ObjectManager.h"
#include "../../../Engine/Input.h"
#include "../../../Engine/Audio/Audio.h"

void Botan::Init()
{
	srand((unsigned)time(nullptr));
}

void Botan::Update()
{
	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());

	if (m_pPlayer->HasGFreddySpown() == true) {
		if (GetKey(FIVE_KEY)) {
			m_IsActive = true;
		}
		m_SpawnJudgement = true;
	}
	else {
		m_SpawnJudgement = false;
	}

#if 0
	if (m_pPlayer->HasGFreddySpown() == true) {
		if (SpawnJudgement(0.00) == true) {
			m_IsActive = true;
		}
		m_SpawnJudgement = true;
	}
	else {
		m_SpawnJudgement = false;
	}
#endif

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

		static bool once = false;
		if (!once)
		{
			pAudio->Play("BotanKillVoice");
			once = true;
		}
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

void Botan::LoadTex()
{
	// koko
	CreateTexture("Res/Game/Enemy/Botan/KillAnimation/1_.png", m_AnimationTex.m_TextureData[0]);
	CreateTexture("Res/Game/Enemy/Botan/KillAnimation/2_.png", m_AnimationTex.m_TextureData[1]);
	CreateTexture("Res/Game/Enemy/Botan/KillAnimation/3_.png", m_AnimationTex.m_TextureData[2]);
}

void Botan::Draw()
{
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (m_IsActive == false) { return; }
	// 死んでいたらここより下の処理にはいかない

	if (pPlayer->CurrentViewID() == SubGameScene::CENTER_VIEW
		&& GetCurrentSceneId() == SceneId::GameScene) {

		DrawTexture(1360.0f, 540.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::BOTAN_PLAYER_TEX));
	}
}

void Botan::KillAnimation()
{
	if (m_CanKill == true)
	{
		DrawAnimation(0.0f, 0.0f, &m_AnimationTex);
	}
}
