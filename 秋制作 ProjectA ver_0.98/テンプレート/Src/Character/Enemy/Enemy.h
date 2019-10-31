#ifndef ENEMY_H_
#define ENEMY_H_
#include "../Character.h"
#include "../CharacterID.h"
#include "../../Utility/RoomID.h"
#include "..//..//Scene/Scene.h"


class Enemy : public Character {
public:
	~Enemy() override{}

	RoomID GetRoomID() {
		return m_RoomId;
	}

	bool HasKill()const override { return m_HasKill; }

	void LoadTex(SceneId id_)override {}

private:
	CharacterID m_Id;
	
	RoomID m_RoomId;
	int	   m_iFrameCount;
	bool   m_IsDeath;
	bool   m_HasKill;
};

#endif