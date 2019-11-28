#include "../Engine/Graphics.h"
#include "../Engine/Input.h"
#include "../Texture/Texture.h"
#include "OpeningScene.h"
#include "../Engine/Calculation.h"
#include "..//Timer/Timer.h"
#include "../Character/Player/Player.h"
#include "../Character/CharacterManager.h"
#include "../Character/CharacterID.h"

// ゲームオーバーシーンの初期化
void InitOpeningScene();
// ゲームオーバーシーンのメイン
void MainOpeningScene();
// ゲームオーバーシーンの終了
SceneId FinishOpeningScene();

SceneId UpdateOpeningScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitOpeningScene();
		break;
	case SceneStep::MainStep:
		MainOpeningScene();
		break;
	case SceneStep::EndStep:
		return FinishOpeningScene();
		break;
	}

	return SceneId::OpeningScene;
}

enum class Days {
	DAY_0,
	DAY_1,
	DAY_2,
	DAY_3,
};

Days days = Days::DAY_0;

void DrawOpeningScene()
{
	switch (days)
	{
	case Days::DAY_0:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_OPENING, OpeningCategoryTextureList::OpeningDiaryTex));
		break;
	case Days::DAY_1:
		break;
	case Days::DAY_2:
		break;
	case Days::DAY_3:
		break;
	default:
		break;
	}

}

void InitOpeningScene()
{

	LoadTexture("Res/Opening/diary.png", TEXTURE_CATEGORY_OPENING, OpeningCategoryTextureList::OpeningDiaryTex);
	ChangeSceneStep(SceneStep::MainStep);

}

void MainOpeningScene()
{

	if (OnMouseDown(Left) == true) {
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishOpeningScene()
{
	ReleaseCategoryTexture(TEXTURE_CATEGORY_OPENING);

	return SceneId::GameScene;
}

