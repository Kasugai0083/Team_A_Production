#pragma once

#include "../Utility/Vec.h"
#include "../Utility/Size.h"
#include "../Texture/Texture.h"
#include "ObjectID.h"


class Object {
public:

	Object() {};
	~Object() {};

	virtual void Init() = 0;
	virtual void Init(Vec2 pos_) {};

	virtual void Update() {};
	virtual bool HasOnMouse() = 0;
	
	virtual void Draw() {};
	virtual void Draw(Vec2 pos_) {};

protected:

};
