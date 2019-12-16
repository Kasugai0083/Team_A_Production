#include "GameData.h"

#include"../Scene.h"
#include "../../Character/CharacterManager.h"
#include "../../Timer/Timer.h"

GameData* GameView() {
	static GameData g_GameData;
	return &g_GameData;
}

void RoomToMonitor() {

	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	//キー入力でシーン遷移
	if (pPlayer->ControlGameScene() == true) {
		SceneController()->SetID(SceneTransition::Id::Monitor, true);
		ChangeSceneStep(SceneStep::EndStep);
	}
}

void MonitorToRoom() {
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	//キー入力でシーン遷移
	if (pPlayer->ControlGameScene() == true) {
		SceneController()->SetID(SceneTransition::Id::Game, true);
		ChangeSceneStep(SceneStep::EndStep);
	}
}

void GameData::Update() {

	Character* pPlayer = g_Manager.GetCharacter(PLAYER);
	Timer* pTimerInstance = Timer::GetInstance();

	//if (GetCurrentSceneId() == GameScene) {
	//	RoomToMonitor();
	//}
	//else if (GetCurrentSceneId() == MonitorScene) {
	//	MonitorToRoom();
	//}

	if (m_HasMonitor == false) {
		if (pPlayer->ControlGameScene() == true) {

			m_HasMonitor = true;

			pTimerInstance->Init(Timer::Id::SCENE);
		}
	}
	else {
		if (pPlayer->ControlMonitor() == true) {
			m_HasMonitor = false;

			pTimerInstance->Init(Timer::Id::SCENE);
		}
	}

}