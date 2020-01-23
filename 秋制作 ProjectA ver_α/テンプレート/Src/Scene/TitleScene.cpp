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
#include "../Data/Days/DayController.h"
#include "../Data/GameData.h"
#include "../Utility/FileReader.h"
#include "../Texture/LoadTex.h"

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

static D3DXCOLOR g_TitleFade(0.f,0.f,0.f,0.f);
static bool SceneJump;

void DrawTitleScene()
{

	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleBgTex));

	ObjManager()->Draw();

	DrawFade(true, g_TitleFade);
}



void InitTitleScene()
{

	InitTexture();

	SceneJump = false;
	g_TitleFade.r = 0.f;
	g_TitleFade.g = 0.f;
	g_TitleFade.b = 0.f;
	g_TitleFade.a = 0.f;

	Timer* pTimerInstance = Timer::GetInstance();

	ObjManager()->CreateTitleObj();
	ObjManager()->Init();

	LoadSceneTex(SceneId::TitleScene);

	// オーディオ
	auto audio = AudioPlayer::GetInstance(GetWindowHandle());
	audio->Load("Title", "Sound/TitleBGM.wav");
	audio->Load("Select", "Sound/TitleStart.wav");

	audio->Play("Title", 0, true);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainTitleScene()
{
	auto audio = AudioPlayer::GetInstance();

	if (SceneJump == true) {

		g_TitleFade.a += 0.01f;
		if (g_TitleFade.a >= 1.5f) {
			ChangeSceneStep(SceneStep::EndStep);
		}
		return;
	}

	SceneController()->GameEnd();

	ObjManager()->Update();
	
	FileReader FR;



	//ニューゲームUIにマウスオーバーしている場合シーン遷移
	if (ObjManager()->HasOnMouse(ObjID::BUTTON_NEW_GAME) == true) {
		if (OnMouseDown(Left) == true) {

			DayManager()->LoadDays(Days::DAY_1);
			
			FR.WriteCSV("Days.csv", 1);

			GameData::GetInstance()->LoadGameData();

			SceneJump = true;
			audio->Play("Select", 0);

		}
	}
	if (ObjManager()->HasOnMouse(ObjID::BUTTON_CONTINUE) == true) {

		if (DayManager()->GetCurrentDays() != Days::DAY_0) {
			if (OnMouseDown(Left) == true) {

				SceneJump = true;
				audio->Play("Select");

			}
		}
		if (DayManager()->GetCurrentDays() == Days::DAY_0) {
			if (OnMouseDown(Left) == true) {

				SceneJump = true;
				audio->Play("Select");

			}
		}

	}



}

SceneId FinishTitleScene()
{
	// リリース解放
	ReleaseCategoryTexture(SceneId::TitleScene);
	
	ReleaseCategoryTexture(TEXTURE_CATEGORY_TITLE);
	ObjManager()->ReleaseTitleObj();

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init();

	//	オーディオ
	auto audio = AudioPlayer::GetInstance();
	audio->Stop("Title");
	audio->Release("Title");


		// 次のシーンIDを返す
	return SceneId::OpeningScene;

}

