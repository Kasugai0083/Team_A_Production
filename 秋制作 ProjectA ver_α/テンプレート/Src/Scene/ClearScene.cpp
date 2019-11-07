#include "../Engine/Graphics.h"
#include "../Engine/Input.h"
#include "../Texture/Texture.h"
#include "ClearScene.h"
#include "../Engine/Calculation.h"
#include "..//Timer/Timer.h"
#include "../Character/Player/Player.h"
#include "../Character/CharacterManager.h"
#include "../Character/CharacterID.h"

// ゲームオーバーシーンの初期化
void InitClearScene();
// ゲームオーバーシーンのメイン
void MainClearScene();
// ゲームオーバーシーンの終了
SceneId FinishClearScene();

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
	if (tmp_player->IsDeath() == true) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CLEAR, ClearCategoryTextureList::ClearGameOverTex));
	}
	else {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CLEAR, ClearCategoryTextureList::ClearBgTex));
	}
}

void InitClearScene()
{

	Timer* pTimerInstance = Timer::GetInstance();

	pTimerInstance->Init();

	LoadTexture("Res/End/EndBg.png", TEXTURE_CATEGORY_CLEAR, ClearCategoryTextureList::ClearBgTex);
	LoadTexture("Res/End/GameOver.png", TEXTURE_CATEGORY_CLEAR, ClearCategoryTextureList::ClearGameOverTex);
	ChangeSceneStep(SceneStep::MainStep);

}

void MainClearScene()
{

	SceneController()->GameEnd();

	if (OnMouseDown(Left) == true) {
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishClearScene()
{
	ReleaseCategoryTexture(TEXTURE_CATEGORY_CLEAR);

	return SceneId::TitleScene;
}

