#include "UI.h"
#include "../../Engine/Input.h"
#include "../../Engine/Calculation.h"
#include "../../Texture/Texture.h"
#include "../../Engine/Graphics.h"
#include "../ObjectManager.h"


Object* g_TitleLogo;

UI::UI() {
		m_Pos = {0.f, 0.f};
		m_Size = {0.f, 0.f};
		m_OnMouse = false;
}

void UI::Draw(){

	DrawTexture(m_Pos.X, m_Pos.Y, m_Tex);

	Lib::Texture polygon("hoge");

	if (m_OnMouse == true) {
		DrawAlphaBox2D(polygon, m_Pos, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
	}
		
}

void UI::Update() {
	if (RectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
		m_OnMouse = true;
	}
	else {
		m_OnMouse = false;
	}
}

bool UI::HasOnMouse() {
	return m_OnMouse;
}