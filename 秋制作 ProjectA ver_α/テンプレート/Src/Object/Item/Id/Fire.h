#pragma once

#include "../Item.h"
#include "../../../Scene/Scene.h"
#include "Candle.h"
#include "../../ObjectManager.h"

enum class FireID {
	CENTER_FIRE,
	RIGHT_FIRE,
	LEFT_FIRE,
};

class Fire : public Item {
public:
	Fire(FireID id_) {
		m_Id = id_;
	}
	void Init()override;
	void Init(Vec2 pos_) override;
	void Update()override;

	void Draw()override;

private:
	FireID m_Id;
	Object* m_pObject;
};
