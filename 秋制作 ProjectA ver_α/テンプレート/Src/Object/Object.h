#pragma once

#include "../Utility/Vec.h"
#include "../Utility/Size.h"
#include "../Texture/Texture.h"
#include "ObjectID.h"
#include "UI/UIID.h"

struct Candller {
	bool CenterCaLight;
	bool RightCaLight;
	bool LeftCaLight;
};

enum class CandleLight {
	CENTER_LIGHT,
	RIGHT_LIGHT,
	LEFT_LIGHT,
};

class Object {
public:

	Object() {};
	~Object() {};

	virtual void Init() {};
	virtual void Init(Vec2 pos_) {};
	virtual void Init(object::ObjectId id_) {};
	virtual void Init(object::ObjectId id_,Vec2 pos_) {};

	virtual void InitCount() {};

	virtual void Update() {};

	virtual bool HasOnMouse() = 0;
	
	virtual void Draw() {};
	virtual void Draw(Vec2 pos_) {};

	virtual void SetCandller(Candller* candller_) { return; };
	virtual void SetCount(int* count_) { return; };
	virtual void SetPosition(Vec2 pos_) {};
	virtual bool HasLight(CandleLight cl_) { return 0; };

	virtual Vec2 GetPos() { return m_Pos; };
	virtual float GetHp() { return 0; };
	virtual float GetRatio() { return 0; };
protected:

	bool m_IsDeath;

private:
	Candller* m_Candller;
	Vec2 m_Pos;
};
