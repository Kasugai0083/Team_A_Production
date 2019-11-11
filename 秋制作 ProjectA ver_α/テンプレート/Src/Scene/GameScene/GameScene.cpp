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
static Candller CandllerInstance = {true, true, true};

namespace Draw {

	

	void DrawCenterItem() {
		ObjManager()->SetCandller(CandllerInstance);

		//キャンドル
		if (CandllerInstance.CenterCaLight == true) {
			ObjManager()->Draw(object::FIRE_SMALL);
			ObjManager()->Draw(object::CANDLE_EFFECT);
		}

		ObjManager()->Draw(object::CANDLE_SMALL);
		ObjManager()->Draw(object::CANDLE_STAND);

		//プレイヤーのアイテム
		ObjManager()->Draw(object::CRYSTAL);
		ObjManager()->Draw(object::MUSICBOX);

	}

	void DrawLeftItem() {
		ObjManager()->SetCandller(CandllerInstance);

		if (CandllerInstance.LeftCaLight == true) {
			ObjManager()->Draw(object::FIRE_BIG);
			ObjManager()->Draw(object::CANDLE_EFFECT);
		}
		ObjManager()->Draw(object::CANDLE_BIG);
		ObjManager()->Draw(object::CANDLE_STAND);

	}

	void DrawRightItem() {
		ObjManager()->SetCandller(CandllerInstance);

		if (CandllerInstance.RightCaLight == true) {
			ObjManager()->Draw(object::FIRE_BIG);
			ObjManager()->Draw(object::CANDLE_EFFECT);
		}
		ObjManager()->Draw(object::CANDLE_BIG);
		ObjManager()->Draw(object::CANDLE_STAND);

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

	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFreeTex), 100.f, 100.f);

}

void InitGameScene()
{

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init(Timer::Id::SCENE);

	ObjManager()->Init();

	Vec2 EffectPos = { (960.f - CANDLE_EFFECT_SIZE.Width / 2),60.f };
	switch (PepshiMan()->CurrentViewID()) {
	case GameData::RIGHT:
		ObjManager()->Init(object::CANDLE_EFFECT,EffectPos);
		break;
	case GameData::LEFT:
		ObjManager()->Init(object::CANDLE_EFFECT, EffectPos);
		break;
	}


	g_Manager.LoadTex(GetCurrentSceneId());

	LoadTexture("Res/Game/Center/GameCenterBg.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex);
	LoadTexture("Res/Game/Left/GameLeftBg.png", TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex);
	LoadTexture("Res/Game/Right/GameRightBg.png", TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightBgTex);
	LoadTexture("Res/Game/Enemy/Bonnie.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFreeTex);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainGameScene()
{
	ObjManager()->SetCandller(CandllerInstance);

	Character* tmp_player = g_Manager.GetCharacter(PLAYER);

	if (tmp_player == nullptr) {
		return;
	}

	//タイマーのアップデート

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Update();

	SceneController()->GameEnd();

	g_Manager.Update();

	ObjManager()->Update();


	Vec2 EffectPos = { (960.f - CANDLE_EFFECT_SIZE.Width / 2),60.f };

	//キー入力でシーン遷移
	if (pTimerInstance->GetTime(Timer::Id::SCENE) >= SCENE_WAIT) {

		switch (PepshiMan()->CurrentViewID()) {
		case GameData::SubGameScene::CENTER:
			if (GetKey(A_KEY) == true) {
				ObjManager()->Init(object::CANDLE_EFFECT, EffectPos);
				pTimerInstance->Init(Timer::Id::SCENE);
				PepshiMan()->SetViewID(GameData::LEFT);
			}
			if (GetKey(D_KEY) == true) {
				ObjManager()->Init(object::CANDLE_EFFECT, EffectPos);
				pTimerInstance->Init(Timer::Id::SCENE);
				PepshiMan()->SetViewID(GameData::RIGHT);
			}
			break;
		case GameData::RIGHT:
			if (GetKey(A_KEY) == true) {
				ObjManager()->Init(object::CANDLE_EFFECT, CANDLE_EFFECT_POS);
				pTimerInstance->Init(Timer::Id::SCENE);
				PepshiMan()->SetViewID(GameData::CENTER);
			}
			break;
		case GameData::LEFT:
			if (GetKey(D_KEY) == true) {
				ObjManager()->Init(object::CANDLE_EFFECT, CANDLE_EFFECT_POS);
				pTimerInstance->Init(Timer::Id::SCENE);
				PepshiMan()->SetViewID(GameData::CENTER);
			}
			break;
		}

		SceneController()->ChangeStep(SceneTransition::Id::Monitor, S_KEY);

	}

	//クリア時間経過でシーン遷移
	if (pTimerInstance->GetTime(Timer::Id::CLEAR) >= CLEAR_TIME) {
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

