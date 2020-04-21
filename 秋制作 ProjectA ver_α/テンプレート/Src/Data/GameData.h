#ifndef GAMEDATA_H_
#define GAMEDATA_H_

/**
*	@file Botan.h
*	@author 春日井
*	@brief キャラクター「牡丹」を管理するクラスを処理
*/

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

struct EnemyData {
	int m_SpownJudge;
	int m_MovementSpeed;
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
	// ゲット関数
	EnemyData GetEnemyData(EnemyID enemyId_) const { return m_EData[static_cast<int>(enemyId_)]; }
	GameParam GetGameParam() const { return m_GameParam; }
	Days GetDays() const { return m_Days; }

	// データを受け取る関数(GameData を Accesor にする場合)
	void SetEnemyData(EnemyData edata_, CharacterID charid_) { m_EData[charid_] = edata_; }
	void SetGameParam(GameParam param_) { m_GameParam = param_; }

	// 値を読み込むメソッド
	void LoadDay(Days day_);

	void LoadParam(GameParam param_);

	void LoadGameData();

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
