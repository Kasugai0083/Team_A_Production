#pragma once
#include "Object.h"

//キャラクタークラスの管理


class ObjectManager {

public:

	ObjectManager();
	~ObjectManager();

	void Init();
	void Init(object::ObjectId id_, Vec2 pos_);

	void Update();
	void Update(object::ObjectId id_);

	Object* GetObj(int id_) {
		return m_pObjects[id_];
	}

	void Draw(object::ObjectId id_);

	bool HasOnMouse(object::ObjectId id_);

private:
	void Release();

	Object* m_pObjects[object::MAX_OBJECT_NUM];
};

ObjectManager* ObjManager();

