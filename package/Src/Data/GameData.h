#ifndef GAMEDATA_H_
#define GAMEDATA_H_

/**
*	@file GameData.h
*	@author 春日井
*	@brief 外部ファイルから読み込んできた値を管理するクラスを処理
*/

#include "Days/DayController.h"
#include "../Utility/SingletonTemplate.h"
#include "../Character/CharacterID.h"

class CSV;

/**
* @enum SubGameScene
* @brief モニタービューの種類
*/
enum class SubGameScene
{
	CENTER_VIEW,			//!< プレイヤールーム中央
	LEFT_VIEW,				//!< プレイヤールーム左
	RIGHT_VIEW,				//!< プレイヤールーム右
	WORKSHOP_VIEW,			//!< 工房
	STORE_ROOM_VIEW,		//!< 物置
	RECEPTION_ROOM_VIEW,	//!< 客間
	CHILD_ROOM_VIEW,		//!< 子供部屋
	RIGHT_CORRIDOR_VIEW,	//!< 右廊下
	LEFT_CORRIDOR_VIEW,		//!< 左廊下
};

/**
* @struct EnemyData
* @brief 外部出力されるエネミーの情報
*/
struct EnemyData
{
	int m_SpownJudge;		//!< エネミーの出現頻度
	int m_MovementSpeed;	//!< エネミーの移動時間
};

/**
* @struct GameParam
* @brief 外部出力されるゲームシステムの情報
*/
struct GameParam 
{
	float m_MeltRatio;		//!< 蝋燭の融解速度
	int m_TimeMagnification;//!< ステージクリアの時間
};

/**
* @class GameData
* @brief 外部ファイルから読み込んできた値を管理
*/
class GameData : public Singleton<GameData> 
{

public:
	/**
	* @fn LoadGameData
	* @brief 指定のCSVから値の抜き出し
	*/
	void LoadGameData();

public:
	/**
	* クラスの値を返す関数群
	*/

	EnemyData GetEnemyData(EnemyID enemyId_) const { return m_EData[static_cast<int>(enemyId_)]; }
	GameParam GetGameParam() const { return m_GameParam; }
	Days GetDays() const { return m_Days; }

private:
	EnemyData m_EData[6];
	GameParam m_GameParam;
	Days m_Days;
private:
	friend Singleton<GameData>;

	GameData() {};
	virtual ~GameData() {};

	//コピーコンストラクタの禁止
	GameData(const GameData&) = delete;
	GameData& operator=(const GameData&) = delete;
	//ムーブコンストラクタの禁止
	GameData(const GameData&&) = delete;
	GameData& operator=(const GameData&&) = delete;
};

#endif
