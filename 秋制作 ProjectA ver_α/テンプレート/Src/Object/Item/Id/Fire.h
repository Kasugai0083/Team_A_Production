#pragma once

#include "../Item.h"
#include "../../../Scene/Scene.h"


class FireBig : public Item {
public:

	void Init()override {

		m_Pos = FIRE_BIG_POS;
		m_Size = FIRE_BIG_SIZE;
		LoadTexture("Res/Game/Item/Candle_Fire_Right_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);

	};
	void Init(Vec2 pos_) override {
		m_Pos = pos_;
		m_Size = FIRE_BIG_SIZE;
		LoadTexture("Res/Game/Item/Candle_Fire_Right_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);
	}

private:

};

class FireSmall : public Item {
public:

	void Init()override {

		m_Pos = FIRE_SMALL_POS;
		m_Size = FIRE_SMALL_SIZE;
		LoadTexture("Res/Game/Item/Candle_Fire.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireSmallTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireSmallTex);

	};
	void Init(Vec2 pos_) override {
		m_Pos = pos_;
		m_Size = FIRE_SMALL_SIZE;
		LoadTexture("Res/Game/Item/Candle_Fire.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireSmallTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireSmallTex);
	}


private:

};

