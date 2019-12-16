#ifndef  DAY_CONTROLLER_H_
#define  DAY_CONTROLLER_H_

#include "../../Character/CharacterManager.h"

enum class Days {
	DAY_0,
	DAY_1,
	DAY_2,
	DAY_3,

	ENDING
};

// なんとなく作ったＤＡＹ管理クラス
class DayController {
public:
	//仮にコンストラクタで初期化
	DayController() { 
		m_Days = Days::DAY_0;
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
	};
	~DayController() {};

	void LoadDays(Days savedata_ = Days::DAY_0) { m_Days = savedata_; };

	void CheckClear();

	Days GetCurrentDays() { return m_Days; };

	void DrawCurrentDays();

private:
	Days m_Days;
	Character* m_pPlayer;
};

DayController* DayManager();

#endif 