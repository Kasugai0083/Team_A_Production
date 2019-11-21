#ifndef UI_H_
#define UI_H_

#include "UIvalue.h"
#include "../../Texture/Texture.h"
#include "../Object.h"

class UI : public Object {
public:
	
	UI();

	

	void Update()override;
	void Draw()override;
	bool HasOnMouse()override;

protected:
	Texture* m_Tex;
	bool m_OnMouse;
	Vec2 m_Pos;
	Size m_Size;
};

#endif