#pragma once

#include "../UI.h"
#include "../../../Scene/Scene.h"


class TitleLogo : public UI {
public:

	void Init()override {

		m_Pos = TITLE_LOGO_POS;
		m_Size = TITLE_LOGO_SIZE;
		LoadTexture("Res/Title/TitleLogo.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleLogoTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleLogoTex);

	};

	void Draw()override {
		DrawTexture(m_Pos.X, m_Pos.Y, m_Tex);
	}

private:

};