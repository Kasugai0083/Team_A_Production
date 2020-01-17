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

void DrawTitleScene()
{

	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleBgTex));

	ObjManager()->Draw();

	DayManager()->DrawCurrentDays();
}



void InitTitleScene()
{

	InitTexture();

	GameData::GetInstance()->LoadGameData();

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init(Timer::Id::CLEAR);

	ObjManager()->CreateTitleObj();
	ObjManager()->Init();

	LoadSceneTex(SceneId::TitleScene);

	// オーディオ
	auto audio = AudioPlayer::GetInstance(GetWindowHandle());
	audio->Load("Title", "Sound/TitleBGM.wav");
	audio->Load("Select", "Sound/TitleStart.wav");

	audio->Play("Title", 1000, true);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainTitleScene()
{

	SceneController()->GameEnd();

	ObjManager()->Update();
	
	FileReader FR;

	//ニューゲームUIにマウスオーバーしている場合シーン遷移
	if (ObjManager()->HasOnMouse(ObjID::BUTTON_NEW_GAME) == true) {
		if (OnMouseDown(Left) == true) {

			DayManager()->LoadDays(Days::DAY_1);
			
			FR.WriteCSV("Days.csv", 1);

			ChangeSceneStep(SceneStep::EndStep);
		}
	}
	if (ObjManager()->HasOnMouse(ObjID::BUTTON_CONTINUE) == true) {

		if (DayManager()->GetCurrentDays() != Days::DAY_0) {
			if (OnMouseDown(Left) == true) {
				ChangeSceneStep(SceneStep::EndStep);
			}
		}
		if (DayManager()->GetCurrentDays() == Days::DAY_0) {
			if (OnMouseDown(Left) == true) {
				//DayManager()->LoadDays(Days::DAY_3);
				ChangeSceneStep(SceneStep::EndStep);
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

	audio->Play("Select");

	// 次のシーンIDを返す
	return SceneId::OpeningScene;
}

