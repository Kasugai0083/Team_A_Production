#include "Enemy.h"
#include <random>
#include <time.h>

bool Enemy::EnemyTimer::MoveTimer()
{
	m_Time++;

	if (m_Time >= m_MoveSpeed) {
		m_Time = 0;
		return true;
	}

	return false;
}
