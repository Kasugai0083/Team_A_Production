#include "Margaret.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Timer/Timer.h"
#include "../../../Object/Item/Id/PlayerItem.h"
#include "../../../Engine/Audio/Audio.h"
#include "../../../Utility/Probability.h"



void Margaret::Init()
{	
}

void Margaret::Update()
{
	if (m_HasKill) { return; }

	EnemyTimer EnemuTimer(10);
	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());



#if 1

	static bool CountFrag = true;

#endif

#if 0

	static bool CountFrag = false;

#endif

	if (GetKeyDown(DOWN_KEY)) {
		CountFrag = true;
		m_iFrameCount = 1600;
	}

	// モニターシーンかつ子供部屋を見ているとき
	if (m_pPlayer->HasMonitor() == true
		&& m_pPlayer->CurrentViewID() == SubGameScene::CHILD_ROOM_VIEW) {

		m_iFrameCount += 2;
		// 上限値になったら上限値をいれる
		if (m_iFrameCount >= MAX_COUNT) {
			m_iFrameCount = MAX_COUNT;
		}
	}
	else if (CountFrag){
		m_iFrameCount--;

		if (m_iFrameCount <= 0) {
			m_iFrameCount = 0;
		}

	}

	if (m_iFrameCount >= 3200) {
		m_TextureCategory = EnemyCategoryTextureList::MARGARET_PIZA_1;
	}
	else if (m_iFrameCount < 3200 && m_iFrameCount > 2800) {
		m_TextureCategory = EnemyCategoryTextureList::MARGARET_PIZA_2;
	}
	else if (m_iFrameCount < 2800 && m_iFrameCount > 2400) {
		m_TextureCategory = EnemyCategoryTextureList::MARGARET_PIZA_3;
	}
	else if (m_iFrameCount < 2400 && m_iFrameCount > 2000) {
		m_TextureCategory = EnemyCategoryTextureList::MARGARET_PIZA_4;
	}
	else if (m_iFrameCount < 2000 && m_iFrameCount > 1600) {
		m_TextureCategory = EnemyCategoryTextureList::MARGARET_PIZA_5;
	}
	else if (m_iFrameCount < 1600 && m_iFrameCount > 1200) {
		m_TextureCategory = EnemyCategoryTextureList::MARGARET_PIZA_6;
	}
	else if (m_iFrameCount < 1200 && m_iFrameCount > 800) {
		m_TextureCategory = EnemyCategoryTextureList::MARGARET_PIZA_7;
	}
	else if (m_iFrameCount < 800 && m_iFrameCount > 400) {
		m_TextureCategory = EnemyCategoryTextureList::MARGARET_PIZA_8;
		// 不穏な音を鳴らす

	}
	else if (m_iFrameCount < 400 && m_iFrameCount > 0) {
		m_TextureCategory = EnemyCategoryTextureList::MARGARET_PIZA_9;
	}



	if (m_iFrameCount <= 0) {
		m_IsActive = true;
	}


	if (m_IsActive == false) { return; }
	// アクティブじゃなかったらここより下の処理にはいかない

	static bool once = false;
	if (m_IsActive == true) {
		// ↓ゲームオーバー処理↓ //
		m_Color.a += 0.01f;

		if (!once)
		{
			pAudio->Play("PuppetKillVoice",0);
			once = true;

			m_CanKill = true;
		}
	}

	// キルアニメーションが終わったら殺す処理
	if (m_CanKill && m_Color.a >= 1.5f) {
		m_iFrameCount = 0;
		m_HasKill = true;
		once = false;
		//m_CanKill = false;
	}



}

void Margaret::LoadTex()
{
}

void Margaret::Draw()
{
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (m_IsActive == false)
	{
		if (pPlayer->CurrentViewID(SubGameScene::CHILD_ROOM_VIEW)) {

			DrawTexture(720.0f,  770.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_SPAWN_EYE_TEX));
			DrawTexture(720.0f,  770.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_SPAWN_BASE_TEX));
			DrawTexture(1200.0f, 700.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_EYE_TEX));
			DrawTexture(1200.0f, 800.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, m_TextureCategory));
		}
	}
}

void Margaret::KillAnimation()
{
	if (m_CanKill == true)
	{
		DrawAnimation(0.0f, 0.0f, &m_AnimationTex);
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_KILLANIME_TEX));
		DrawFade(false, m_Color);

	}
}
