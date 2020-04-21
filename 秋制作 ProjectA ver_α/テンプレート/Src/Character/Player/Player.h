#ifndef PLAYER_H_
#define PLAYER_H_

/**
*	@file Player.h
*	@author 春日井
*	@brief プレイヤーを管理するクラスを定義
*/

#include "../Character.h"
#include "../..//Data/GameData.h"

/**
* @class Player
* @brief プレイヤーの情報を制御・管理
*/
class Player : public Character 
{
	 
public:
	/** @brief コンストラクタ */
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
	
	~Player() override {}	/** @brief デストラクタ */

	void Init()override;	/** @brief 初期化 */

	void Update()override;	/** @brief 更新 */

	void Draw()override;	/** @brief 描画 */

	/**
	* @fn HasMask
	* @brief プレイヤーがマスクを被っているかどうか
	*/
	bool HasMask() const override
	{
		return m_IsMask;
	}


	/**
	* @fn HasMonitor
	* @brief プレイヤーがモニターを見ているかどうか
	*/
	bool HasMonitor() const override
	{
		return m_HasMonitor;
	}

	/**
	* @fn IsActive
	* @brief プレイヤーが生きているかどうか
	*/
	bool IsActive() override { return m_IsActive; };

	/**
	* @fn CurrentViewID
	* @brief どこの部屋を見ているか
	*/
	SubGameScene CurrentViewID() const override
	{
		return m_ViewID;
	}

	/**
	* @fn ControlMonitor
	* @brief モニターシーン遷移を管理する関数
	*/
	bool ControlMonitor() override;
	/**
	* @fn ControlGameScene
	* @brief ゲームシーン遷移を管理する関数
	*/
	bool ControlGameScene() override;
	/**
	* @fn HasGFreddySpown
	* @brief ゴールデンフレディのフラグを取得
	*/
	bool HasGFreddySpown() override { return m_HasGFreddySpown; };

	/**
	* @fn CurrentViewID
	* @brief 現在のプレイヤー視界情報と引数の視界情報を比較
	*/ 
	const bool CurrentViewID(const SubGameScene sceneId_) const override;

private:
	/**
	* クラス内で使用する関数
	*/

	/**
	* @fn OnMask
	* @brief マスクのアニメーション
	*/
	void OnMask();

	/**
	* @fn KeyPush
	* @param[in] button_ どのボタンを触れたか
	* @param[out] view_ どの ViewScene に移動するか
	* @brief button_ で指定したボタンを入力した view_ で指定した ViewScene に遷移
	*/
	template <class T1, class T2>
	void KeyPush(T1 button_, T2 view_);

	/**
	* @fn ButtonPush
	* @param[in] button_ どのボタンを触れたか
	* @param[out] view_ どの MonitorView に移動するか
	* @brief button_ で指定したボタンを入力した view_ で指定した MonitorView に遷移
	*/
	template <class T1, class T2>
	void ButtonPush(T1 button_, T2 view_);

private:
	bool m_IsMask;			/** @brief マスクをつけてるかどうか */
	float m_MaskAnimation;	/** @brief マスクのアニメーションタイマー */
	bool m_HasGFreddySpown;	/** @brief ゴールデンフレディのフラグが立っているかどうか */
	bool m_HasMonitor;		/** @brief モニターを見ているかどうか */

	/** @brief 視界情報の制御 */
	SubGameScene m_ViewID, TmpRoom, TmpMonitor;
};

#endif
