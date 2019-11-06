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

	ObjManager()->Draw(object::TITLE_LOGO);
	ObjManager()->Draw(object::NEW_GAME);
	ObjManager()->Draw(object::CONTINUE);

}

void InitTitleScene()
{

	ObjManager()->Init();

	LoadTexture("Res/Title/TitleBg.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleBgTex);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainTitleScene()
{
	SceneController()->GameEnd();

	ObjManager()->Update();
	
	//ニューゲームUIにマウスオーバーしている場合シーン遷移
	if (ObjManager()->HasOnMouse(object::NEW_GAME) == true) {
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

	TimerFunc()->Init();
	g_Manager.Initialize();

	// 次のシーンIDを返す
	return SceneId::GameScene;
}

