#pragma once

#include "../Utility/Vec.h"
#include "../Utility/Size.h"
#include "../Texture/Texture.h"
#include "ObjectID.h"

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
	virtual void InitCount() {};

	virtual void Update() {};

	virtual bool HasOnMouse() = 0;
	
	virtual void Draw() {};

	virtual void SetCandller(Candller* candller_) { return; };
	virtual void SetCount(int* count_) { return; };
	virtual void SetPosition(Vec2 pos_) {};
	virtual bool HasLight(CandleLight cl_) { return 0; };

	virtual Vec2 GetPos() { return m_Pos; };
	virtual float GetHp() { return 0; };
	virtual float GetRatio() { return 0; };
	virtual bool HasCaLight() { return 0; };

	virtual bool HasMask() { return 0; };
protected:

	bool m_IsDeath;
	ObjID m_Id;

private:
	Candller* m_Candller;
	Vec2 m_Pos;
};
