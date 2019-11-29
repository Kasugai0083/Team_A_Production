#ifndef ENEMY_H_
#define ENEMY_H_

#include "../Character.h"
#include "../CharacterID.h"
#include "../../Utility/RoomID.h"
#include "..//..//Scene/Scene.h"
#include <random>

class Enemy : public Character 
{
public:
	/*
		コンストラクタ
	*/
	Enemy(RoomID roomid_, int framecount_, bool haskill_):
		Character(false)
	{
		m_RoomId	  = roomid_; 
		m_iFrameCount = framecount_;
		m_HasKill	  = haskill_;
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
	virtual void LoadTex(SceneId id_)override {}

	/*
		純粋仮想関数
		エネミーがプレイヤーを殺したときにするアニメーション関数
	*/
	virtual void KillAnimation() = 0;

protected:
	// エネミーの移動用タイマークラス(未実装)
	class EnemyTimer
	{
	public:
		/*
			コンストラクタ
		*/
		EnemyTimer(int time_, int min_time_, int max_time) {

			m_Time = time_;
			m_RandTime = GetRand(min_time_, max_time);
		}
		/*
			デストラクタ
		*/
		~EnemyTimer(){}

		unsigned int GetRand(unsigned int min_val_, unsigned int max_val_);

		/*
			スポーン用のタイマー関数
			特定の時間になるとTrueが返る
		*/
		bool SpawnTimer(Enemy& enemy_);

		/*
			移動用のタイマー関数
			特定の時間になるとTrueが返る
		*/
		bool MoveTimer(Enemy& enemy_);

	protected:
		int m_Time;
		int m_RandTime;
	};

protected:
	RoomID m_RoomId;		// どこの部屋にいるか変数
	int	   m_iFrameCount;	// フレイムカウント用変数
	bool   m_CanKill;		// 殺せるかどうか	True:殺せる		False:殺せない
	bool   m_HasKill;		// 殺したかどうか   True:殺した     False:殺してない

	Character* m_pPlayer;	// プレイヤーの参照用変数
};

#endif