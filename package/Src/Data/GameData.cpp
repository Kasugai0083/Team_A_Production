#include "GameData.h"
#include "../Utility/FileReader.h"


void GameData::LoadGameData()
{
	FileReader GameDataReader;
	GameDataReader.LoadCSV(m_EData, &m_GameParam, &m_Days);
}
