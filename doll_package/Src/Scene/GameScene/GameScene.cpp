#include <stdio.h>
#include "../../Scene/Scene.h"
#include "../../Engine/Input.h"
#include "../../Engine/Graphics.h"
#include "../../Texture/Texture.h"
#include "../../Engine/Calculation.h"
#include "../../Character/Enemy/Enemy.h"
#include "../../Timer/Timer.h"
#include "../../Character/CharacterManager.h"
#include "../../Object/ObjectManager.h"
#include "../../Object/ObjectID.h"
#include "../..//Data/GameData.h"
#include "GameScene.h"
#include "../../Object/Item/ItemValue.h"
#include "../../Object/Object.h"
#include "../../Object/UI/UIvalue.h"
#include "../../Engine/Audio/Audio.h"
#include "../../Texture/LoadTex.h"

// ゲーム本編シーンの初期化
void InitGameScene();
// ゲーム本編シーンのメイン処理
void MainGameScene();
// ゲーム本編シーンの終了
SceneId FinishGameScene();

//シーン遷移
SceneId UpdateGameScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitGameScene();
		break;
	case SceneStep::MainStep:
		MainGameScene();
		break;
	case SceneStep::EndStep:
		return FinishGameScene();
		break;
	}

	return SceneId::GameScene;
}

void DrawMonitorBg() {

	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (pPlayer->CurrentViewID() == SubGameScene::WORKSHOP_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownBgTex));
	}
	else if (pPlayer->CurrentViewID() == SubGameScene::LEFT_CORRIDOR_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctBgTex));
	}
	else if (pPlayer->CurrentViewID() == SubGameScene::RIGHT_CORRIDOR_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctBgTex));
	}
	else if (pPlayer->CurrentViewID() == SubGameScene::STORE_ROOM_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex));
	}
	else if (pPlayer->CurrentViewID() == SubGameScene::RECEPTION_ROOM_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorResptionRoomBgTex));
	}
	else if (pPlayer->CurrentViewID() == SubGameScene::CHILD_ROOM_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChildRoomBgTex));
	}

	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex));

	DrawFont(100.f, 900.f, "Space で 戻る", Large, White);

}

//シーンのメイン処理
void DrawGameScene()
{
	Object* pCenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);
	Object* pLeftCandle = ObjManager()->GetObj(ObjID::CANDLE_LEFT);
	Object* pRightCandle = ObjManager()->GetObj(ObjID::CANDLE_RIGHT);

	Character* pPlayer = g_Manager.GetCharacter(PLAYER);
	Timer* pTimerInstance = Timer::GetInstance();
	

	switch (pPlayer->CurrentViewID()) {
	case SubGameScene::CENTER_VIEW:
		if (pPlayer->HasMonitor() == false) {

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex));

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterDeskTex));

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFanceTex));

		}
		g_Manager.Draw();

		if (pPlayer->HasMonitor() == false) {

			if (pCenterCandle->HasCaLight() == false) {
				DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBlackTex));
			}
		}

		ObjManager()->Draw();

		pTimerInstance->Draw();

		pPlayer->Draw();

		break;
	case SubGameScene::RIGHT_VIEW:
		if (pPlayer->HasMonitor() == false) {
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightBgTex));
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiFrontTex));
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiBackTex));
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFanceTex));
			//カーテン
			if (pRightCandle->HasCaLight() == false) {
				DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightBlackTex));
			}
		}


		g_Manager.Draw();

		ObjManager()->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	case SubGameScene::LEFT_VIEW:
		if (pPlayer->HasMonitor() == false) {

			DrawTexture(128.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex));
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiFrontTex));
			DrawTexture(128.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiBackTex));
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFanceTex));

			//カーテン
			if (pLeftCandle->HasCaLight() == false) {
				DrawTexture(128.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftBlackTex));
			}
		}

		ObjManager()->Draw();

		pPlayer->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	case SubGameScene::WORKSHOP_VIEW:

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownBgTex));
		
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex));

		DrawFont(100.f, 900.f, "Space で 戻る", Large, White);

		ObjManager()->Draw();

		pPlayer->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	case SubGameScene::LEFT_CORRIDOR_VIEW:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctBgTex));
		
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex));

		DrawFont(100.f, 900.f, "Space で 戻る", Large, White);

		ObjManager()->Draw();

		pPlayer->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	case SubGameScene::RIGHT_CORRIDOR_VIEW:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctBgTex));

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex));

		DrawFont(100.f, 900.f, "Space で 戻る", Large, White);

		ObjManager()->Draw();

		pPlayer->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	case SubGameScene::STORE_ROOM_VIEW:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex));

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex));

		DrawFont(100.f, 900.f, "Space で 戻る", Large, White);

		ObjManager()->Draw();

		pPlayer->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	case SubGameScene::RECEPTION_ROOM_VIEW:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorResptionRoomBgTex));

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex));

		DrawFont(100.f, 900.f, "Space で 戻る", Large, White);

		ObjManager()->Draw();

		pPlayer->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	case SubGameScene::CHILD_ROOM_VIEW:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChildRoomBgTex));

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex));

		DrawFont(100.f, 900.f, "Space で 戻る", Large, White);

		ObjManager()->Draw();

		pPlayer->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	}
	
	g_Manager.KillAnimation();
	
		
	

}

