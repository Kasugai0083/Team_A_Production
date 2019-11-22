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

	LoadTexture("Res/Game/Monitor/GameMonitorBg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownTex);
	LoadTexture("Res/Game/Monitor/Duct/LeftDuct.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctTex);
	LoadTexture("Res/Game/Monitor/Duct/RightDuct.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctTex);
}

void DrawMonitor() {


	if (MonitorFunc()->Get() == MonitorTransition::Id::Spown) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownTex));
	}
	else if (MonitorFunc()->Get() == MonitorTransition::Id::Left_Duct) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctTex));
	}
	else if (MonitorFunc()->Get() == MonitorTransition::Id::Right_Duct) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctTex));
	}

	//マップ
	ObjManager()->DrawUI(MONITOR_MAP);
	//水晶
	ObjManager()->DrawUI(BUTTON_WORKSHOP);
	ObjManager()->DrawUI(BUTTON_STORE_ROOM);
	ObjManager()->DrawUI(BUTTON_RECEPTION_ROOM);
	ObjManager()->DrawUI(BUTTON_CHILD_ROOM);
	ObjManager()->DrawUI(BUTTON_RIGHT_CORRIDOR);
	ObjManager()->DrawUI(BUTTON_LEFT_CORRIDOR);

	DrawTexture(PLAYER_ROOM_UI_POS.X, PLAYER_ROOM_UI_POS.Y, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPlayerRoomUITex));

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
	DrawMonitor();

	g_Manager.Draw();

}

void InitMonitorScene()
{

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init(Timer::Id::SCENE);

	ObjManager()->Init();

	LoadMonitor();

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

	ObjManager()->UpdateUI(BUTTON_WORKSHOP);
	ObjManager()->UpdateUI(BUTTON_STORE_ROOM);
	ObjManager()->UpdateUI(BUTTON_RECEPTION_ROOM);
	ObjManager()->UpdateUI(BUTTON_CHILD_ROOM);
	ObjManager()->UpdateUI(BUTTON_RIGHT_CORRIDOR);
	ObjManager()->UpdateUI(BUTTON_LEFT_CORRIDOR);

	//タイマーのアップデート

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Update();

	SceneController()->GameEnd();

	g_Manager.Update();


	//キー入力でシーン遷移
	if (pTimerInstance->GetTime(Timer::Id::SCENE) >= SCENE_WAIT) {

		if (ObjManager()->HasOnMouseUI(BUTTON_WORKSHOP) == true) {
			if (OnMouseDown(Left) == true) {
				MonitorFunc()->Set(MonitorTransition::Id::Spown);
				pTimerInstance->Init(Timer::Id::SCENE);
			}
		}
		if (ObjManager()->HasOnMouseUI(BUTTON_LEFT_CORRIDOR) == true) {
			if (OnMouseDown(Left) == true) {
				MonitorFunc()->Set(MonitorTransition::Id::Left_Duct);
				pTimerInstance->Init(Timer::Id::SCENE);
			}
		}
		if (ObjManager()->HasOnMouseUI(BUTTON_RIGHT_CORRIDOR) == true) {
			if (OnMouseDown(Left) == true) {
				MonitorFunc()->Set(MonitorTransition::Id::Right_Duct);
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

