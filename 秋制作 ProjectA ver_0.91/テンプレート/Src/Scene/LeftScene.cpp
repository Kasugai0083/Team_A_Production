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
void InitLeftScene();
// ゲーム本編シーンのメイン処理
void MainLeftScene();
// ゲーム本編シーンの終了
SceneId FinishLeftScene();

SceneId UpdateLeftScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitLeftScene();
		break;
	case SceneStep::MainStep:
		MainLeftScene();
		break;
	case SceneStep::EndStep:
		return FinishLeftScene();
		break;
	}

	return SceneId::LeftScene;
}

void DrawLeftScene()
{
	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex));

	g_Manager.Draw();
}

void InitLeftScene()
{
	TimerFunc()->Set(0, Timer::Id::Scene);

	LoadTexture("Res/Game/Left/GameLeftBg.png", TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex);

	g_Manager.LoadTex(GetCurrentSceneId());

	ChangeSceneStep(SceneStep::MainStep);
}

void MainLeftScene()
{

	TimerFunc()->Update(Timer::Id::Scene);

	TransButton()->GameEnd();

	g_Manager.Update();

	if (TimerFunc()->Get(Timer::Id::Scene) >= SCENE_WAIT) {

		if (GetKey(D_KEY) == true) {
			TransButton()->Change(SceneTransition::Id::Center, true);
			ChangeSceneStep(SceneStep::EndStep);
		}
	}
}

SceneId FinishLeftScene()
{
	ReleaseCategoryTexture(TEXTURE_CATEGORY_LEFT);


	if (TransButton()->Research(SceneTransition::Id::Center) == true) {
		TransButton()->Change(SceneTransition::Id::Center, false);
		return SceneId::CenterScene;
	}
}

