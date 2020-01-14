#ifndef ENEMY_H_
#define ENEMY_H_

#include "../CharacterID.h"
#include "../../Utility/RoomID.h"
#include "../../Scene/Scene.h"
#include <random>
#include "../Character.h"
#include "../../Engine/Graphics.h"


class Enemy : public Character
{
public:
	/*
		コンストラクタ
	*/
	Enemy(RoomID roomId_, EnemyID enemyId_) :
		Character(false)
	{
		GameData::GetInstance()->SendEnemyData(&m_EnemyData, (int)enemyId_);
		m_RoomId	  = roomId_;
		m_iFrameCount = 0;
		m_HasKill	  = false;
		m_CanKill	  = false;
	}

	/*
		デストラクタ
	*/
	virtual ~Enemy() override{}

	/*
		初期化
	*/
	virtual void Init() override{}

	/*
		更新
	*/
	virtual void Update() override{}

	/*
		エネミーがプレイヤーを殺したかどうか
		m_HasKillを返す
	*/
	virtual bool HasKill()const override { return m_HasKill; }

	/*
		引数に指定したシーンのテクスチャをロードする
	*/
	virtual void LoadTex()override {}

	protected:
	// エネミーの移動用タイマークラス(未実装)
	class EnemyTimer
	{
	public:
		/*
			コンストラクタ
		*/
		EnemyTimer(int moveSpeed_) {

			m_Time = 0;
			m_MoveSpeed = moveSpeed_;
		}
		/*
			デストラクタ
		*/
		~EnemyTimer() {}

		/*
			移動用のタイマー関数
			特定の時間になるとTrueが返る
		*/
		bool MoveTimer();

	private:
		int m_Time;
		int m_MoveSpeed;
	};

protected:
	RoomID     m_RoomId;			  // どこの部屋にいるか変数
	int	       m_iFrameCount;		  // フレイムカウント用変数
	bool       m_CanKill;			  // 殺せるかどうか	True:殺せる　 False:殺せない
	bool       m_HasKill;			  // 殺したかどうか True:殺した   False:殺してない
	AnimationTexture m_AnimationTex;  // アニメーション用テクスチャ保存変数
	EnemyData  m_EnemyData;			  // 敵の移動速度とスポーン確率が保存されている変数

	Character* m_pPlayer;			  // プレイヤーの参照用変数
};

#endif