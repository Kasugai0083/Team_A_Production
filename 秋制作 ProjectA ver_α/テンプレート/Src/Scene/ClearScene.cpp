#include "../Engine/Graphics.h"
#include "../Engine/Input.h"
#include "../Texture/Texture.h"
#include "ClearScene.h"
#include "../Engine/Calculation.h"
#include "..//Timer/Timer.h"
#include "../Character/Player/Player.h"
#include "../Character/CharacterManager.h"
#include "../Character/CharacterID.h"
#include "../Data/Days/DayController.h"
#include "../Engine/Audio/Audio.h"
#include "../Object/ObjectManager.h"
#include "../Texture/LoadTex.h"

// ゲームオーバーシーンの初期化
void InitClearScene();
// ゲームオーバーシーンのメイン
void MainClearScene();
// ゲームオーバーシーンの終了
SceneId FinishClearScene();

int g_ClearCount = 0;

SceneId UpdateClearScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitClearScene();
		break;
	case SceneStep::MainStep:
		MainClearScene();
		break;
	case SceneStep::EndStep:
		return FinishClearScene();
		break;
	}

	return SceneId::ClearScene;
}

void DrawClearScene()
{
	Character* tmp_player = g_Manager.GetCharacter(PLAYER);
	
	if (tmp_player == nullptr) {
		return;
	}

	//プレイヤー死亡時は背景を変更
	if (tmp_player->IsActive() == false) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CLEAR, ClearCategoryTextureList::ClearGameOverTex));

	}
	else {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CLEAR, ClearCategoryTextureList::ClearBgTex));
		if (DayManager()->GetCurrentDays() == Days::DAY_3) {
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CLEAR, ClearCategoryTextureList::ClearGameEndTex));
		}
	}
}

bool Check() {
	Character* tmp_player = g_Manager.GetCharacter(PLAYER);
	return tmp_player->IsActive();
}

void InitClearScene()
{
	InitTexture();

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init();

	//true => クリア時Daysを進める
	DayManager()->CheckClear();
	
	LoadSceneTex(SceneId::ClearScene);

	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());
	pAudio->Load("GameOverBGM", "Sound/GameOverBGM.wav");

	ChangeSceneStep(SceneStep::MainStep);

}

void MainClearScene()
{
	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());
	static bool once = false;

	Character* pPlayer = g_Manager.GetCharacter(PLAYER);
	if (pPlayer == nullptr) {
		return;
	}

	if (pPlayer->IsActive()) {
		if (!once)
		{
			pAudio->Play("ClearSE");
			once = true;
		}
	}

	SceneController()->GameEnd();

	if (OnMouseDown(Left) == true) {
		once = false;
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishClearScene()
{
	ReleaseCategoryTexture(TEXTURE_CATEGORY_CLEAR);

	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());
	pAudio->Stop("ClearSE");

	// 敵の声を止める
	pAudio->Stop("OhagiKillVoice");
	pAudio->Stop("SakuraKillVoice");
	pAudio->Stop("UmeKillVoice");
	pAudio->Stop("OranKillVoice");
	pAudio->Stop("BotanKillVoice");
	pAudio->Stop("PuppetKillVoice");

	g_Manager.Release();

	return SceneId::TitleScene;
}