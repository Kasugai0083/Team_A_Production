#ifndef ITEM_H_
#define ITEM_H_

#include "../../Utility/Vec.h"
#include "../../Utility/Size.h"
#include "../../Texture/Texture.h"
#include "../Object.h"
#include "ItemValue.h"


class Item : public Object {
public:

	Item();
	~Item();

	void Draw()override;
	void Update()override;
	bool HasOnMouse()override;
	
	void SetPosition(Vec2 pos_)override;

protected:
	Texture* m_pTex;
	bool m_OnMouse;
	Vec2 m_Pos;
	Size m_Size;
	Size m_Frame;

};

#endif