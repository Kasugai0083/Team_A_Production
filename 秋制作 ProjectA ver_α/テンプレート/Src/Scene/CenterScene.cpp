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
#include "../Object/ObjectID.h"

// ゲーム本編シーンの初期化
void InitCenterScene();
// ゲーム本編シーンのメイン処理
void MainCenterScene();
// ゲーム本編シーンの終了
SceneId FinishCenterScene();

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

	g_Manager.Draw();

}

void InitCenterScene()
{
	TimerFunc()->Set(0 ,Timer::Id::Scene);

	ObjManager()->Init();

	g_Manager.LoadTex(GetCurrentSceneId());

	LoadTexture("Res/Game/Center/GameCenterBg.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainCenterScene()
{
	Character* tmp_player = g_Manager.GetCharacter(PLAYER);

	TimerFunc()->Update(Timer::Id::Scene);
	TimerFunc()->Update(Timer::Id::Clear);

	TransButton()->GameEnd();
	
	g_Manager.Update();

	ObjManager()->Update(object::CANDLE_STAND);
	ObjManager()->Update(object::MUSICBOX);

	if (TimerFunc()->Get(Timer::Id::Scene) >= SCENE_WAIT) {
		
		//フラグを立ててEndStepに移行
		TransButton()->ChangeStep(SceneTransition::Id::Left, A_KEY);
		TransButton()->ChangeStep(SceneTransition::Id::Right, D_KEY);
		TransButton()->ChangeStep(SceneTransition::Id::Monitor, S_KEY);

	}
	if (TimerFunc()->Get(Timer::Id::Clear) >= CLEAR_TIME) {
		if(tmp_player->IsDeath() == false){
			TransButton()->Change(SceneTransition::Id::Clear, true);
			ChangeSceneStep(SceneStep::EndStep);
		}
	}
	if (tmp_player->IsDeath() == true) {
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

