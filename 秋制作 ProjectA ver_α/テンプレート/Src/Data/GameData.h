#ifndef GAMEDATA_H_
#define GAMEDATA_H_

#include "Days/DayController.h"
#include "../Utility/SingletonTemplate.h"
#include "../Character/CharacterID.h"

class CSV;

enum class SubGameScene {
	CENTER_VIEW,			//プレイヤールーム中央
	LEFT_VIEW,				//プレイヤールーム左
	RIGHT_VIEW,				//プレイヤールーム右
	WORKSHOP_VIEW,			//工房
	STORE_ROOM_VIEW,		//物置
	RECEPTION_ROOM_VIEW,	//客間
	CHILD_ROOM_VIEW,		//子供部屋
	RIGHT_CORRIDOR_VIEW,	//右廊下
	LEFT_CORRIDOR_VIEW,		//左廊下
};

/**
* エネミーのスポーンする頻度\n
* DAYによって調整
*/
const float D1_SPOWN_JUDGE_OHAGI = 1.0f;
const float D1_SPOWN_JUDGE_SAKURA = 1.0f;
const float D1_SPOWN_JUDGE_UME = 1.0f;
const float D1_SPOWN_JUDGE_RAN = 1.0f;
const float D1_SPOWN_JUDGE_BOTAN = 1.0f;

const float D2_SPOWN_JUDGE_OHAGI = 1.0f;
const float D2_SPOWN_JUDGE_SAKURA = 1.0f;
const float D2_SPOWN_JUDGE_UME = 1.0f;
const float D2_SPOWN_JUDGE_RAN = 1.0f;
const float D2_SPOWN_JUDGE_BOTAN = 1.0f;

const float D3_SPOWN_JUDGE_OHAGI = 1.0f;
const float D3_SPOWN_JUDGE_SAKURA = 1.0f;
const float D3_SPOWN_JUDGE_UME = 1.0f;
const float D3_SPOWN_JUDGE_RAN = 1.0f;
const float D3_SPOWN_JUDGE_BOTAN = 1.0f;

const float ED_SPOWN_JUDGE_OHAGI = 1.0f;
const float ED_SPOWN_JUDGE_SAKURA = 1.0f;
const float ED_SPOWN_JUDGE_UME = 1.0f;
const float ED_SPOWN_JUDGE_RAN = 1.0f;
const float ED_SPOWN_JUDGE_BOTAN = 1.0f;

/**
* エネミーの移動速度\n
* プランナーが調整する項目
*/
const int D1_MOVEMENT_SPEED_OHAGI = 300;
const int D1_MOVEMENT_SPEED_SAKURA = 300;
const int D1_MOVEMENT_SPEED_UME = 300;
const int D1_MOVEMENT_SPEED_RAN = 300;
const int D1_MOVEMENT_SPEED_BOTAN = 0;

const int D2_MOVEMENT_SPEED_OHAGI = 300;
const int D2_MOVEMENT_SPEED_SAKURA = 300;
const int D2_MOVEMENT_SPEED_UME = 300;
const int D2_MOVEMENT_SPEED_RAN = 300;
const int D2_MOVEMENT_SPEED_BOTAN = 0;

const int D3_MOVEMENT_SPEED_OHAGI = 300;
const int D3_MOVEMENT_SPEED_SAKURA = 300;
const int D3_MOVEMENT_SPEED_UME = 300;
const int D3_MOVEMENT_SPEED_RAN = 300;
const int D3_MOVEMENT_SPEED_BOTAN = 0;

const int ED_MOVEMENT_SPEED_OHAGI = 300;
const int ED_MOVEMENT_SPEED_SAKURA = 300;
const int ED_MOVEMENT_SPEED_UME = 300;
const int ED_MOVEMENT_SPEED_RAN = 300;
const int ED_MOVEMENT_SPEED_BOTAN = 0;

//! 蝋燭が溶ける速度
const float MELT_RATIO = 0.001f; 

//! ここで時間の進みを変更
const int TIME_MAGNIFICATION = 1;

struct EnemyData {
	float m_SpownJudge;
	float m_MovementSpeed;
};

struct GameParam {
	float m_MeltRatio;
	int m_TimeMagnification;
};

class GameData : public Singleton<GameData> {

public:
	// データを送信する関数(GameData を Accesor にしない場合)
	void SendEnemyData(EnemyData* edata_, int i) { *edata_ = m_EData[i]; }
	void SendGameParam(GameParam* gameparam_) { *gameparam_ = m_GameParam; }

	// データを受け取る関数(GameData を Accesor にする場合)
	void SetEnemyData(EnemyData edata_, CharacterID charid_) { m_EData[charid_] = edata_; }
	void SetGameParam(GameParam param_) { m_GameParam = param_; }

	// 値を読み込むメソッド
	void LoadDay(Days day_);

	void LoadParam(GameParam param_);


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