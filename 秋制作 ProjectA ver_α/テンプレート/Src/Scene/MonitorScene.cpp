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
#include "../Object/UI/UIvalue.h"


// ゲーム本編シーンの初期化
void InitMonitorScene();
// ゲーム本編シーンのメイン処理
void MainMonitorScene();
// ゲーム本編シーンの終了
SceneId FinishMonitorScene();


#pragma region モニターの描画関数

void LoadMonitor() {

	ObjManager()->Init();

	LoadTexture("Res/Game/Monitor/GameMonitorBg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownBgTex);
	LoadTexture("Res/Game/Monitor/Duct/LeftDuct.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctBgTex);
	LoadTexture("Res/Game/Monitor/Duct/RightDuct.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctBgTex);
	LoadTexture("Res/Game/Monitor/child_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChildRoomBgTex);
	LoadTexture("Res/Game/Monitor/resption_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorResptionRoomBgTex);
	LoadTexture("Res/Game/Monitor/store_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex);

}

void DrawBg() {
	if (GameView()->CurrentMonitorID() == MonitorView::WORKSHOP_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownBgTex));
	}
	else if (GameView()->CurrentMonitorID() == MonitorView::LEFT_CORRIDOR_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctBgTex));
	}
	else if (GameView()->CurrentMonitorID() == MonitorView::RIGHT_CORRIDOR_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctBgTex));
	}
	else if (GameView()->CurrentMonitorID() == MonitorView::STORE_ROOM_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex));
	}
	else if (GameView()->CurrentMonitorID() == MonitorView::RECEPTION_ROOM_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorResptionRoomBgTex));
	}
	else if (GameView()->CurrentMonitorID() == MonitorView::CHILD_ROOM_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChildRoomBgTex));
	}

	DrawFont(100.f, 900.f, "Space で 戻る",Large, White);

}

void DrawUI() {

	//マップ
	ObjManager()->DrawUI(MONITOR_MAP);
	//水晶
	ObjManager()->DrawUI(BUTTON_WORKSHOP);
	ObjManager()->DrawUI(BUTTON_STORE_ROOM);
	ObjManager()->DrawUI(BUTTON_RECEPTION_ROOM);
	ObjManager()->DrawUI(BUTTON_CHILD_ROOM);
	ObjManager()->DrawUI(BUTTON_RIGHT_CORRIDOR);
	ObjManager()->DrawUI(BUTTON_LEFT_CORRIDOR);

	switch (GameView()->CurrentMonitorID()) {
	case MonitorView::WORKSHOP_VIEW:
		ObjManager()->DrawUI(BUTTON_ON_WORKSHOP);
		break;
	case MonitorView::STORE_ROOM_VIEW:
		ObjManager()->DrawUI(BUTTON_ON_STORE_ROOM);
		break;
	case MonitorView::RECEPTION_ROOM_VIEW:
		ObjManager()->DrawUI(BUTTON_ON_RECEPTION_ROOM);
		break;
	case MonitorView::CHILD_ROOM_VIEW:
		ObjManager()->DrawUI(BUTTON_ON_CHILD_ROOM);
		break;
	case MonitorView::RIGHT_CORRIDOR_VIEW:
		ObjManager()->DrawUI(BUTTON_ON_RIGHT_CORRIDOR);
		break;
	case MonitorView::LEFT_CORRIDOR_VIEW:
		ObjManager()->DrawUI(BUTTON_ON_LEFT_CORRIDOR);
		break;

	}

}
#pragma endregion

SceneId UpdateMonitorScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitMonitorScene();
		break;
	case SceneStep::MainStep:
		MainMonitorScene();
		break;
	case SceneStep::EndStep:
		return FinishMonitorScene();
		break;
	}

	return SceneId::MonitorScene;
}

void DrawMonitorScene()
{	
	DrawBg();

	g_Manager.Draw();///ここが原因

	ObjManager()->DrawUI();

	//DrawUI();

}

void InitMonitorScene()
{

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init(Timer::Id::SCENE);

	LoadMonitor();

	ObjManager()->Init();

	ObjManager()->InitUI();

	g_Manager.LoadTex(GetCurrentSceneId());

	ChangeSceneStep(SceneStep::MainStep);
}

