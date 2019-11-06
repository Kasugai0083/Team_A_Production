#include <stdio.h>
#include "../../Scene/Scene.h"
#include "../../Engine/Input.h"
#include "../../Engine/Graphics.h"
#include "../../Texture/Texture.h"
#include "../../Engine/Calculation.h"
#include "../../Character/Enemy/Enemy.h"
#include "../../Timer/Timer.h"
#include "../../Character/CharacterManager.h"
#include "../../Object/ObjectManager.h"
#include "../../Object/ObjectID.h"
#include "GameData.h"
#include "GameScene.h"
#include "../../Object/Item/ItemValue.h"

// ゲーム本編シーンの初期化
void InitGameScene();
// ゲーム本編シーンのメイン処理
void MainGameScene();
// ゲーム本編シーンの終了
SceneId FinishGameScene();

//シーン遷移
SceneId UpdateGameScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitGameScene();
		break;
	case SceneStep::MainStep:
		MainGameScene();
		break;
	case SceneStep::EndStep:
		return FinishGameScene();
		break;
	}

	return SceneId::GameScene;
}

#pragma region 描画関数

namespace Draw {

	Vec2 EffectPos = { (960.f - CANDLE_EFFECT_SIZE.Width / 2),60.f };

	void DrawCenterItem() {
		//キャンドル
		ObjManager()->Draw(object::CANDLE_SMALL);
		ObjManager()->Draw(object::FIRE_SMALL);
		ObjManager()->Draw(object::CANDLE_STAND);
		ObjManager()->Draw(object::CANDLE_EFFECT);

		//プレイヤーのアイテム
		ObjManager()->Draw(object::CRYSTAL);
		ObjManager()->Draw(object::MUSICBOX);

	}

	void DrawLeftItem() {
		ObjManager()->Draw(object::CANDLE_BIG);
		ObjManager()->Draw(object::FIRE_BIG);
		ObjManager()->Draw(object::CANDLE_STAND);
		ObjManager()->Draw(object::CANDLE_EFFECT, EffectPos);
	}

	void DrawRightItem() {
		ObjManager()->Draw(object::CANDLE_BIG);
		ObjManager()->Draw(object::FIRE_BIG);
		ObjManager()->Draw(object::CANDLE_STAND);
		ObjManager()->Draw(object::CANDLE_EFFECT, EffectPos);
	}

}
#pragma endregion

//シーンのメイン処理
void DrawGameScene()
{

	switch (PepshiMan()->CurrentViewID()) {
	case GameData::CENTER:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex));
		Draw::DrawCenterItem();
		break;
	case GameData::RIGHT:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightBgTex));
		Draw::DrawRightItem();
		break;
	case GameData::LEFT:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex));
		Draw::DrawLeftItem();
		break;
	}
	g_Manager.Draw();

}

void InitGameScene()
{
	TimerFunc()->Set(0, Timer::Id::Scene);

	ObjManager()->Init();

	g_Manager.LoadTex(GetCurrentSceneId());

	LoadTexture("Res/Game/Center/GameCenterBg.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex);
	LoadTexture("Res/Game/Left/GameLeftBg.png", TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex);
	LoadTexture("Res/Game/Right/GameRightBg.png", TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightBgTex);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameScene()
{
	Character* tmp_player = g_Manager.GetCharacter(PLAYER);

	if (tmp_player == nullptr) {
		return;
	}

	//タイマーのアップデート
	TimerFunc()->Update(Timer::Id::Scene);
	TimerFunc()->Update(Timer::Id::Clear);

	SceneController()->GameEnd();

	g_Manager.Update();

	ObjManager()->Update();


	Vec2 EffectPos = { (960.f - CANDLE_EFFECT_SIZE.Width / 2),60.f };

	//キー入力でシーン遷移
	if (TimerFunc()->Get(Timer::Id::Scene) >= SCENE_WAIT) {

		switch (PepshiMan()->CurrentViewID()) {
		case GameData::SubGameScene::CENTER:
			if (GetKey(A_KEY) == true) {
				ObjManager()->Init(object::CANDLE_EFFECT, EffectPos);
				TimerFunc()->Init(Timer::Id::Scene);
				PepshiMan()->SetViewID(GameData::LEFT);
			}
			if (GetKey(D_KEY) == true) {
				ObjManager()->Init(object::CANDLE_EFFECT, EffectPos);
				TimerFunc()->Init(Timer::Id::Scene);
				PepshiMan()->SetViewID(GameData::RIGHT);
			}
			break;
		case GameData::RIGHT:
			if (GetKey(A_KEY) == true) {
				ObjManager()->Init(object::CANDLE_EFFECT, CANDLE_EFFECT_POS);
				TimerFunc()->Init(Timer::Id::Scene);
				PepshiMan()->SetViewID(GameData::CENTER);
			}
			break;
		case GameData::LEFT:
			if (GetKey(D_KEY) == true) {
				ObjManager()->Init(object::CANDLE_EFFECT, CANDLE_EFFECT_POS);
				TimerFunc()->Init(Timer::Id::Scene);
				PepshiMan()->SetViewID(GameData::CENTER);
			}
			break;
		}

		SceneController()->ChangeStep(SceneTransition::Id::Monitor, S_KEY);

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
//シーンのメイン処理ここまで

SceneId FinishGameScene()
{
	ReleaseCategoryTexture(TEXTURE_CATEGORY_GAME);

	if (SceneController()->IsGetID(SceneTransition::Id::Clear) == true) {
		SceneController()->SetID(SceneTransition::Id::Clear, false);
		return SceneId::ClearScene;
	}
	else if (SceneController()->IsGetID(SceneTransition::Id::Monitor) == true) {
		SceneController()->SetID(SceneTransition::Id::Monitor, false);
		return SceneId::MonitorScene;
	}
}

