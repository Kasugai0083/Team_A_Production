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
	void Update(object::ObjectId id);

	Object* GetObj(int id) {
		return m_Objects[id];
	}

	void Draw(object::ObjectId id);

	bool HasOnMouse(object::ObjectId id);

private:
	void Release();

	Object* m_Objects[object::MAX_OBJECT_NUM];
};

ObjectManager* ObjManager();

