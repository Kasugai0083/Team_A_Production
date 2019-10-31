#pragma once

#include "../UI.h"
#include "../../../Scene/Scene.h"


class NewGame : public UI {
public:

	void Init()override {

		m_Pos = NEWGAME_UI_POS;
		m_Size = NEWGAME_UI_SIZE;
		LoadTexture("Res/Title/TitleMenuStart.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleNewGameUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleNewGameUITex);

	};

private:

};