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


Candller* CreateCandller() {
	static Candller CandInstance = { true, false, true };
	return &CandInstance;
}

#pragma region 描画関数

namespace Draw {

	void DrawCenterItem() {
		
		Candller* CandllerInstance = CreateCandller();

		//キャンドル
		if (CandllerInstance->CenterCaLight == true) {
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

		Candller* CandllerInstance = CreateCandller();

		if (CandllerInstance->LeftCaLight == true) {
			ObjManager()->Draw(object::FIRE_BIG);
			ObjManager()->Draw(object::CANDLE_EFFECT);
		}
		ObjManager()->Draw(object::CANDLE_BIG);
		ObjManager()->Draw(object::CANDLE_STAND);

	}

	void DrawRightItem() {

		Candller* CandllerInstance = CreateCandller();

		if (CandllerInstance->RightCaLight == true) {
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
		DrawTexture(760.0f, 540.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::EnemyBoonieTex), 356.f, 356.f);

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiFrontTex));
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiBackTex));

		break;
	case GameData::LEFT:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex));
		Draw::DrawLeftItem();
		DrawTexture(760.0f, 540.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFreeTex), 300.f, 300.f);

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiFrontTex));
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiBackTex));

		break;
	}
	g_Manager.Draw();



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

	Vec2 CandlePos = { 9999.f ,9999.f };
	ObjManager()->Init(object::CANDLE_BIG, CandlePos);

	g_Manager.LoadTex(GetCurrentSceneId());

	LoadTexture("Res/Game/Center/GameCenterBg.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex);
	LoadTexture("Res/Game/Left/GameLeftBg.png", TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex);
	LoadTexture("Res/Game/Right/GameRightBg.png", TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightBgTex);

	LoadTexture("Res/Game/Enemy/Bonnie.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::EnemyBoonieTex);
	
	LoadTexture("Res/Game/Right/right_shoji_front.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiFrontTex);
	LoadTexture("Res/Game/Right/right_shoji_back.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiBackTex);
	LoadTexture("Res/Game/Left/left_shoji_front.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiFrontTex);
	LoadTexture("Res/Game/Left/left_shoji_back.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiBackTex);



	ChangeSceneStep(SceneStep::MainStep);
}



void MainGameScene()
{
	int count = 0;
	Candller* CandllerInstance = CreateCandller();

	ObjManager()->SetCandller(CandllerInstance);
	ObjManager()->SetCount(&count);

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
	Vec2 CandlePos = { 9999.f ,9999.f };


	//キー入力でシーン遷移
	if (pTimerInstance->GetTime(Timer::Id::SCENE) >= SCENE_WAIT) {

		switch (PepshiMan()->CurrentViewID()) {
		case GameData::SubGameScene::CENTER:
			if (GetKey(A_KEY) == true) {
				ObjManager()->Init(object::CANDLE_EFFECT, EffectPos);

				ObjManager()->Init(object::CANDLE_SMALL, CandlePos);
				ObjManager()->Init(object::CANDLE_BIG, CANDLE_BIG_POS);

				pTimerInstance->Init(Timer::Id::SCENE);
				PepshiMan()->SetViewID(GameData::LEFT);
			}
			if (GetKey(D_KEY) == true) {
				ObjManager()->Init(object::CANDLE_EFFECT, EffectPos);

				ObjManager()->Init(object::CANDLE_SMALL, CandlePos);
				ObjManager()->Init(object::CANDLE_BIG, CANDLE_BIG_POS);

				pTimerInstance->Init(Timer::Id::SCENE);
				PepshiMan()->SetViewID(GameData::RIGHT);
			}
			break;
		case GameData::RIGHT:
			if (GetKey(A_KEY) == true) {
				ObjManager()->Init(object::CANDLE_EFFECT, CANDLE_EFFECT_POS);

				ObjManager()->Init(object::CANDLE_SMALL, CANDLE_SMALL_POS);
				ObjManager()->Init(object::CANDLE_BIG, CandlePos);

				pTimerInstance->Init(Timer::Id::SCENE);
				PepshiMan()->SetViewID(GameData::CENTER);
			}
			break;
		case GameData::LEFT:
			if (GetKey(D_KEY) == true) {
				ObjManager()->Init(object::CANDLE_EFFECT, CANDLE_EFFECT_POS);

				ObjManager()->Init(object::CANDLE_SMALL, CANDLE_SMALL_POS);
				ObjManager()->Init(object::CANDLE_BIG, CandlePos);

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

