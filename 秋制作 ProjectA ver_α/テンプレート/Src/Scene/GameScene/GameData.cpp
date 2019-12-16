#include "GameData.h"

#include"../Scene.h"
#include "../../Character/CharacterManager.h"
#include "../../Timer/Timer.h"

GameData* GameView() {
	static GameData g_GameData;
	return &g_GameData;
}

//void GameData::SetViewID(SubGameScene id_) {
//
//}