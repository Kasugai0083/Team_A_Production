#include <stdio.h>
#include "../Scene/Scene.h"
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
void InitCenterScene();
// ゲーム本編シーンのメイン処理
void MainCenterScene();
// ゲーム本編シーンの終了
SceneId FinishCenterScene();

#pragma region シーン中に使用する関数群

const float MusicBox_X1 = 1140.0f;
const float MusicBox_X2 = 1300.0f;
const float MusicBox_Y1 = 920.0f;
const float MusicBox_Y2 = 1080.0f;

void MusicBoxHit() {

	bool CountDown = false;

	if (RectangleHit(GetMousePos().X, GetMousePos().Y, MusicBox_X1, MusicBox_Y1, MusicBox_X2, MusicBox_Y2) == true) {
		if (OnMousePush(Left) == true) {
			TimerFunc()->CountDown(Timer::Id::MusicBox);
			CountDown = true;
		}
		else { CountDown = false; }
	}
	else { CountDown = false; }

	if (CountDown == false) {
		TimerFunc()->Update(Timer::Id::MusicBox);
	}
}

void LoadCircle() {
	LoadTexture("Res/Game/Center/Circle/Circle1.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle1Tex);
	LoadTexture("Res/Game/Center/Circle/Circle2.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle2Tex);
	LoadTexture("Res/Game/Center/Circle/Circle3.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle3Tex);
	LoadTexture("Res/Game/Center/Circle/Circle4.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle4Tex);
	LoadTexture("Res/Game/Center/Circle/Circle5.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle5Tex);
	LoadTexture("Res/Game/Center/Circle/Circle6.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle6Tex);
	LoadTexture("Res/Game/Center/Circle/Circle7.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle7Tex);
	LoadTexture("Res/Game/Center/Circle/Circle8.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle8Tex);

}

const float MB_Pos_Adjustment_X = 50.0f;
const float MB_Pos_Adjustment_Y = 100.0f;

void DrawCircle() {

	if (TimerFunc()->Get(Timer::Id::MusicBox) <= 100) {
		DrawTexture((MusicBox_X1 + MB_Pos_Adjustment_X), (MusicBox_Y1 - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle1Tex));
	}else if (TimerFunc()->Get(Timer::Id::MusicBox) <= 200) {
		DrawTexture((MusicBox_X1 + MB_Pos_Adjustment_X), (MusicBox_Y1 - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle2Tex));
	}else if (TimerFunc()->Get(Timer::Id::MusicBox) <= 300) {
		DrawTexture((MusicBox_X1 + MB_Pos_Adjustment_X), (MusicBox_Y1 - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle3Tex));
	}else if (TimerFunc()->Get(Timer::Id::MusicBox) <= 400) {
		DrawTexture((MusicBox_X1 + MB_Pos_Adjustment_X), (MusicBox_Y1 - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle4Tex));
	}else if (TimerFunc()->Get(Timer::Id::MusicBox) <= 500) {
		DrawTexture((MusicBox_X1 + MB_Pos_Adjustment_X), (MusicBox_Y1 - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle5Tex));
	}else if (TimerFunc()->Get(Timer::Id::MusicBox) <= 600) {
		DrawTexture((MusicBox_X1 + MB_Pos_Adjustment_X), (MusicBox_Y1 - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle6Tex));
	}else if (TimerFunc()->Get(Timer::Id::MusicBox) <= 700) {
		DrawTexture((MusicBox_X1 + MB_Pos_Adjustment_X), (MusicBox_Y1 - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle7Tex));
	}else if (TimerFunc()->Get(Timer::Id::MusicBox) <= 800) {
		DrawTexture((MusicBox_X1 + MB_Pos_Adjustment_X), (MusicBox_Y1 - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle8Tex));
	}else if (TimerFunc()->Get(Timer::Id::MusicBox) <= 900) {
	}

}

//ここまで
#pragma endregion

//シーン遷移
SceneId UpdateCenterScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitCenterScene();
		break;
	case SceneStep::MainStep:
		MainCenterScene();
		break;
	case SceneStep::EndStep:
		return FinishCenterScene();
		break;
	}

	return SceneId::CenterScene;
}

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

//シーンのメイン処理
void DrawCenterScene()
{

	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex));

	DrawCenterItem();

	DrawCircle();
	g_Manager.Draw();

}

void InitCenterScene()
{
	TimerFunc()->Set(0 ,Timer::Id::Scene);

	ObjManager()->Init();

	LoadCircle();

	g_Manager.LoadTex(GetCurrentSceneId());

	LoadTexture("Res/Game/Center/GameCenterBg.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainCenterScene()
{
	Character* tmp_player = g_Manager.GetCharacter(PLAYER);

	MusicBoxHit();

	TimerFunc()->Update(Timer::Id::Scene);
	TimerFunc()->Update(Timer::Id::Clear);

	TransButton()->GameEnd();
	
	g_Manager.Update();
	ObjManager()->Update();

	if (TimerFunc()->Get(Timer::Id::Scene) >= SCENE_WAIT) {
		
		//フラグを立ててEndStepに移行
		TransButton()->ChangeStep(SceneTransition::Id::Left, A_KEY);
		TransButton()->ChangeStep(SceneTransition::Id::Right, D_KEY);
		TransButton()->ChangeStep(SceneTransition::Id::Monitor, S_KEY);

	}
	if (TimerFunc()->Get(Timer::Id::Clear) >= CLEAR_TIME) {
		if(tmp_player->GetIsDeath() == false){
			TransButton()->Change(SceneTransition::Id::Clear, true);
			ChangeSceneStep(SceneStep::EndStep);
		}
	}
	if (tmp_player->GetIsDeath() == true) {
		TransButton()->Change(SceneTransition::Id::Clear, true);
		ChangeSceneStep(SceneStep::EndStep);
	}

}
//シーンのメイン処理ここまで

SceneId FinishCenterScene()
{
	ReleaseCategoryTexture(TEXTURE_CATEGORY_CENTER);

	if (TransButton()->Research(SceneTransition::Id::Clear) == true) {
		TransButton()->Change(SceneTransition::Id::Clear, false);
		return SceneId::ClearScene;
	}	
	else if (TransButton()->Research(SceneTransition::Id::Left) == true) {
		TransButton()->Change(SceneTransition::Id::Left, false);
		return SceneId::LeftScene;
	}
	else if (TransButton()->Research(SceneTransition::Id::Right) == true) {
		TransButton()->Change(SceneTransition::Id::Right, false);
		return SceneId::RightScene;
	}
	else if (TransButton()->Research(SceneTransition::Id::Monitor) == true) {
		TransButton()->Change(SceneTransition::Id::Monitor, false);
		return SceneId::MonitorScene;
	}
}

