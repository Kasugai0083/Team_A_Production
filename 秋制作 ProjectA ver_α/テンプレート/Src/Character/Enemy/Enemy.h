#ifndef ENEMY_H_
#define ENEMY_H_
#include "../Character.h"
#include "../CharacterID.h"
#include "../../Utility/RoomID.h"
#include "..//..//Scene/Scene.h"
#include <random>


class Enemy : public Character {
public:
	virtual ~Enemy() override{}

	virtual bool HasKill()const override { return m_HasKill; }

	virtual void LoadTex(SceneId id_)override {}

protected:
	// エネミーの移動用タイマークラス
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
		~EnemyTimer();

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

private:
	CharacterID m_Id;
	
	RoomID m_RoomId;
	int	   m_iFrameCount;
	bool   m_IsDeath;
	bool   m_HasKill;
};

#endif