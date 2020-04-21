#ifndef  DAY_CONTROLLER_H_
#define  DAY_CONTROLLER_H_

/**
*	@file DayController.h
*	@author 春日井
*	@brief 日付(難易度)を管理するクラスを処理
*/


class Character;

enum class Days 
{
	DAY_0,
	DAY_1,
	DAY_2,
	DAY_3,

};

class DayController 
{
public:

	DayController();		// コンストラクタ
	~DayController() {};	// デストラクタ

	// セーブデータの日付を読み込み
	void LoadDays(Days savedata_ = Days::DAY_0) { m_Days = savedata_; };

	// クリア済の場合日数を進行させる
	void CheckClear();

	// 現在の日数を画面に表示(デバッグ用)
	void DrawCurrentDays();

	Days GetCurrentDays() { return m_Days; };

private:
	Days m_Days;			// 日数情報
	Character* m_pPlayer;	// プレイヤーのポインタ
};

// 簡易版シングルトン
DayController* DayManager();

#endif 