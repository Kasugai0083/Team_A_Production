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
#include "../Engine/Audio/Audio.h"
#include "../Scene/Days/DayController.h"

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

bool g_flag = false;

void DrawTitleScene()
{

	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleBgTex));

	ObjManager()->Draw();

	DayManager()->DrawCurrentDays();

	if (g_flag == true) {
		DrawFont(100.f,100.f, "ON",FontSize::Large,FontColor::Yellow);
	}
	else {
		DrawFont(100.f, 100.f, "OFF", FontSize::Large, FontColor::Yellow);

	}

}



void InitTitleScene()
{
	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init(Timer::Id::CLEAR);


	ObjManager()->Init();

	LoadTexture("Res/Title/TitleBg.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleBgTex);
	LoadTexture("Res/Game/Enemy/Bonnie.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleFreeTex);


	// オーディオ
	auto audio = AudioPlayer::GetInstance(GetWindowHandle());
	audio->Load("Title", "Sound/nayu_dra.wav");
	audio->Play("Title");

	ChangeSceneStep(SceneStep::MainStep);
}

void MainTitleScene()
{

	SceneController()->GameEnd();

	ObjManager()->Update();
	
	if (GetKeyDown(SPACE_KEY) == true) {
		if (g_flag == false) {
			g_flag = true;
		}
		else {
			g_flag = false;
		}
	}

	//ニューゲームUIにマウスオーバーしている場合シーン遷移
	if (ObjManager()->HasOnMouse(ObjID::BUTTON_NEW_GAME) == true) {
		if (OnMouseDown(Left) == true) {
			DayManager()->LoadDays(Days::DAY_1);
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

	//	オーディオ
	auto audio = AudioPlayer::GetInstance();
	audio->Stop("Title");
	audio->Release("Title");


	g_Manager.Initialize();

	// 次のシーンIDを返す
	return SceneId::OpeningScene;
}

