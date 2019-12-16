#include "DayController.h"
#include "..//..//Engine/Graphics.h"
#include <string>

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

	//bool check = true;
	bool check = m_pPlayer->IsActive();

	if (check != true) {
		switch (m_Days)
		{
		case Days::DAY_0:
			m_Days = Days::DAY_1;
			break;
		case Days::DAY_1:
			m_Days = Days::DAY_2;
			break;
		case Days::DAY_2:
			m_Days = Days::DAY_3;
			break;
		case Days::DAY_3:
			m_Days = Days::ENDING;
			break;
		default:
			break;
		}
	}
	else if (check == false) {

	}

};