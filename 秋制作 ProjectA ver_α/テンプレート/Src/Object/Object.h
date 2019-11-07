#pragma once

#include "../Utility/Vec.h"
#include "../Utility/Size.h"
#include "../Texture/Texture.h"
#include "ObjectID.h"


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

	virtual bool HasCenterCaLight() { return 0; };
	virtual bool HasRightCaLight() { return 0; };
	virtual bool HasLeftCaLight() { return 0; };

protected:

};
