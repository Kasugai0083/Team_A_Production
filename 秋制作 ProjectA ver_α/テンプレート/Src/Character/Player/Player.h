#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Character.h"
#include "../../Scene/GameScene/GameData.h"

class Player : public Character {
	 
public:
	/*
		コンストラクタ
	*/
	Player():
		Character(true)
	{
		m_HasGFreddySpown = false;
	}
	/*
		デストラクタ
	*/
	~Player() override {}

	void Init()override;

	void Update()override;

	void Draw()override;

	bool HasMask() const override{
		return m_IsMask;
	}

	bool IsActive() override { return m_IsActive; };

	MonitorView CurrentViewMonitorID() const override{
		return m_MonitorViewID;
	}

	//モニターシーン遷移を管理する関数
	void ControlMonitor() override;
	//ゲームシーン遷移を管理する関数
	void ControlGameScene() override;

	//ゴールデンフレディのフラグを取得
	bool HasGFreddySpown() override { return m_HasGFreddySpown; };


private:
	void OnMask();

private:
	bool m_IsActive;		// 生きてるかどうか(必要性あるかな？)
	bool m_IsMask;		// マスクをつけてるかどうか
	float m_MaskAnimation; // マスクのアニメーションタイマー
	bool m_HasGFreddySpown; //ゴールデンフレディのフラグが立っているかどうか

	MonitorView m_MonitorViewID; // モニターのどこを見ているか

};

#endif
