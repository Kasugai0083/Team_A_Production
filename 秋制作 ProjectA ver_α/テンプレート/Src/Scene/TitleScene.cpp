#include "../Engine/Graphics.h"
#include "../Engine/Input.h"
#include "../Texture/Texture.h"
#include "TitleScene.h"
#include "../Engine/Calculation.h"
#include "Scene.h"
#include "..//Timer/Timer.h"
#include "../Character/CharacterManager.h"
#include "../Engine/Lib/Lib.h"
#include "../Object/ObjectManager.h"
#include "../Object/ObjectID.h"

// タイトルシーンの初期化
void InitTitleScene();
// タイトルシーンのメイン処理
void MainTitleScene();
// タイトルシーンの終了
SceneId FinishTitleScene();

SceneId UpdateTitleScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitTitleScene();
		break;
	case SceneStep::MainStep:
		MainTitleScene();
		break;
	case SceneStep::EndStep:
		return FinishTitleScene();
		break;
	}

	return SceneId::TitleScene;
}

void DrawTitleScene()
{

	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleBgTex));

	ObjManager()->Draw();

}



void InitTitleScene()
{
	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init(Timer::Id::CLEAR);


	ObjManager()->Init();

	LoadTexture("Res/Title/TitleBg.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleBgTex);
	LoadTexture("Res/Game/Enemy/Bonnie.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleFreeTex);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainTitleScene()
{

	SceneController()->GameEnd();

	ObjManager()->Update();
	
	//ニューゲームUIにマウスオーバーしている場合シーン遷移
	if (ObjManager()->HasOnMouse(ObjID::BUTTON_NEW_GAME) == true) {
		if (OnMouseDown(Left) == true) {
			ChangeSceneStep(SceneStep::EndStep);
		}
	}
}

SceneId FinishTitleScene()
{
	// リリース解放
	ReleaseCategoryTexture(SceneId::TitleScene);
	ReleaseCategoryTexture(TEXTURE_CATEGORY_GAME);

	//ObjManager()->Release(TITLE_LOGO);
	//ObjManager()->Release(BUTTON_NEW_GAME);
	//ObjManager()->Release(BUTTON_CONTINUE);
	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init();

	g_Manager.Initialize();

	// 次のシーンIDを返す
	return SceneId::OpeningScene;
}

