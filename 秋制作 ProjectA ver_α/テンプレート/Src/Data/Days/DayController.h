#ifndef  DAY_CONTROLLER_H_
#define  DAY_CONTROLLER_H_

class Character;

enum class Days {
	DAY_0,
	DAY_1,
	DAY_2,
	DAY_3,

};

// なんとなく作ったＤＡＹ管理クラス
class DayController {
public:
	//仮にコンストラクタで初期化
	DayController();
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