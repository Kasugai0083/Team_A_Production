#ifndef CHARACTER_H_
#define CHARACTER_H_

/**
*	@file	Character.h
*	@author 中本
*	@brief	キャラクターの基底クラス
*/

#include "..//Scene/Scene.h"
#include "../Data/GameData.h"
#include "../Utility/RoomID.h"

/**
* @brief キャラクターの基底クラス
* @details このクラスからプレイヤーやエネミーに派生していく
*/
class Character {
public:
	/**
	* @fn		　	Character(bool is_active_
	* @brief		コンストラクタ
	* @param[in]	is_active_(引数名) キャラクターがアクティブ状態か
	*/
	Character(bool is_active_)
	{
		m_IsActive = is_active_;
	}

	/**
	* @fn		　	~Character()
	* @brief		デストラクタ
	*/
	virtual ~Character(){}

	/**
	* @fn			bool IsActive()
	* @brief		キャラクターがアクティブかどうかを調べる関数
	* @return		bool true : アクティブ	false : 非アクティブ
	*/
	virtual bool IsActive() { return m_IsActive; }

	/**
	* @fn void Init()
	* @brief キャラクターの初期化関数
	*/
	virtual void Init() = 0;

	/**
	* @fn void Update()
	* @brief キャラクターの更新関数
	*/
	virtual void Update() = 0;

	/**
	* @fn		void Draw()
	* @brief	キャラクターの描画関数
	*/
	virtual void Draw() = 0;

	virtual bool HasLight() const
	{
		return m_HasLight;
	}

	virtual bool HasMask() const {
		return m_HasMask;
	}

	virtual bool HasMonitor() const {
		return m_HasMonitor;
	}

	virtual SubGameScene CurrentViewID() const {
		return m_ViewID;
	}

	/**
	* @fn		bool HasKill()
	* @brief	プレイヤーを殺したかどうかを返す関数
	* @return	bool true : 殺した	false : 殺してない
	*/
	virtual bool HasKill() const{
		return m_HasKill;
	}

	/**
	* @fn		bool CanKill()
	* @brief	エネミーがプレイヤーを殺せる状態かどうかを返す関数
	* @return	bool true : 殺せる	false : 殺せない
	*/
	virtual bool CanKill() const { 
		return false; 
	}

	/**
	* @fn		RoomID GetRoomID()
	* @brief	エネミーいる部屋を返す関数
	* @return	RoomID エネミーいる部屋が返る
	*/
	virtual RoomID GetRoomID() const { 
		return RoomID::ROOM_VOID; 
	}


	/**
	* @fn		void KillAnimation()
	* @brief	キルアニメーションの描画関数
	*/
	virtual void KillAnimation() {}

	// 2019/12/05追加
	virtual bool ControlMonitor()	{ return 0; }
	virtual bool ControlGameScene() { return 0; }
	virtual bool HasGFreddySpown()	{ return 0; }



	virtual const bool CurrentViewID(const SubGameScene sceneId_) const { return 0; }

	/**
	* @fn		bool SpawnJudgement() const
	* @brief	m_SpawnJudgementを返す
	* @return	bool
	*/
	virtual bool SpawnJudgement() const { return 0; }


protected:
	bool m_IsActive;		//! キャラクターがアクティブかどうかを保存する変数

private:
	//! プレイヤーの情報
	bool m_HasMask;
	bool m_HasLight;
	bool m_HasMonitor;
	SubGameScene m_ViewID;

	bool m_HasKill;			//! 殺したかどうか
};

#endif