#include "GameData.h"
#include "../Utility/FileReader.h"


void GameData::LoadParam(GameParam param_) {
	m_GameParam.m_MeltRatio = param_.m_MeltRatio;
	m_GameParam.m_TimeMagnification = param_.m_TimeMagnification;
}

void GameData::LoadGameData()
{
	FileReader GameDataReader;
	GameDataReader.LoadCSV(m_EData, &m_GameParam, &m_Days);
}
