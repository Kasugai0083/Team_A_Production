#include <stdio.h>
#include "../Engine/Input.h"
#include "../Engine/Graphics.h"
#include "../Texture/Texture.h"
#include "../Engine/Calculation.h"
#include "../Character/Player/Player.h"
#include "../Character/Enemy/Enemy.h"
#include "..//Timer/Timer.h"
#include "../Character/CharacterManager.h"
#include "../Object/ObjectManager.h"

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

void DrawLeftItem() {
	ObjManager()->Draw(object::CANDLE_BIG);
	ObjManager()->Draw(object::FIRE_BIG);
	ObjManager()->Draw(object::CANDLE_STAND);
	ObjManager()->Draw(object::CANDLE_EFFECT);
}

void DrawLeftScene()
{
	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex));

	DrawLeftItem();

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
	Character* tmp_player = g_Manager.GetCharacter(PLAYER);

	TimerFunc()->Update(Timer::Id::Scene);
	TimerFunc()->Update(Timer::Id::MusicBox);

	TransButton()->GameEnd();

	g_Manager.Update();

	if (TimerFunc()->Get(Timer::Id::Scene) >= SCENE_WAIT) {

		if (GetKey(D_KEY) == true) {
			TransButton()->Change(SceneTransition::Id::Center, true);
			ChangeSceneStep(SceneStep::EndStep);
		}
	}
	if (tmp_player->IsDeath() == true) {
		TransButton()->Change(SceneTransition::Id::Clear, true);
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishLeftScene()
{
	ReleaseCategoryTexture(TEXTURE_CATEGORY_LEFT);

	if (TransButton()->Research(SceneTransition::Id::Clear) == true) {
		TransButton()->Change(SceneTransition::Id::Clear, false);
		return SceneId::ClearScene;
	}
	if (TransButton()->Research(SceneTransition::Id::Center) == true) {
		TransButton()->Change(SceneTransition::Id::Center, false);
		return SceneId::CenterScene;
	}
}

