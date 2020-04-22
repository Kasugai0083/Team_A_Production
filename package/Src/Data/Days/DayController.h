#ifndef  DAY_CONTROLLER_H_
#define  DAY_CONTROLLER_H_

/**
*	@file DayController.h
*	@author 春日井
*	@brief 日付(難易度)を管理するクラスを定義
*/

class Character;

/**
* @enum Days
* @brief 日付(難易度)の段階
*/
enum class Days 
{
	DAY_0,
	DAY_1,
	DAY_2,
	DAY_3,

};

/**
* @class DayController
* @brief 日付(難易度)を管理するクラス
*/
class DayController 
{
public:

	DayController();		/** @brief コンストラクタ */
	~DayController() {};	/** @brief デストラクタ */

	/**
	* @fn LoadDays
	* @param[in] savedata_ 指定された値を m_Days に代入
	* @brief セーブデータの日付を読み込み
	*/
	void LoadDays(Days savedata_ = Days::DAY_0) { m_Days = savedata_; };


	/**
	* @fn CheckClear
	* @brief クリア済の場合日数を進行させる
	*/
	void CheckClear();

	/**
	* @fn DrawCurrentDays
	* @brief 現在の日数を画面に表示(デバッグ用)
	*/
	void DrawCurrentDays();

	Days GetCurrentDays() { return m_Days; };

private:
	Days m_Days;			/** @brief 日数情報 */
	Character* m_pPlayer;	/** @brief プレイヤーのポインタ */
};

DayController* DayManager();/** @brief 簡易版シングルトン */

#endif 