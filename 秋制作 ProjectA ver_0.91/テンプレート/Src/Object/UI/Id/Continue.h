#pragma once

#include "../UI.h"
#include "../../../Scene/Scene.h"


class Continue : public UI {
public:

	void Init()override {

		m_Pos = CONTINUE_UI_POS;
		m_Size = CONTINUE_UI_SIZE;
		LoadTexture("Res/Title/TitleMenuHelp.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleContinueUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleContinueUITex);

	};

private:

};