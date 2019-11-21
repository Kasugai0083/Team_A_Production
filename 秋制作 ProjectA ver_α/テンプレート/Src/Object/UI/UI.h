#ifndef UI_H_
#define UI_H_

#include "UIvalue.h"
#include "../../Texture/Texture.h"
#include "../Object.h"


class UI : public Object {
public:

	UI() {};
	UI(UIType type_, UserInterfaceID id_) {
		m_Type = type_;
		m_ID = id_;
	};

	void Init()override;

	void Update()override;
	void Draw()override;
	bool HasOnMouse()override;

protected:
	Texture* m_Tex;
	bool m_OnMouse;
	Vec2 m_Pos;
	Size m_Size;

private:

	UIType m_Type;
	UserInterfaceID m_ID;

};

#endif