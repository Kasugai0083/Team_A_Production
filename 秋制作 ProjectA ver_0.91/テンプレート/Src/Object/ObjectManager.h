#pragma once
#include "Object.h"

//キャラクタークラスの管理


class ObjectManager {

public:

	ObjectManager();
	~ObjectManager();

	void Init();

	void Update();

	Object* GetObj(int id) {
		return m_Objects[id];
	}

	void Draw(object::UserInterfaceId id);

	bool HasOnMouse(object::UserInterfaceId id);

private:
	void Release();

	Object* m_Objects[object::MAX_UI_NUM];
};

ObjectManager* UIManager();

