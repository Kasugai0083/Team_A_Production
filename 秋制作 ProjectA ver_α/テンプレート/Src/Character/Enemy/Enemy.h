#ifndef ENEMY_H_
#define ENEMY_H_
#include "../Character.h"
#include "../CharacterID.h"
#include "../../Utility/RoomID.h"
#include "..//..//Scene/Scene.h"


class Enemy : public Character {
public:
	virtual ~Enemy() override{}

	virtual bool HasKill()const override { return m_HasKill; }

	virtual void LoadTex(SceneId id_)override {}

private:
	// エネミーの移動用タイマークラス
	class EnemyTimer
	{
	public:
		EnemyTimer(int time_) {
			m_Time = time_;
		}

		~EnemyTimer();

		void TimeCount();
		

	private:
		int m_Time;
	};

private:
	CharacterID m_Id;
	
	RoomID m_RoomId;
	int	   m_iFrameCount;
	bool   m_IsDeath;
	bool   m_HasKill;
};

#endif