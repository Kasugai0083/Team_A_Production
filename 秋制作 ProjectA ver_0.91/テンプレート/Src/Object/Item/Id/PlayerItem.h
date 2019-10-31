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
	void Init(Vec2 pos_) override {
		m_Pos = pos_;
		m_Size = CRYSTAL_SIZE;
		LoadTexture("Res/Game/Item/Crystal.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCrystalTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCrystalTex);
	}


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
	void Init(Vec2 pos_) override {
		m_Pos = pos_;
		m_Size = MUSICBOX_SIZE;
		LoadTexture("Res/Game/Item/MusicBox.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMusicBoxTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMusicBoxTex);
	}

private:

};

