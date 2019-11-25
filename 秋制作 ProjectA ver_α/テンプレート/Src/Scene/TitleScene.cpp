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

int y = 1.f;
int y2 = 1.f;

Size size = {256.f, 256.f};

void DrawTitleScene()
{

	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleBgTex));

	ObjManager()->DrawUI(TITLE_LOGO);
	ObjManager()->DrawUI(BUTTON_NEW_GAME);
	ObjManager()->DrawUI(BUTTON_CONTINUE);

	y2++;

	DrawTexture(900.0f, 500.0f + y2, GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleFreeTex),size);
}



void InitTitleScene()
{

	ObjManager()->Init();

	LoadTexture("Res/Title/TitleBg.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleBgTex);
	LoadTexture("Res/Game/Item/Candle_Center_Right_Left.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleFreeTex);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainTitleScene()
{
	SceneController()->GameEnd();

	ObjManager()->Update();
	

	size.Height -= y;

	//ニューゲームUIにマウスオーバーしている場合シーン遷移
	if (ObjManager()->HasOnMouseUI(BUTTON_NEW_GAME) == true) {
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

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init();

	g_Manager.Initialize();

	// 次のシーンIDを返す
	return SceneId::GameScene;
}

