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
	}
}

bool Check() {
	Character* tmp_player = g_Manager.GetCharacter(PLAYER);
	return tmp_player->IsActive();
}

void InitClearScene()
{
	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init();

	LoadTexture("Res/End/EndBg.png", TEXTURE_CATEGORY_CLEAR, ClearCategoryTextureList::ClearBgTex);
	LoadTexture("Res/End/GameOver.png", TEXTURE_CATEGORY_CLEAR, ClearCategoryTextureList::ClearGameOverTex);

	//true => クリア時Daysを進める
	DayManager()->CheckClear();

	//DayManager()->CheckClear(true);
	
	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());
	pAudio->Load("GameOverBGM", "Sound/GameOverBGM.wav");

	ChangeSceneStep(SceneStep::MainStep);

}

void MainClearScene()
{
	SceneController()->GameEnd();

	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());
	static bool once = false;
	if (!once)
	{
		pAudio->Play("GameOverBGM");
		once = true;
	}

	if (OnMouseDown(Left) == true) {
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishClearScene()
{
	ReleaseCategoryTexture(TEXTURE_CATEGORY_CLEAR);

	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());
	pAudio->Stop("GameOverBGM");

	//g_Manager.Release();

	return SceneId::TitleScene;
}

