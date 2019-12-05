#ifndef UI_H_
#define UI_H_

#include "UIvalue.h"
#include "../../Texture/Texture.h"
#include "../Object.h"


class UI : public Object {
public:

	UI() {};
	UI(ObjID id_) {
		m_Id = id_;
		m_HasMask = false;
	};

	void Init()override;

	void Update()override;
	void Draw()override;
	bool HasOnMouse()override;
	bool HasMask()override;

protected:
	Texture* m_Tex;
	bool m_OnMouse;
	Vec2 m_Pos;
	Size m_Size;

private:

	void UpdateGameUI();

	bool m_HasMask;
};

#endif