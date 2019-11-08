#pragma once

#include "../Item.h"
#include "../../../Scene/Scene.h"
#include "../../../Scene/GameScene/GameData.h"
#include "../../../Engine/Input.h"
#include "../../../Engine/Calculation.h"

struct Candller {
	 bool CenterCaLight;
	 bool RightCaLight;
	 bool LeftCaLight;
};

class Candle : public Item {
public:

	Candle() {
		CenterCaLight = false;
		LeftCaLight = false;
		RightCaLight = false;
	};
	void Init()override {};
	void Init(object::ObjectId id_)override{
		switch (id_) {
		case object::CANDLE_BIG:
			LoadTexture("Res/Game/Item/Candle_Center_Right_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleBigTex);
			m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleBigTex);

			if (m_pTex == nullptr) {
				return;
			}

			m_Pos = CANDLE_BIG_POS;
			m_Size = CANDLE_BIG_SIZE;
			break;
		case object::CANDLE_SMALL:
			LoadTexture("Res/Game/Item/Candle_Center.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleSmallTex);
			m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleSmallTex);

			if (m_pTex == nullptr) {
				return;
			}

			m_Pos = CANDLE_SMALL_POS;
			m_Size = CANDLE_SMALL_SIZE;
			break;
		case object::CANDLE_STAND:
			LoadTexture("Res/Game/Item/Candle_Stand.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleStandTex);
			m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleStandTex);

			if (m_pTex == nullptr) {
				return;
			}

			m_Pos = CANDLE_STAND_POS;
			m_Size = CANDLE_STAND_SIZE;
			break;
		case object::CANDLE_EFFECT:
			LoadTexture("Res/Game/Item/Candle_Right_Effect.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleEffectTex);
			m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleEffectTex);

			if (m_pTex == nullptr) {
				return;
			}

			m_Pos = CANDLE_EFFECT_POS;
			m_Size = CANDLE_EFFECT_SIZE;
			break;
		}
	}

	void Init(object::ObjectId id_, Vec2 pos_) override {
		switch (id_) {
		case object::CANDLE_BIG:
			LoadTexture("Res/Game/Item/Candle_Center_Right_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleBigTex);
			m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleBigTex);

			if (m_pTex == nullptr) {
				return;
			}

			m_Pos = pos_;
			m_Size = CANDLE_BIG_SIZE;
			break;
		case object::CANDLE_SMALL:
			LoadTexture("Res/Game/Item/Candle_Center.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleSmallTex);
			m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleSmallTex);

			if (m_pTex == nullptr) {
				return;
			}

			m_Pos = pos_;
			m_Size = CANDLE_SMALL_SIZE;
			break;
		case object::CANDLE_STAND:
			LoadTexture("Res/Game/Item/Candle_Stand.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleStandTex);
			m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleStandTex);

			if (m_pTex == nullptr) {
				return;
			}

			m_Pos = pos_;
			m_Size = CANDLE_STAND_SIZE;
			break;
		case object::CANDLE_EFFECT:
			LoadTexture("Res/Game/Item/Candle_Right_Effect.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleEffectTex);
			m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleEffectTex);

			if (m_pTex == nullptr) {
				return;
			}

			m_Pos = pos_;
			m_Size = CANDLE_EFFECT_SIZE;
			break;
		}
	}



	void Update()override {

		if (HasRectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
			m_OnMouse = true;
			if (OnMouseDown(Left) == true) {
				switch (PepshiMan()->CurrentViewID()) 
				{
					case GameData::CENTER:
						if (CenterCaLight == false) {
							CenterCaLight = true;
						}
						else {
							CenterCaLight = false;
						}
					break;
					case GameData::RIGHT:
						if (RightCaLight == false) {
							RightCaLight = true;
						}
						else {
							RightCaLight = false;
						}
					break;
					case GameData::LEFT:
						if (LeftCaLight == false) {
							LeftCaLight = true;
						}
						else {
							LeftCaLight = false;
						}				
						break;
				}
			}
		}
		else {
			m_OnMouse = false;
		}

	}

	bool* HasCenterCaLight()override{
		m_HasCenterCaLight = &CenterCaLight;
		return m_HasCenterCaLight;
	}
	bool* HasRightCaLight()override{
		m_HasRightCaLight = &RightCaLight;
		return m_HasRightCaLight;
	}
	bool* HasLeftCaLight()override{
		m_HasLeftCaLight = &LeftCaLight;
		return m_HasLeftCaLight;
	}

private:


	bool* m_HasCenterCaLight;
	bool* m_HasRightCaLight;
	bool* m_HasLeftCaLight;

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

		m_Pos = CANDLE_EFFECT_POS;
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

