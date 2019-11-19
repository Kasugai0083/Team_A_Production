#include "Enemy.h"
#include <random>
#include <time.h>

//Enemy::Enemy()
//{
//	RoomID m_RoomId = RoomID::ROOM_WORK;
//	int	   m_iFrameCount = 0;
//	bool   m_HasKill = false;
//}

Enemy::EnemyTimer::~EnemyTimer()
{
}

unsigned int Enemy::EnemyTimer::GetRand(unsigned int min_val_, unsigned int max_val_)
{
	static std::mt19937_64 mt64((unsigned int)time(NULL));

	std::uniform_int_distribution<unsigned int> get_rand_uni_int(min_val_, max_val_);

	return get_rand_uni_int(mt64);
}

bool Enemy::EnemyTimer::SpawnTimer(Enemy& enemy_)
{
	// 早期リターン
	if (enemy_.m_IsDeath == false) { return false; }

	m_Time++;

	if (m_Time >= m_RandTime) {
		m_Time = 0;
		return true;
	}

	return false;
}

bool Enemy::EnemyTimer::MoveTimer(Enemy& enemy_)
{
	// 早期リターン
	if (enemy_.m_IsDeath == true) { return false; }

	m_Time++;

	if (m_Time >= m_RandTime) {
		m_Time = 0;
		return true;
	}

	return false;
}
