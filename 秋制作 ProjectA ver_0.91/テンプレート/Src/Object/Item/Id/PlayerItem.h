#pragma once

#include "../Item.h"
#include "../../../Scene/Scene.h"


class Crystal : public Item {
public:

	void Init()override {

		m_Pos = CRYSTAL_POS;
		m_Size = CRYSTAL_SIZE;
		LoadTexture("Res/Game/Item/Crystal.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCrystalTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCrystalTex);

	};

private:

};

class Mask : public Item {
public:

	void Init()override {

		m_Pos = MASK_POS;
		m_Size = MASK_SIZE;
		LoadTexture("Res/Game/Item/Mask.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMaskTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMaskTex);

	};

private:

};

class MusicBox : public Item {
public:

	void Init()override {

		m_Pos = MUSICBOX_POS;
		m_Size = MUSICBOX_SIZE;
		LoadTexture("Res/Game/Item/MusicBox.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMusicBoxTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMusicBoxTex);

	};

private:

};

