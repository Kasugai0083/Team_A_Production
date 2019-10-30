#ifndef ITEM_H_
#define ITEM_H_

#include "../../Utility/Vec.h"
#include "../../Utility/Size.h"
#include "../../Texture/Texture.h"
#include "../Object.h"

class Item : public Object {
public:

	Item();
	~Item();

	void Init();
	void Update();
	bool HasOnMouse();

protected:
	Texture* m_Tex;
	bool m_OnMouse;
	Vec2 m_Pos;
	Size m_Size;
	Size m_Frame;
};

#endif