#pragma once

#include "../Item.h"
#include "../../../Scene/Scene.h"
#include "Candle.h"
#include "../../ObjectManager.h"

enum class FireID {
	CENTER_FIRE,
	RIGHT_FIRE,
	LEFT_FIRE,
};

class Fire : public Item {
public:
	Fire(FireID id_) {
		m_Id = id_;
	}
	void Init()override {
		switch (m_Id)
		{
		case FireID::CENTER_FIRE:
			LoadTexture("Res/Game/Item/Candle_Fire.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireSmallTex);
			m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireSmallTex);

			if (m_pTex == nullptr) {
				return;
			}

			m_Pos = FIRE_SMALL_POS;
			m_Size = FIRE_SMALL_SIZE;
			m_Frame = FIRE_SMALL_FRAME;
			m_pObject = ObjManager()->GetObj(object::CANDLE_CENTER);
			break;
		case FireID::RIGHT_FIRE:
			LoadTexture("Res/Game/Item/Candle_Fire_Right_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);
			m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);

			if (m_pTex == nullptr) {
				return;
			}

			m_Pos = FIRE_BIG_POS;
			m_Size = FIRE_BIG_SIZE;
			m_Frame = FIRE_BIG_FRAME;
			m_pObject = ObjManager()->GetObj(object::CANDLE_RIGHT);

			break;
		case FireID::LEFT_FIRE:
			LoadTexture("Res/Game/Item/Candle_Fire_Right_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);
			m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);

			if (m_pTex == nullptr) {
				return;
			}

			m_Pos = FIRE_BIG_POS;
			m_Size = FIRE_BIG_SIZE;
			m_Frame = FIRE_BIG_FRAME;
			m_pObject = ObjManager()->GetObj(object::CANDLE_LEFT);

			break;
		default:
			break;
		}

	};
	void Init(Vec2 pos_) override {
		Init();
		m_Pos = pos_;

	}
	void Update() {

		float HeightRatio = 0.0f;

		switch (m_Id)
		{
		case FireID::CENTER_FIRE:
			if (ObjManager()->HasLight(CandleLight::CENTER_LIGHT) == true) {

			
				if (m_pObject->GetRatio() != NULL) {
					HeightRatio = m_pObject->GetRatio();
				}

				m_Pos.Y += HeightRatio;
			}
			break;
		case FireID::RIGHT_FIRE:
			if (ObjManager()->HasLight(CandleLight::RIGHT_LIGHT) == true) {
				if (m_pObject->GetRatio() != NULL) {
					HeightRatio = m_pObject->GetRatio();
				}

				m_Pos.Y += HeightRatio;
			}
			break;
		case FireID::LEFT_FIRE:
			if (ObjManager()->HasLight(CandleLight::LEFT_LIGHT) == true) {
				if (m_pObject->GetRatio() != NULL) {
					HeightRatio = m_pObject->GetRatio();
				}

				m_Pos.Y += HeightRatio;
			}
			break;
		default:
			break;
		}

		if (HasRectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
			m_OnMouse = true;
		}
		else {
			m_OnMouse = false;
		}
	}

	void Draw() {

		DrawTexture(m_Pos.X, m_Pos.Y, m_pTex);

		Lib::Texture polygon("hoge");

		if (m_OnMouse == true) {
			DrawAlphaBox2D(polygon, m_Pos, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
		}

	}
private:
	FireID m_Id;
	Object* m_pObject;
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

