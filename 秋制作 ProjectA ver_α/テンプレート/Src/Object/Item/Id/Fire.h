#pragma once

#include "../Item.h"
#include "../../../Scene/Scene.h"
#include "Candle.h"
#include "../../ObjectManager.h"

class Fire : public Item {
public:
	Fire(ObjID id_) {
		m_Id = id_;
		m_IsDeath = true;
	}
	void Init()override;
	void Update()override;

	void Draw()override;

private:
	void SceneDeath();
	void FireSwitch(bool center_switch_, bool left_switch_, bool right_switch_);

	Object* m_pObject;
};
