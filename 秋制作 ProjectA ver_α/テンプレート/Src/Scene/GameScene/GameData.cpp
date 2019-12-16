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
	if (pTimerInstance->GetTime(Timer::Id::SCENE) >= SCENE_WAIT) {

		if (pPlayer->ControlGameScene() == true) {
			if (m_HasMonitor == false) {
				m_HasMonitor = true;
			}
			else {
				m_HasMonitor = false;
			}

			pTimerInstance->Init(Timer::Id::SCENE);

		}
	}

}