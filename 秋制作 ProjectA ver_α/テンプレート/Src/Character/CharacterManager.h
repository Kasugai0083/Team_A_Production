#ifndef CHARACTERMANAGER_H_
#define CHARACTERMANAGER_H_

#include "Character.h"
#include "CharacterID.h"

//キャラクタークラスの管理
class CharacterManager {

public:

	CharacterManager();
	~CharacterManager();

	void Initialize();

	void Update();

	Character* GetCharacter(int id) {
		return m_Charas[id];
	}

	void Draw();

	void LoadTex(SceneId id);

	bool RefKill();

private:
	void Release();

	Character* m_Charas[8];
};

extern CharacterManager g_Manager;

#endif