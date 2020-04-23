#ifndef ENEMY_H_
#define ENEMY_H_

/**
*	@file	Enemy.h
*	@author 中本
*	@brief	エネミーを管理するクラスを処理
*/


#include <random>
#include "../CharacterID.h"
#include "../../Utility/RoomID.h"
#include "../../Scene/Scene.h"
#include "../Character.h"
#include "../../Engine/Graphics.h"


/**
* @brief	キャラクターの子クラス
* @details	このクラスからそれぞれのエネミーに派生させる
*/
class Enemy : public Character
{
public:
	/**
	* @fn			Enemy(RoomID roomId_, EnemyID enemyId_)
	* @brief		エネミーの初期化を行うコンストラクタ
	* @param[in]	RoomID(roomId_)	エネミーの出現する部屋
	* @param[in]	EnemyID(enemyId_)	エネミーのID
	*/
	Enemy(RoomID roomId_, EnemyID enemyId_) :
		Character(false)
	{
		m_EnemyData.m_MovementSpeed = GameData::GetInstance()->GetEnemyData(enemyId_).m_MovementSpeed;
		m_EnemyData.m_SpownJudge	= GameData::GetInstance()->GetEnemyData(enemyId_).m_SpownJudge;
		m_RoomId	  = roomId_;
		m_iFrameCount = 0;
		m_HasKill	  = false;
		m_CanKill	  = false;

		m_Color.r = 0.5f;
		m_Color.g = 0.f;
		m_Color.b = 0.f;
		m_Color.a = 0.f;
	}

	/**
	* @fn		~Enemy()
	* @brief	デストラクタ
	*/
	virtual ~Enemy() override{}

	/**
	* @fn		void Init()
	* @brief	初期化関数
	*/
	virtual void Init() override{}

	/**
	* @fn		void Init()
	* @brief	更新関数
	*/
	virtual void Update() override{}

	/**
	* @fn		RoomID GetRoomID()
	* @brief	エネミーいる部屋を返す関数
	* @return	RoomID エネミーいる部屋が返る
	*/
	RoomID GetRoomID() const override{ return m_RoomId; }

	/**
	* @fn		bool HasKill()
	* @brief	プレイヤーを殺したかどうかを返す関数
	* @return	bool true : 殺した	false : 殺してない
	*/
	bool HasKill()const override { return m_HasKill; }

	/**
	* @fn		bool CanKill()
	* @brief	エネミーがプレイヤーを殺せる状態かどうかを返す関数
	* @return	bool true : 殺せる	false : 殺せない
	*/
	bool CanKill() const override { return m_CanKill; }



protected:
	RoomID     m_RoomId;			  //! どの部屋にいるかを保存する変数
	int	       m_iFrameCount;		  //! フレイムカウント用変数
	bool       m_CanKill;			  //! プレイヤーを殺せるかどうか
	bool       m_HasKill;			  //! 殺したかどうか
	EnemyData  m_EnemyData;			  //! 敵の移動速度とスポーン確率が保存されている変数
	AnimationTexture m_AnimationTex;  //! アニメーション用テクスチャ保存変数

	Character* m_pPlayer;			  //! プレイヤーの参照用変数

	D3DXCOLOR m_Color;				  //! フェードイン処理のための変数
};

#endif