#include "Item.h"
#include "../../Engine/Input.h"
#include "../../Engine/Calculation.h"
#include "../../Texture/Texture.h"
#include "../../Engine/Graphics.h"


Item::Item() {
	m_Pos = { 0.f, 0.f };
	m_Size = { 0.f, 0.f };
	m_OnMouse = false;
}

void Item::Draw() {

	if(m_IsDeath == false){
		DrawTexture(m_Pos.X, m_Pos.Y, m_pTex);

		Lib::Texture polygon("hoge");

		if (m_OnMouse == true) {
			DrawAlphaBox2D(polygon, m_Pos, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
		}

	}
}

void Item::Update() {

	if (HasRectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
		m_OnMouse = true;
	}
	else {
		m_OnMouse = false;
	}
}
