#pragma once

#include "../Item.h"
#include "../../../Scene/Scene.h"
#include "../../../Scene/GameScene/GameData.h"
#include "../../../Engine/Input.h"
#include "../../../Engine/Calculation.h"

enum class CandleType {
	CENTER_CANDLE,
	LEFT_CANDLE,
	RIGHT_CANDLE,
	OTHER
};

const float CANDLE_MELT_BIG = 0.2f;
const float CANDLE_MELT_SMALL = 0.1f;


class Candle : public Item {
public:

	Candle(CandleType type_) {
		m_Type = type_;
		m_Time = 0;
		m_Hp = 100.f;
	};
	void Init()override {};
	void Init(object::ObjectId id_)override;

	void Init(object::ObjectId id_, Vec2 pos_) override;


	bool HasLight(CandleLight cl_)override;

	//void SetCandller(Candller* candller_)override;
	//void SetCount(int* count_)override;

	void InitCount()override;
	void Update()override;

	void Draw() override;


private:

	CandleType m_Type;
	static int m_Count;
	static Candller m_Candller;
	float m_Hp;
	static Candller m_Death;
	int m_Time;

};

class CandleBig : public Item {
public:

	void Init()override {
		LoadTexture("Res/Game/Item/Candle_Center_Right_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleBigTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleBigTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = CANDLE_BIG_POS;
		m_Size = CANDLE_BIG_SIZE;
	};

	void Init(Vec2 pos_) override{
		LoadTexture("Res/Game/Item/Candle_Center_Right_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleBigTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleBigTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = pos_;
		m_Size = CANDLE_BIG_SIZE;
	}

private:

};

class CandleSmall : public Item {
public:

	void Init()override {
		LoadTexture("Res/Game/Item/Candle_Center.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleSmallTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleSmallTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = CANDLE_SMALL_POS;
		m_Size = CANDLE_SMALL_SIZE;

	};
	void Init(Vec2 pos_) override {
		LoadTexture("Res/Game/Item/Candle_Center.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleSmallTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleSmallTex);

		if (m_pTex == nullptr) {
			return;
		}
		
		m_Pos = pos_;
		m_Size = CANDLE_SMALL_SIZE;
	}

private:

};

class CandleStand : public Item {
public:

	void Init()override {
		LoadTexture("Res/Game/Item/Candle_Stand.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleStandTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleStandTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = CANDLE_STAND_POS;
		m_Size = CANDLE_STAND_SIZE;

	};
	void Init(Vec2 pos_) override {
		LoadTexture("Res/Game/Item/Candle_Stand.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleStandTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleStandTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = pos_;
		m_Size = CANDLE_STAND_SIZE;
	}
private:
};

class CandleEffect : public Item {
public:

	void Init()override {
		LoadTexture("Res/Game/Item/Candle_Right_Effect.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleEffectTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleEffectTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = BIG_CANDLE_EFFECT_POS;
		m_Size = CANDLE_EFFECT_SIZE;

	};
	void Init(Vec2 pos_) override {
		LoadTexture("Res/Game/Item/Candle_Right_Effect.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleEffectTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleEffectTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = pos_;
		m_Size = CANDLE_EFFECT_SIZE;
	}
	void Draw(Vec2 pos_)override {

		DrawTexture(pos_.X, pos_.Y, m_pTex);

		Lib::Texture polygon("hoge");

		if (m_OnMouse == true) {
			DrawAlphaBox2D(polygon, pos_, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
		}

	}
private:
};

