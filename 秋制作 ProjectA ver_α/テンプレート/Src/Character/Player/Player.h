#ifndef PLAYER_H_
#define PLAYER_H_

/**
*	@file Player.h
*	@author 春日井
*	@brief プレイヤーを管理するクラスを処理
*/


#include "../Character.h"
#include "../..//Data/GameData.h"

class Player : public Character {
	 
public:
	// コンストラクタ
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
	
	// デストラクタ
	~Player() override {}

	void Init()override;	// 初期化

	void Update()override;	// 更新

	void Draw()override;	// 描画

	// プレイヤーがマスクを被っているかどうか
	bool HasMask() const override
	{
		return m_IsMask;
	}

	// プレイヤーがモニターを見ているかどうか
	bool HasMonitor() const override
	{
		return m_HasMonitor;
	}

	// プレイヤーが生きているかどうか
	bool IsActive() override { return m_IsActive; };

	// どこの部屋を見ているか
	SubGameScene CurrentViewID() const override
	{
		return m_ViewID;
	}
	// モニターシーン遷移を管理する関数
	bool ControlMonitor() override;
	// ゲームシーン遷移を管理する関数
	bool ControlGameScene() override;

	//ゴールデンフレディのフラグを取得
	bool HasGFreddySpown() override { return m_HasGFreddySpown; };

	// 現在のプレイヤー視界情報と引数の視界情報を比較
	const bool CurrentViewID(const SubGameScene sceneId_) const override;

private:

	void OnMask();	// マスクのアニメーション

	template <class T1, class T2>
	void KeyPush(T1 button_, T2 view_);

	template <class T1, class T2>
	void ButtonPush(T1 button_, T2 view_);

private:
	bool m_IsMask;			// マスクをつけてるかどうか
	float m_MaskAnimation;	// マスクのアニメーションタイマー
	bool m_HasGFreddySpown; // ゴールデンフレディのフラグが立っているかどうか
	bool m_HasMonitor;		// モニターを見ているかどうか

	// 視界情報の制御
	SubGameScene m_ViewID, TmpRoom, TmpMonitor;
};

#endif
