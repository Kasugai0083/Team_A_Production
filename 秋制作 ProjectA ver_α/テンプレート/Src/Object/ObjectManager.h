#pragma once
#include "Object.h"
#include "ObjectID.h"
#include "../Scene/GameScene/GameData.h"
//キャラクタークラスの管理


class ObjectManager {

public:

	ObjectManager();
	~ObjectManager();

	Object* GetObj(ObjID id_) {
		return m_pObjects[static_cast<int>(id_)];
	}

	void Init();

	void Update();

	void Release();
	void Release(int id);

	void Draw();

	bool HasOnMouse(ObjID id_);
	void InitCount();



private:

	Object* m_pObjects[static_cast<int>(ObjID::MAX_OBJECT_NUM)];

};

ObjectManager* ObjManager();

