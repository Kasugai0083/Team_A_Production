#include "GameData.h"

GameData* PepshiMan() {
	static GameData g_GameData;
	return &g_GameData;
}