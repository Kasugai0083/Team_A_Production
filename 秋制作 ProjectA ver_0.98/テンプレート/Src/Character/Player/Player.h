#ifndef PLAYER_H_
#define PLAYER_H_


#include "../Character.h"

class Player : public Character {
	 
public:

	//Player(){}

	~Player() override {}

	void Init()override;

	void Update()override;

	void Draw()override;

	bool GetIsLight() override{
		return m_IsLight;
	}

	bool GetIsMask()override{
		return m_IsMask;
	}

	bool GetIsMonitor()override{
		return m_IsMonitor;
	}
	bool GetIsDeath()override { return m_IsDeath; };
	void OnMask();


private:

// フラグ
	bool m_IsDeath;		// 生きてるかどうか(必要性あるかな？)
	bool m_IsLight;		// ライトをつけてるかどうか
	bool m_IsMask;		// マスクをつけてるかどうか
	bool m_IsMonitor;	// モニターを見ているかどうか
	float m_MaskAnimation; // マスクのアニメーションタイマー


};

#endif
