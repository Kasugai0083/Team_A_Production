#ifndef PLAYER_H_
#define PLAYER_H_


#include "../Character.h"

class Player : public Character {
	 
public:
	/*
		コンストラクタ
	*/
	Player():
		Character(false)
	{}
	/*
		デストラクタ
	*/
	~Player() override {}

	void Init()override;

	void Update()override;

	void Draw()override;

	bool HasLight() override{
		return m_IsLight;
	}

	bool HasMask()override{
		return m_IsMask;
	}

	bool HasMonitor()override{
		return m_IsMonitor;
	}
	bool IsDeath()override { return m_IsActive; };
	void OnMask();


private:
// フラグ
	bool m_IsActive;		// 生きてるかどうか(必要性あるかな？)
	bool m_IsLight;		// ライトをつけてるかどうか
	bool m_IsMask;		// マスクをつけてるかどうか
	bool m_IsMonitor;	// モニターを見ているかどうか
	float m_MaskAnimation; // マスクのアニメーションタイマー

};

#endif
