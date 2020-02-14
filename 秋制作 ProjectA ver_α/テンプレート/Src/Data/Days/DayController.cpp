#include "DayController.h"
#include "..//..//Engine/Graphics.h"
#include <string>
#include "../../Character/CharacterManager.h"
#include "../../Utility/FileReader.h"

DayController::DayController() {
	m_Days = GameData::GetInstance()->GetDays();
};


DayController* DayManager() {
	static DayController Days;
	return &Days;
}

void DayController::DrawCurrentDays() {

	std::string debug;

	debug = std::to_string(static_cast<int>(m_Days));

	DrawFont(100.f, 100.f, debug.c_str(), Large, Yellow);
}

void DayController::CheckClear() {
	// クリアフラグをどっかでとってDAYを進行する

	m_pPlayer = g_Manager.GetCharacter(PLAYER);
	
	//bool check = true;
	bool check = m_pPlayer->IsActive();

	FileReader FR;

	if (check == true) {
		switch (m_Days)
		{
		case Days::DAY_0:
			m_Days = Days::DAY_1;
			break;
		case Days::DAY_1:
			m_Days = Days::DAY_2;
			FR.WriteCSV("Res/Csv/Days.csv", static_cast<int>(m_Days));
			break;
		case Days::DAY_2:
			m_Days = Days::DAY_3;
			FR.WriteCSV("Res/Csv/Days.csv", static_cast<int>(m_Days));
			break;
		case Days::DAY_3:
			break;
		default:
			break;
		}
	}
	else if (check == false) {

	}

};