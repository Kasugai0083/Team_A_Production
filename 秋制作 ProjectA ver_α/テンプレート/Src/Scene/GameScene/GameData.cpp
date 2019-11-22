#include "GameData.h"

GameData* GameView() {
	static GameData g_GameData;
	return &g_GameData;
}