#include "GameData.h"
#include "../Utility/FileReader.h"

void GameData::LoadDay(Days day_) {

	switch (day_)
	{
	case Days::DAY_0:
		break;
	case Days::DAY_1:
		m_EData[0].m_SpownJudge = D1_SPOWN_JUDGE_OHAGI;
		m_EData[0].m_MovementSpeed = D1_MOVEMENT_SPEED_OHAGI;

		m_EData[1].m_SpownJudge = D1_SPOWN_JUDGE_SAKURA;
		m_EData[1].m_MovementSpeed = D1_MOVEMENT_SPEED_SAKURA;

		m_EData[2].m_SpownJudge = D1_SPOWN_JUDGE_UME;
		m_EData[2].m_MovementSpeed = D1_MOVEMENT_SPEED_UME;

		m_EData[3].m_SpownJudge = D1_SPOWN_JUDGE_RAN;
		m_EData[3].m_MovementSpeed = D1_MOVEMENT_SPEED_RAN;

		m_EData[4].m_SpownJudge = D1_SPOWN_JUDGE_BOTAN;
		m_EData[4].m_MovementSpeed = D1_MOVEMENT_SPEED_BOTAN;
		
		break;
	case Days::DAY_2:
		m_EData[0].m_SpownJudge = D2_SPOWN_JUDGE_OHAGI;
		m_EData[0].m_MovementSpeed = D2_MOVEMENT_SPEED_OHAGI;

		m_EData[1].m_SpownJudge = D2_SPOWN_JUDGE_SAKURA;
		m_EData[1].m_MovementSpeed = D2_MOVEMENT_SPEED_SAKURA;

		m_EData[2].m_SpownJudge = D2_SPOWN_JUDGE_UME;
		m_EData[2].m_MovementSpeed = D2_MOVEMENT_SPEED_UME;

		m_EData[3].m_SpownJudge = D2_SPOWN_JUDGE_RAN;
		m_EData[3].m_MovementSpeed = D2_MOVEMENT_SPEED_RAN;

		m_EData[4].m_SpownJudge = D2_SPOWN_JUDGE_BOTAN;
		m_EData[4].m_MovementSpeed = D2_MOVEMENT_SPEED_BOTAN;

		break;
	case Days::DAY_3:
		m_EData[0].m_SpownJudge = D3_SPOWN_JUDGE_OHAGI;
		m_EData[0].m_MovementSpeed = D3_MOVEMENT_SPEED_OHAGI;

		m_EData[1].m_SpownJudge = D3_SPOWN_JUDGE_SAKURA;
		m_EData[1].m_MovementSpeed = D3_MOVEMENT_SPEED_SAKURA;

		m_EData[2].m_SpownJudge = D3_SPOWN_JUDGE_UME;
		m_EData[2].m_MovementSpeed = D3_MOVEMENT_SPEED_UME;

		m_EData[3].m_SpownJudge = D3_SPOWN_JUDGE_RAN;
		m_EData[3].m_MovementSpeed = D3_MOVEMENT_SPEED_RAN;

		m_EData[4].m_SpownJudge = D3_SPOWN_JUDGE_BOTAN;
		m_EData[4].m_MovementSpeed = D3_MOVEMENT_SPEED_BOTAN;
		break;
	default:
		break;
	}

}

void GameData::LoadParam(GameParam param_) {
	m_GameParam.m_MeltRatio = param_.m_MeltRatio;
	m_GameParam.m_TimeMagnification = param_.m_TimeMagnification;
}

void GameData::LoadGameData()
{
	FileReader GameDataReader;
	GameDataReader.LoadCSV(m_EData, &m_GameParam, &m_Days);
}
