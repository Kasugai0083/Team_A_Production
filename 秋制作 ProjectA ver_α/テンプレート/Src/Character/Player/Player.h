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
	{}
	/*
		デストラクタ
	*/
	~Player() override {}

	void Init()override;

	void Update()override;

	void Draw()override;

	bool HasLight() const override{
		return m_IsLight;
	}

	bool HasMask() const override{
		return m_IsMask;
	}

	bool HasMonitor() const override{
		return m_IsMonitor;
	}
	bool IsDeath() override { return m_IsActive; };

	MonitorView CurrentViewMonitorID() const override{
		return m_MonitorViewID;
	}

	void OnMask();


private:
// フラグ
	bool m_IsActive;		// 生きてるかどうか(必要性あるかな？)
	bool m_IsLight;		// ライトをつけてるかどうか
	bool m_IsMask;		// マスクをつけてるかどうか
	bool m_IsMonitor;	// モニターを見ているかどうか
	float m_MaskAnimation; // マスクのアニメーションタイマー

	MonitorView m_MonitorViewID; // モニターのどこを見ているか

};

#endif
