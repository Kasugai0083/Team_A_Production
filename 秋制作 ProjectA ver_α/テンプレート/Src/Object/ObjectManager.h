#pragma once
#include "Object.h"
#include "../Scene/GameScene/GameData.h"
#include "UI/UIID.h"
//キャラクタークラスの管理


class ObjectManager {

public:

	ObjectManager();
	~ObjectManager();

	void Init();
	void Init(object::ObjectId id_, Vec2 pos_);

	void Update();
	void Update(object::ObjectId id_);
	void UpdateUI(UserInterfaceID id_);


	Object* GetObj(int id_) {
		return m_pObjects[id_];
	}

	void DrawUI();
	void Draw(object::ObjectId id_);
	void Draw(object::ObjectId id_, Vec2 pos_);
	void DrawUI(UserInterfaceID id_);

	bool HasOnMouse(object::ObjectId id_);
	bool HasOnMouseUI(UserInterfaceID id_);

	void SetPosition(object::ObjectId id_, Vec2 pos_);

	bool HasLight(CandleLight cl_);
	void InitCount();
	void InitUI();

	void Release();

	void Release(int id);

private:



	Object* m_pObjects[object::MAX_OBJECT_NUM];
	Object* m_pUI[MAX_UI_NUM];
};

ObjectManager* ObjManager();

