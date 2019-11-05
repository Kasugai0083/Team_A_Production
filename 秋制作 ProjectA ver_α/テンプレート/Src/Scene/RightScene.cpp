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
#include "../Object/Item/ItemValue.h"

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

void DrawRightItem() {
	ObjManager()->Draw(object::CANDLE_BIG);
	ObjManager()->Draw(object::FIRE_BIG);
	ObjManager()->Draw(object::CANDLE_STAND);
	ObjManager()->Draw(object::CANDLE_EFFECT);
}

void DrawRightScene()
{

	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightBgTex));
	
	DrawRightItem();

	g_Manager.Draw();

}

void InitRightScene()
{
	TimerFunc()->Set(0, Timer::Id::Scene);

	Vec2 EffectPos = { (960.f - CANDLE_EFFECT_SIZE.Width / 2),60.f };
	ObjManager()->Init(object::CANDLE_EFFECT, EffectPos);

	LoadTexture("Res/Game/Right/GameRightBg.png", TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightBgTex);

	g_Manager.LoadTex(GetCurrentSceneId());

	ChangeSceneStep(SceneStep::MainStep);
}

void MainRightScene()
{
	Character* tmp_player = g_Manager.GetCharacter(PLAYER);

	if (tmp_player == nullptr) {
		return;
	}

	//タイマーのアップデート
	TimerFunc()->Update(Timer::Id::Scene);
	TimerFunc()->Update(Timer::Id::MusicBox);

	SceneController()->GameEnd();

	g_Manager.Update();

	ObjManager()->Update();

	//キー入力でシーン遷移
	if (TimerFunc()->Get(Timer::Id::Scene) >= SCENE_WAIT) {

		if (GetKey(A_KEY) == true) {
			SceneController()->SetID(SceneTransition::Id::Center, true);
			ChangeSceneStep(SceneStep::EndStep);
		}
	}

	//クリア時間経過でシーン遷移
	if (TimerFunc()->Get(Timer::Id::Clear) >= CLEAR_TIME) {
		if (tmp_player->IsDeath() == false) {
			SceneController()->SetID(SceneTransition::Id::Clear, true);
			ChangeSceneStep(SceneStep::EndStep);
		}
	}

	//プレイヤーの死亡でシーン遷移
	if (tmp_player->IsDeath() == true) {
		SceneController()->SetID(SceneTransition::Id::Clear, true);
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishRightScene()
{
	ReleaseCategoryTexture(TEXTURE_CATEGORY_RIGHT);
	if (SceneController()->IsGetID(SceneTransition::Id::Clear) == true) {
		SceneController()->SetID(SceneTransition::Id::Clear, false);
		return SceneId::ClearScene;
	}
	else if (SceneController()->IsGetID(SceneTransition::Id::Center) == true) {
		SceneController()->SetID(SceneTransition::Id::Center, false);
		return SceneId::CenterScene;
	}
}

