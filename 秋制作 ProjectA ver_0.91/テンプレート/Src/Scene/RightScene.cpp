#include <stdio.h>
#include "../Engine/Input.h"
#include "../Engine/Graphics.h"
#include "../Texture/Texture.h"
#include "../Engine/Calculation.h"
#include "../Character/Player/Player.h"
#include "../Character/Enemy/Enemy.h"
#include "..//Timer/Timer.h"
#include "../Character/CharacterManager.h"


// ゲーム本編シーンの初期化
void InitRightScene();
// ゲーム本編シーンのメイン処理
void MainRightScene();
// ゲーム本編シーンの終了
SceneId FinishRightScene();

SceneId UpdateRightScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitRightScene();
		break;
	case SceneStep::MainStep:
		MainRightScene();
		break;
	case SceneStep::EndStep:
		return FinishRightScene();
		break;
	}

	return SceneId::RightScene;
}

void DrawRightScene()
{

	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightBgTex));
	
	g_Manager.Draw();

}

void InitRightScene()
{
	TimerFunc()->Set(0, Timer::Id::Scene);

	LoadTexture("Res/Game/Right/GameRightBg.png", TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightBgTex);

	g_Manager.LoadTex(GetCurrentSceneId());

	ChangeSceneStep(SceneStep::MainStep);
}

void MainRightScene()
{

	TimerFunc()->Update(Timer::Id::Scene);

	TransButton()->GameEnd();

	g_Manager.Update();

	if (TimerFunc()->Get(Timer::Id::Scene) >= SCENE_WAIT) {

		if (GetKey(A_KEY) == true) {
			TransButton()->Change(SceneTransition::Id::Center, true);
			ChangeSceneStep(SceneStep::EndStep);
		}
	}
}

SceneId FinishRightScene()
{
	ReleaseCategoryTexture(TEXTURE_CATEGORY_RIGHT);

	if (TransButton()->Research(SceneTransition::Id::Center) == true) {
		TransButton()->Change(SceneTransition::Id::Center, false);
		return SceneId::CenterScene;
	}
}

