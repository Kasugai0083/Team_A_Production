#ifndef ENEMY_H_
#define ENEMY_H_
#include "../Character.h"
#include "../CharacterID.h"
#include "../../Utility/RoomID.h"
#include "..//..//Scene/Scene.h"

class Enemy : public Character {

public:
	
	Enemy(CharacterID id_) { m_Id = id_; }

	~Enemy() override{}

	void Init()override;

	void Update()override;

	RoomID GetRoomID() {
		return m_RoomId;
	}

	bool GetIsKill()override { return m_IsPlayerKill; }

	void Draw()override;
	void LoadTex(SceneId id)override;

private:

	int m_FrameCount;
	CharacterID m_Id;
	bool m_IsDeath;	
	bool m_IsPlayerKill;
	RoomID m_RoomId;
};

#endif