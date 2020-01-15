#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Character.h"
#include "../..//Data/GameData.h"

class Player : public Character {
	 
public:
	/*
		コンストラクタ
	*/
	Player():
		Character(true)
	{
		m_HasGFreddySpown = false;
		m_HasMonitor = false;
		m_ViewID = SubGameScene::CENTER_VIEW;
		TmpRoom = SubGameScene::CENTER_VIEW;
		TmpMonitor = SubGameScene::WORKSHOP_VIEW;

		m_IsMask = false;
		m_MaskAnimation = -540.f;
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

	void LoadTex() override;

	bool HasMonitor() const override {
		return m_HasMonitor;
	}

	bool IsActive() override { return m_IsActive; };

	SubGameScene CurrentViewID() const override{
		return m_ViewID;
	}
	//モニターシーン遷移を管理する関数
	bool ControlMonitor() override;
	//ゲームシーン遷移を管理する関数
	bool ControlGameScene() override;

	//ゴールデンフレディのフラグを取得
	bool HasGFreddySpown() override { return m_HasGFreddySpown; };

	const bool CurrentViewID(const SubGameScene sceneId_) const override;



private:
	void OnMask();

	template <class T1, class T2>
	void KeyPush(T1 button_, T2 view_);

	template <class T1, class T2>
	void ButtonPush(T1 button_, T2 view_);

private:
	//bool m_IsActive;		// 生きてるかどうか(必要性あるかな？)
	bool m_IsMask;		// マスクをつけてるかどうか
	float m_MaskAnimation; // マスクのアニメーションタイマー
	bool m_HasGFreddySpown; //ゴールデンフレディのフラグが立っているかどうか
	bool m_HasMonitor;		// モニターを見ているかどうか

	SubGameScene m_ViewID, TmpRoom, TmpMonitor;
};

#endif
