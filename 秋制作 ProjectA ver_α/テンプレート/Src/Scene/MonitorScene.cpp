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
	DrawTexture(1200.f, 400.f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorMapTex));
	//水晶
	DrawTexture(1600.f, 430.f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom1Tex));
	DrawTexture(1375.f, 550.f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom2Tex));
	DrawTexture(1600.f, 550.f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom3Tex));
	DrawTexture(1825.f, 550.f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom4Tex));
	DrawTexture(1375.f, 700.f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom5Tex));
	DrawTexture(1720.f, 700.f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom6Tex));


	switch (MonitorFunc()->Get()) {
	case MonitorTransition::Id::Spown:
		//スポーン黒、左ダクト白、右ダクト白
		ObjManager()->Draw(object::BLACK_MONITOR_SPOWN);
		ObjManager()->Draw(object::RIGHT_DUCT);
		ObjManager()->Draw(object::LEFT_DUCT);
		break;
	case MonitorTransition::Id::Left_Duct:
		//スポーン白、左ダクト黒、右ダクト白
		ObjManager()->Draw(object::MONITOR_SPOWN);
		ObjManager()->Draw(object::RIGHT_DUCT);
		ObjManager()->Draw(object::BLACK_LEFT_DUCT);
		break;
	case MonitorTransition::Id::Right_Duct:
		//スポーン白、左ダクト白、右ダクト黒
		ObjManager()->Draw(object::MONITOR_SPOWN);
		ObjManager()->Draw(object::BLACK_RIGHT_DUCT);
		ObjManager()->Draw(object::LEFT_DUCT);
		break;
	default:
		break;
	}

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

	LoadTexture("Res/Game/Monitor/MonitorUI/button_1.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom1Tex);
	LoadTexture("Res/Game/Monitor/MonitorUI/button_2.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom2Tex);
	LoadTexture("Res/Game/Monitor/MonitorUI/button_3.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom3Tex);
	LoadTexture("Res/Game/Monitor/MonitorUI/button_4.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom4Tex);
	LoadTexture("Res/Game/Monitor/MonitorUI/button_5.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom5Tex);
	LoadTexture("Res/Game/Monitor/MonitorUI/button_6.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom6Tex);

	LoadTexture("Res/Game/Monitor/MonitorUI/map.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorMapTex);

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
	ObjManager()->Update(object::MONITOR_SPOWN);
	ObjManager()->Update(object::LEFT_DUCT);
	ObjManager()->Update(object::RIGHT_DUCT);

	//タイマーのアップデート

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Update();

	SceneController()->GameEnd();

	g_Manager.Update();


	//キー入力でシーン遷移
	if (pTimerInstance->GetTime(Timer::Id::SCENE) >= SCENE_WAIT) {

		if (ObjManager()->HasOnMouse(object::MONITOR_SPOWN) == true) {
			if (OnMouseDown(Left) == true) {
				MonitorFunc()->Set(MonitorTransition::Id::Spown);
				pTimerInstance->Init(Timer::Id::SCENE);
			}
		}
		if (ObjManager()->HasOnMouse(object::LEFT_DUCT) == true) {
			if (OnMouseDown(Left) == true) {
				MonitorFunc()->Set(MonitorTransition::Id::Left_Duct);
				pTimerInstance->Init(Timer::Id::SCENE);
			}
		}
		if (ObjManager()->HasOnMouse(object::RIGHT_DUCT) == true) {
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
	ReleaseCategoryTexture(TEXTURE_CATEGORY_MONITOR);

	if (SceneController()->IsGetID(SceneTransition::Id::Clear) == true) {
		SceneController()->SetID(SceneTransition::Id::Clear, false);
		return SceneId::ClearScene;
	}
	else if (SceneController()->IsGetID(SceneTransition::Id::Game) == true) {
		SceneController()->SetID(SceneTransition::Id::Game, false);
		return SceneId::GameScene;
	}
}

