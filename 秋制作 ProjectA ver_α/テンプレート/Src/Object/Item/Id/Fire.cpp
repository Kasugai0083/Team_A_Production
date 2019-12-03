#include "Fire.h"

void Fire::Init() {
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

void Fire::Init(Vec2 pos_) {
	Init();
	m_Pos = pos_;
}

void Fire::Update() {
	float HeightRatio = 0.f;

	switch (m_Id)
	{
	case FireID::CENTER_FIRE:
		if (ObjManager()->HasLight(CandleLight::CENTER_LIGHT) == true) {

			if (m_pObject->GetRatio() != NULL) {
				HeightRatio = m_pObject->GetRatio();
			}

			m_Pos.Y = FIRE_SMALL_POS.Y + HeightRatio;
		}
		break;
	case FireID::RIGHT_FIRE:
		if (ObjManager()->HasLight(CandleLight::RIGHT_LIGHT) == true) {
			if (m_pObject->GetRatio() != NULL) {
				HeightRatio = m_pObject->GetRatio();
			}

			m_Pos.Y = FIRE_BIG_POS.Y + HeightRatio;

		}
		break;
	case FireID::LEFT_FIRE:
		if (ObjManager()->HasLight(CandleLight::LEFT_LIGHT) == true) {
			if (m_pObject->GetRatio() != NULL) {
				HeightRatio = m_pObject->GetRatio();
			}
			m_Pos.Y = FIRE_BIG_POS.Y + HeightRatio;

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

void Fire::Draw() {
	DrawTexture(m_Pos.X, m_Pos.Y, m_pTex);

	Lib::Texture polygon("hoge");

	if (m_OnMouse == true) {
		DrawAlphaBox2D(polygon, m_Pos, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
	}

}