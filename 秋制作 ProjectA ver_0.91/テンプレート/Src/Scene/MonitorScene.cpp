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

//UI* UIFunc(UI::Id id, bool OnBlack = false) {
//	static Object obj[UI::Id::MaxNum];
//
//	for (int i = 0; i < UI::Id::MaxNum; i++) {
//		obj[i] = new UI;
//	}
//
//	ui[id].Init(id, OnBlack);
//
//	return &ui[id];
//}

void LoadMonitor() {

	UIManager()->Init();

	LoadTexture("Res/Game/Monitor/GameMonitorBg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownTex);
	LoadTexture("Res/Game/Monitor/Duct/LeftDuct.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctTex);
	LoadTexture("Res/Game/Monitor/Duct/RightDuct.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctTex);
	//
	//LoadTexture("Res/Game/Monitor/MonitorUI/SpownUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownUITex);
	//LoadTexture("Res/Game/Monitor/MonitorUI/LeftDuctUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctUITex);
	//LoadTexture("Res/Game/Monitor/MonitorUI/RightDuctUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctUITex);
	//
	//LoadTexture("Res/Game/Monitor/MonitorUI/OnSpownUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnSpownUITex);
	//LoadTexture("Res/Game/Monitor/MonitorUI/OnLeftDuctUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnLeftDuctUITex);
	//LoadTexture("Res/Game/Monitor/MonitorUI/OnRightDuctUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnRightDuctUITex);

	//LoadTexture("Res/Game/Monitor/MonitorUI/PlayerRoomUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPlayerRoomUITex);
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

	switch (MonitorFunc()->Get()) {
	case MonitorTransition::Id::Spown:
		//スポーン黒、左ダクト白、右ダクト白
		UIManager()->Draw(object::BLACK_MONITOR_SPOWN);
		UIManager()->Draw(object::RIGHT_DUCT);
		UIManager()->Draw(object::LEFT_DUCT);

		//UIFunc(UI::Id::MonitorSpown, true)->Draw(false);
		//UIFunc(UI::Id::RightDuct)->Draw();
		//UIFunc(UI::Id::LeftDuct)->Draw();
		break;
	case MonitorTransition::Id::Left_Duct:
		//スポーン白、左ダクト黒、右ダクト白
		UIManager()->Draw(object::MONITOR_SPOWN);
		UIManager()->Draw(object::RIGHT_DUCT);
		UIManager()->Draw(object::BLACK_LEFT_DUCT);

		//UIFunc(UI::Id::MonitorSpown)->Draw();
		//UIFunc(UI::Id::RightDuct)->Draw();
		//UIFunc(UI::Id::LeftDuct, true)->Draw(false);
		break;
	case MonitorTransition::Id::Right_Duct:
		//スポーン白、左ダクト白、右ダクト黒
		UIManager()->Draw(object::MONITOR_SPOWN);
		UIManager()->Draw(object::BLACK_RIGHT_DUCT);
		UIManager()->Draw(object::LEFT_DUCT);

		//UIFunc(UI::Id::MonitorSpown)->Draw();
		//UIFunc(UI::Id::RightDuct, true)->Draw(false);
		//UIFunc(UI::Id::LeftDuct)->Draw();
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
	TimerFunc()->Set(0, Timer::Id::Scene);

	LoadMonitor();

	g_Manager.LoadTex(GetCurrentSceneId());

	ChangeSceneStep(SceneStep::MainStep);
}

void MainMonitorScene()
{

	UIManager()->Update();

	//UIFunc(UI::Id::MonitorSpown)->Update();
	//UIFunc(UI::Id::RightDuct)->Update();
	//UIFunc(UI::Id::LeftDuct)->Update();

	TimerFunc()->Update(Timer::Id::Scene);
	TimerFunc()->Update(Timer::Id::MusicBox);

	TransButton()->GameEnd();

	g_Manager.Update();


		
	if (TimerFunc()->Get(Timer::Id::Scene) >= SCENE_WAIT) {

		if (UIManager()->HasOnMouse(object::MONITOR_SPOWN) == true) {
			if (OnMouseDown(Left) == true) {
				MonitorFunc()->Set(MonitorTransition::Id::Spown);
				TimerFunc()->Set(0, Timer::Id::Scene);
			}
		}
		if (UIManager()->HasOnMouse(object::LEFT_DUCT) == true) {
			if (OnMouseDown(Left) == true) {
				MonitorFunc()->Set(MonitorTransition::Id::Left_Duct);
				TimerFunc()->Set(0, Timer::Id::Scene);
			}
		}
		if (UIManager()->HasOnMouse(object::RIGHT_DUCT) == true) {
			if (OnMouseDown(Left) == true) {
				MonitorFunc()->Set(MonitorTransition::Id::Right_Duct);
				TimerFunc()->Set(0, Timer::Id::Scene);
			}
		}
		/*		if (UIFunc(UI::Id::MonitorSpown)->HasOnMouse() == true) {
			if (OnMouseDown(Left) == true) {
				MonitorFunc()->Set(MonitorTransition::Id::Spown);
				TimerFunc()->Set(0, Timer::Id::Scene);
			}
		}
		if (UIFunc(UI::Id::LeftDuct)->HasOnMouse() == true) {
			if (OnMouseDown(Left) == true) {
				MonitorFunc()->Set(MonitorTransition::Id::Left_Duct);
				TimerFunc()->Set(0, Timer::Id::Scene);
			}
		}
		if (UIFunc(UI::Id::RightDuct)->HasOnMouse() == true) {
			if (OnMouseDown(Left) == true) {
				MonitorFunc()->Set(MonitorTransition::Id::Right_Duct);
				TimerFunc()->Set(0, Timer::Id::Scene);
			}
		}
*/

		if (GetKey(W_KEY) == true) {
			TransButton()->Change(SceneTransition::Id::Center, true);
			ChangeSceneStep(SceneStep::EndStep);
		}
	}
}

SceneId FinishMonitorScene()
{
	ReleaseCategoryTexture(TEXTURE_CATEGORY_MONITOR);

	if (TransButton()->Research(SceneTransition::Id::Center) == true) {
		TransButton()->Change(SceneTransition::Id::Center, false);
		return SceneId::CenterScene;
	}
}

