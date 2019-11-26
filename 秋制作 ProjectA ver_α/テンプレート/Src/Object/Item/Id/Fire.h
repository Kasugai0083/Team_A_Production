#pragma once

#include "../Item.h"
#include "../../../Scene/Scene.h"


class FireBig : public Item {
public:

	void Init()override {
		LoadTexture("Res/Game/Item/Candle_Fire_Right_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = FIRE_BIG_POS;
		m_Size = FIRE_BIG_SIZE;

	};
	void Init(Vec2 pos_) override {
		LoadTexture("Res/Game/Item/Candle_Fire_Right_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = pos_;
		m_Size = FIRE_BIG_SIZE;
	}


private:

};

class FireSmall : public Item {
public:

	void Init()override {
		LoadTexture("Res/Game/Item/Candle_Fire.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireSmallTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireSmallTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = FIRE_SMALL_POS;
		m_Size = FIRE_SMALL_SIZE;

	};
	void Init(Vec2 pos_) override {
		LoadTexture("Res/Game/Item/Candle_Fire.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireSmallTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireSmallTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = pos_;
		m_Size = FIRE_SMALL_SIZE;
	}


private:

};

