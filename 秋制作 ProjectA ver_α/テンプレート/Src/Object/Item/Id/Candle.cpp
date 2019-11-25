#include "Candle.h"

Candller Candle::m_Candller = {false, false , false};

void Candle::Init(object::ObjectId id_) {
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

void Candle::Init(object::ObjectId id_, Vec2 pos_) {
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


//void Candle::SetCandller(Candller* candller_){
//	m_Candller = candller_;
//}
void Candle::SetCount(int* count_){
	m_Count = count_;
}

void Candle::Update(){

	if (HasRectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
		m_OnMouse = true;
		if (OnMouseDown(Left) == true) {


			switch (GameView()->CurrentViewID())
			{
			case GameData::CENTER:
				if (m_Candller.CenterCaLight == false) {
					if (*m_Count == 0) {
						m_Candller.CenterCaLight = true;
						*m_Count += 1;
					}
				}
				else {
					if (*m_Count == 0) {
						m_Candller.CenterCaLight = false;
						*m_Count += 1;
					}
				}
				break;
			case GameData::RIGHT:
				if (m_Candller.RightCaLight == false) {
					if (*m_Count == 0) {
						m_Candller.RightCaLight = true;
						*m_Count += 1;
					}
				}
				else {
					if (*m_Count == 0) {
						m_Candller.RightCaLight = false;
						*m_Count += 1;
					}
				}
				break;
			case GameData::LEFT:
				if (m_Candller.LeftCaLight == false) {
					if (*m_Count == 0) {
						m_Candller.LeftCaLight = true;
						*m_Count += 1;
					}
				}
				else {
					if (*m_Count == 0) {
						m_Candller.LeftCaLight = false;
						*m_Count += 1;
					}
				}
				break;
			}
		}
	}
	else {
		m_OnMouse = false;
	}

}

void Candle::Draw(){

	DrawTexture(m_Pos.X, m_Pos.Y, m_pTex);

	Lib::Texture polygon("hoge");

	if (m_OnMouse == true) {
		DrawAlphaBox2D(polygon, m_Pos, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
	}

}

bool Candle::HasLight(CandleLight cl_) {
	switch (cl_)
	{
	case CandleLight::CENTER_LIGHT:
		return m_Candller.CenterCaLight;
		break;
	case CandleLight::RIGHT_LIGHT:
		return m_Candller.RightCaLight;
		break;
	case CandleLight::LEFT_LIGHT:
		return m_Candller.LeftCaLight;
		break;
	default:
		break;
	}
}
