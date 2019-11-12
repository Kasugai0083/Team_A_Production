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


class Object {
public:

	Object() {};
	~Object() {};

	virtual void Init() {};
	virtual void Init(Vec2 pos_) {};
	virtual void Init(object::ObjectId id_) {};
	virtual void Init(object::ObjectId id_,Vec2 pos_) {};

	virtual void Update() {};
	virtual bool HasOnMouse() = 0;
	
	virtual void Draw() {};
	virtual void Draw(Vec2 pos_) {};

	virtual void SetCandller(Candller* candller_) { return; };
	virtual void SetCount(int* count_) { return; };
protected:

private:
	Candller* m_Candller;
};