void InitGameScene()
{
	InitTexture();

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init();

	ObjManager()->CreateGameObj();
	ObjManager()->Init();

	g_Manager.CreateCharacter();

	LoadSceneTex(SceneId::GameScene);

	// オーディオ
	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());
	pAudio->Load("GameBGM", "Res/Sound/GameBGM.wav");
	pAudio->Play("GameBGM", 0, true);

	pAudio->Load("RousokuSE", "Res/Sound/RousokuSE.wav");
	pAudio->Load("MaskSE", "Res/Sound/MaskSE.wav");
	pAudio->Load("OhagiKillVoice", "Res/Sound/OhagiKillVoice.wav");
	pAudio->Load("SakuraKillVoice", "Res/Sound/SakuraKillVoice.wav");
	pAudio->Load("UmeKillVoice", "Res/Sound/UmeKillVoice.wav");
	pAudio->Load("OranKillVoice", "Res/Sound/OranKillVoice.wav");
	pAudio->Load("BotanKillVoice", "Res/Sound/BotanKillVoice.wav");
	pAudio->Load("PuppetKillVoice", "Res/Sound/PuppetKillVoice.wav");
	pAudio->Load("ToMonitor", "Res/Sound/ToMonitor.wav");
	pAudio->Load("YukaKisimiSE", "Res/Sound/KisimiSE.wav");
	pAudio->Load("ClearSE", "Res/Sound/ClearSE.wav");
	pAudio->Load("ChildRoomBGM", "Res/Sound/ChildRoomBGM.wav");


	ChangeSceneStep(SceneStep::MainStep);
}


void MainGameScene()
{
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

;

	if (pPlayer == nullptr) {
		return;
	}

	//タイマーのアップデート

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Update();

	SceneController()->GameEnd();

	g_Manager.Update();

	ObjManager()->Update();

	//クリア時間経過でシーン遷移
	if (pTimerInstance->GetClearTime() == CLEAR_TIME) {
		SceneController()->SetID(SceneTransition::Id::Clear, true);
		ChangeSceneStep(SceneStep::EndStep);
	}

	//プレイヤーの死亡でシーン遷移
	if (pPlayer->IsActive() == false) {

		SceneController()->SetID(SceneTransition::Id::Clear, true);
		ChangeSceneStep(SceneStep::EndStep);
	}

}
//シーンのメイン処理ここまで

SceneId FinishGameScene()
{

	ReleaseCategoryTexture(TEXTURE_CATEGORY_GAME);
	ReleaseCategoryTexture(TEXTURE_CATEGORY_CENTER);
	ReleaseCategoryTexture(TEXTURE_CATEGORY_LEFT);
	ReleaseCategoryTexture(TEXTURE_CATEGORY_RIGHT);
	ReleaseCategoryTexture(TEXTURE_CATEGORY_MONITOR);

	ObjManager()->ReleaseGameObj();

	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());
	pAudio->Stop("GameBGM");

	if (SceneController()->IsGetID(SceneTransition::Id::Clear) == true) {
		SceneController()->SetID(SceneTransition::Id::Clear, false);
		return SceneId::ClearScene;
	}
}

