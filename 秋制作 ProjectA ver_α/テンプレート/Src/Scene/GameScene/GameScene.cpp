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
#include "../../Object/Object.h"
#include "../../Object/UI/UIvalue.h"

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

//シーンのメイン処理
void DrawGameScene()
{
	Object* pCenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);
	Object* pLeftCandle = ObjManager()->GetObj(ObjID::CANDLE_LEFT);
	Object* pRightCandle = ObjManager()->GetObj(ObjID::CANDLE_RIGHT);

	Character* pPlayer = g_Manager.GetCharacter(PLAYER);
	Timer* pTimerInstance = Timer::GetInstance();


	switch (GameView()->CurrentViewID()) {
	case GameData::CENTER:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex));

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterDeskTex));

		g_Manager.Draw();

		if (pCenterCandle->HasCaLight() == false) {
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBlackTex));
		}

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFanceTex));

		ObjManager()->Draw();

		pTimerInstance->Draw();

		pPlayer->Draw();


		break;
	case GameData::RIGHT:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightBgTex));
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiFrontTex));
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiBackTex));
		
		//カーテン
		if (pRightCandle->HasCaLight() == false) {
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightBlackTex));
		}

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFanceTex));


		pTimerInstance->Draw();

		g_Manager.Draw();

		ObjManager()->Draw();


		break;
	case GameData::LEFT:
		DrawTexture(128.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex));
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiFrontTex));
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiBackTex));

		//カーテン
		if (pLeftCandle->HasCaLight() == false) {
			DrawTexture(128.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftBlackTex));
		}

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFanceTex));

		ObjManager()->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	}


	
}

void InitGameScene()
{

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init(Timer::Id::SCENE);

	ObjManager()->Init();


	g_Manager.LoadTex(GetCurrentSceneId());

	//ゲームシーン背景
	LoadTexture("Res/Game/Center/GameCenterBg.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex);
	LoadTexture("Res/Game/Left/GameLeftBg.png", TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex);
	LoadTexture("Res/Game/Right/GameRightBg.png", TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightBgTex);

	//センターシーン
	LoadTexture("Res/Game/Center/fence_black_texture.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFanceTex);
	LoadTexture("Res/Game/Center/all_black_texture.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFilterTex);
	LoadTexture("Res/Game/Center/desk.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterDeskTex);
	LoadTexture("Res/Game/Center/black_texture_center.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBlackTex);

	//右シーン
	LoadTexture("Res/Game/Right/right_shoji_front.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiFrontTex);
	LoadTexture("Res/Game/Right/right_shoji_back.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiBackTex);
	LoadTexture("Res/Game/Right/black_texture_right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightBlackTex);
	//左シーン
	LoadTexture("Res/Game/Left/left_shoji_front.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiFrontTex);
	LoadTexture("Res/Game/Left/left_shoji_back.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiBackTex);
	LoadTexture("Res/Game/Left/black_texture_left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftBlackTex);


	ChangeSceneStep(SceneStep::MainStep);
}

bool HasSceneChange(GameData::SubGameScene scene_) {
	switch (scene_)
	{
	case GameData::CENTER:
		if (GetKey(A_KEY) == true) {
			return true;
		}
		break;
	case GameData::LEFT:
		break;
	case GameData::RIGHT:
		break;
	default:
		break;
	}
}

void MainGameScene()
{
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (pPlayer == nullptr) {
		return;
	}

	//タイマーのアップデート

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Update();

	SceneController()->GameEnd();

	g_Manager.Update();

	ObjManager()->Update();


	//キー入力でシーン遷移
	if (pPlayer->ControlGameScene() == true) {
		SceneController()->SetID(SceneTransition::Id::Monitor, true);
		ChangeSceneStep(SceneStep::EndStep);
	}

	//クリア時間経過でシーン遷移
	if (pTimerInstance->GetClearTime() == CLEAR_TIME) {
			SceneController()->SetID(SceneTransition::Id::Clear, true);
			ChangeSceneStep(SceneStep::EndStep);
	}

	//プレイヤーの死亡でシーン遷移
	if (pPlayer->IsActive() == false) {

		SceneController()->SetID(SceneTransition::Id::Clear, true);
		ChangeSceneStep(SceneStep::EndStep);
	}

}
//シーンのメイン処理ここまで

SceneId FinishGameScene()
{
	//ReleaseCategoryTexture(TEXTURE_CATEGORY_GAME);

	if (SceneController()->IsGetID(SceneTransition::Id::Clear) == true) {
		SceneController()->SetID(SceneTransition::Id::Clear, false);
		return SceneId::ClearScene;
	}
	else if (SceneController()->IsGetID(SceneTransition::Id::Monitor) == true) {
		SceneController()->SetID(SceneTransition::Id::Monitor, false);
		return SceneId::MonitorScene;
	}
}

