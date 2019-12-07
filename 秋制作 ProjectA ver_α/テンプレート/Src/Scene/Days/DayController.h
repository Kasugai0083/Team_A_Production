#ifndef  DAY_CONTROLLER_H_
#define  DAY_CONTROLLER_H_



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
	DayController() { m_Days = Days::DAY_0; };
	~DayController() {};

	void LoadDays(Days savedata_ = Days::DAY_0) { m_Days = savedata_; };

	void CheckClear() {
		// クリアフラグをどっかでとってDAYを進行する
		bool Clear = false;

		if (Clear == true) {
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
	};

	Days GetCurrentDays() { return m_Days; };

private:
	static Days m_Days;
};

#endif // ! DAY_CONTROLLER_H_