void MainMonitorScene()
{
	Character* tmp_player = g_Manager.GetCharacter(PLAYER);

	if (tmp_player == nullptr) {
		return;
	}

	//UIのアップデート

	ObjManager()->Update();

	//ObjManager()->UpdateUI(BUTTON_WORKSHOP);
	//ObjManager()->UpdateUI(BUTTON_STORE_ROOM);
	//ObjManager()->UpdateUI(BUTTON_RECEPTION_ROOM);
	//ObjManager()->UpdateUI(BUTTON_CHILD_ROOM);
	//ObjManager()->UpdateUI(BUTTON_RIGHT_CORRIDOR);
	//ObjManager()->UpdateUI(BUTTON_LEFT_CORRIDOR);

	//タイマーのアップデート

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Update();

	SceneController()->GameEnd();

	g_Manager.Update();


	//キー入力でシーン遷移
	if (pTimerInstance->GetTime(Timer::Id::SCENE) >= SCENE_WAIT) {

		if (ObjManager()->HasOnMouseUI(BUTTON_WORKSHOP) == true) {
			if (OnMouseDown(Left) == true) {
				GameView()->SetMonitorID(MonitorView::WORKSHOP_VIEW);
				pTimerInstance->Init(Timer::Id::SCENE);
			}
		}
		if (ObjManager()->HasOnMouseUI(BUTTON_LEFT_CORRIDOR) == true) {
			if (OnMouseDown(Left) == true) {
				GameView()->SetMonitorID(MonitorView::LEFT_CORRIDOR_VIEW);
				pTimerInstance->Init(Timer::Id::SCENE);

			}
		}
		if (ObjManager()->HasOnMouseUI(BUTTON_RIGHT_CORRIDOR) == true) {
			if (OnMouseDown(Left) == true) {
				GameView()->SetMonitorID(MonitorView::RIGHT_CORRIDOR_VIEW);
				pTimerInstance->Init(Timer::Id::SCENE);

			}
		}
		if (ObjManager()->HasOnMouseUI(BUTTON_STORE_ROOM) == true) {
			if (OnMouseDown(Left) == true) {
				GameView()->SetMonitorID(MonitorView::STORE_ROOM_VIEW);
				pTimerInstance->Init(Timer::Id::SCENE);

			}
		}
		if (ObjManager()->HasOnMouseUI(BUTTON_RECEPTION_ROOM) == true) {
			if (OnMouseDown(Left) == true) {
				GameView()->SetMonitorID(MonitorView::RECEPTION_ROOM_VIEW);
				pTimerInstance->Init(Timer::Id::SCENE);

			}
		}
		if (ObjManager()->HasOnMouseUI(BUTTON_CHILD_ROOM) == true) {
			if (OnMouseDown(Left) == true) {
				GameView()->SetMonitorID(MonitorView::CHILD_ROOM_VIEW);
				pTimerInstance->Init(Timer::Id::SCENE);

			}
		}

		if (GetKey(W_KEY) == true) {
			SceneController()->SetID(SceneTransition::Id::Game, true);
			ChangeSceneStep(SceneStep::EndStep);
		}
	}

	//クリア時間経過でシーン遷移
	if (pTimerInstance->GetTime(Timer::Id::CLEAR) >= CLEAR_TIME) {
		if (tmp_player->IsActive() == false) {
			SceneController()->SetID(SceneTransition::Id::Clear, true);
			ChangeSceneStep(SceneStep::EndStep);
		}
	}

	//プレイヤーの死亡でシーン遷移
	if (tmp_player->IsActive() == true) {
		SceneController()->SetID(SceneTransition::Id::Clear, true);
		ChangeSceneStep(SceneStep::EndStep);
	}

}

SceneId FinishMonitorScene()
{
	//ReleaseCategoryTexture(TEXTURE_CATEGORY_MONITOR);

	//ObjManager()->Release();

	if (SceneController()->IsGetID(SceneTransition::Id::Clear) == true) {
		SceneController()->SetID(SceneTransition::Id::Clear, false);
		return SceneId::ClearScene;
	}
	else if (SceneController()->IsGetID(SceneTransition::Id::Game) == true) {
		SceneController()->SetID(SceneTransition::Id::Game, false);
		return SceneId::GameScene;
	}
}

