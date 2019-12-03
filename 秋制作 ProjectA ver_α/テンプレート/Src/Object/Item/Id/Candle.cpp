#include "Candle.h"

Candller Candle::m_Candller = {false, false, false};
Candller Candle::m_Death = {false, false, false};
int Candle::m_Count = 0;


void Candle::Init() {
	switch (m_Id) {
	case ObjID::CANDLE_LEFT:
		LoadTexture("Res/Game/Item/Candle_Center_Right_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleBigTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleBigTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = CANDLE_BIG_POS;

		m_HeightRatio = (m_Frame.Height - (m_Frame.Height * m_CandleHp));

		m_Pos.Y = CANDLE_BIG_POS.Y + m_HeightRatio;

		m_Size = CANDLE_BIG_SIZE;
		m_Frame = CANDLE_BIG_FRAME;

		break;
	case ObjID::CANDLE_RIGHT:
		LoadTexture("Res/Game/Item/Candle_Center_Right_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleBigTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleBigTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = CANDLE_BIG_POS;

		m_HeightRatio = (m_Frame.Height - (m_Frame.Height * m_CandleHp));

		m_Pos.Y = CANDLE_BIG_POS.Y + m_HeightRatio;


		m_Size = CANDLE_BIG_SIZE;
		m_Frame = CANDLE_BIG_FRAME;

		break;
	case ObjID::CANDLE_CENTER:
		LoadTexture("Res/Game/Item/Candle_Center.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleSmallTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleSmallTex);

		if (m_pTex == nullptr) {
			return;
		}
		m_Pos = CANDLE_SMALL_POS;

		m_HeightRatio = (m_Frame.Height - (m_Frame.Height * m_CandleHp));

		m_Pos.Y = CANDLE_SMALL_POS.Y + m_HeightRatio;

		m_Size = CANDLE_SMALL_SIZE;
		m_Frame = CANDLE_SMALL_FRAME;

		break;
	case ObjID::CANDLE_STAND:
		LoadTexture("Res/Game/Item/Candle_Stand.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleStandTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleStandTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = CANDLE_STAND_POS;
		m_Size = CANDLE_STAND_SIZE;
		m_Frame = CANDLE_STAND_FRAME;

		break;
	case ObjID::CANDLE_EFFECT:
		LoadTexture("Res/Game/Item/Candle_Right_Effect.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleEffectTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCandleEffectTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = BIG_CANDLE_EFFECT_POS;
		m_Size = CANDLE_EFFECT_SIZE;
		m_Frame = CANDLE_EFFECT_FRAME;

		break;
	}
}

void Candle::InitCount() {
	m_Count = 0;
}

void Candle::CandleSwitch(bool center_switch_, bool left_switch_, bool right_switch_) {
	switch (m_Id)
	{
	case ObjID::CANDLE_LEFT:
		m_IsDeath = left_switch_;
		break;
	case ObjID::CANDLE_RIGHT:
		m_IsDeath = right_switch_;
		break;
	case ObjID::CANDLE_CENTER:
		m_IsDeath = center_switch_;
		break;
	}
}

void Candle::SceneDeath() {
	if (GetCurrentSceneId() == GameScene) {

		switch (m_Id)
		{
		case ObjID::CANDLE_EFFECT:
			m_IsDeath = false;
			break;
		case ObjID::CANDLE_STAND:
			m_IsDeath = false;
			break;
		}

		switch (GameView()->CurrentViewID())
		{
		case GameData::SubGameScene::CENTER:
			CandleSwitch(false, true, true);
			break;
		case GameData::SubGameScene::RIGHT:
			CandleSwitch(true, true, false);
			break;
		case GameData::SubGameScene::LEFT:
			CandleSwitch(true, false, true);
			break;
		}
	}
	else {
		m_IsDeath = true;
	}
}



void Candle::MeltCandle(ObjID id_) {

	if (m_HasCaLight == true) {
		switch (m_Id)
		{
		case ObjID::CANDLE_LEFT:
			m_CandleHp -= MELT_RATIO;

			m_HeightRatio = (m_Frame.Height - (m_Frame.Height * m_CandleHp));

			m_Pos.Y = CANDLE_BIG_POS.Y + m_HeightRatio;

			break;
		case ObjID::CANDLE_RIGHT:

			m_CandleHp -= MELT_RATIO;

			m_HeightRatio = (m_Frame.Height - (m_Frame.Height * m_CandleHp));

			m_Pos.Y = CANDLE_BIG_POS.Y + m_HeightRatio;

			break;
		case ObjID::CANDLE_CENTER:
			m_CandleHp -= MELT_RATIO;

			m_HeightRatio = (m_Frame.Height - (m_Frame.Height * m_CandleHp));

			m_Pos.Y = CANDLE_SMALL_POS.Y + m_HeightRatio;

			break;
		}

	}

}

void Candle::Update(){

	SceneDeath();

	if (m_IsDeath == false || m_CandleHp > 0.f) {


		MeltCandle(ObjID::CANDLE_CENTER);
		MeltCandle(ObjID::CANDLE_LEFT);
		MeltCandle(ObjID::CANDLE_RIGHT);

		//if (m_Candller.CenterCaLight == true) {
		//	MeltCandle(ObjID::CANDLE_CENTER);
		//}
		//if (m_Candller.LeftCaLight == true) {
		//	MeltCandle(ObjID::CANDLE_LEFT);
		//}
		//if (m_Candller.RightCaLight == true) {
		//	MeltCandle(ObjID::CANDLE_RIGHT);
		//}

		//if (m_Death.CenterCaLight == true) {
		//	m_Candller.CenterCaLight = false;
		//}
		//if (m_Death.RightCaLight == true) {
		//	m_Candller.RightCaLight = false;
		//}
		//if (m_Death.LeftCaLight == true) {
		//	m_Candller.LeftCaLight = false;
		//}

		if (OnMousePush(Right) == true) {
			switch (GameView()->CurrentViewID())
			{
			case GameData::CENTER:
				if (m_Id == ObjID::CANDLE_CENTER) {
					m_HasCaLight = true;
				}
				break;
			case GameData::RIGHT:
				if (m_Id == ObjID::CANDLE_RIGHT) {
					m_HasCaLight = true;
				}
				break;
			case GameData::LEFT:
				if (m_Id == ObjID::CANDLE_LEFT) {
					m_HasCaLight = true;
				}
				break;
			}
		}
		else {
			m_HasCaLight = false;
		}


		if (HasRectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
			m_OnMouse = true;
		}
		else {
			m_OnMouse = false;
		}
	}
}

void Candle::Draw(){

	if (m_IsDeath == false) {
		switch (m_Id)
		{
		case ObjID::CANDLE_CENTER:
		case ObjID::CANDLE_LEFT:
		case ObjID::CANDLE_RIGHT:
			CandleDraw(m_Pos.X, m_Pos.Y, m_pTex, m_Frame, m_CandleHp);
			break;
		case ObjID::CANDLE_EFFECT:
		case ObjID::CANDLE_STAND:
			DrawTexture(m_Pos.X, m_Pos.Y, m_pTex, m_Frame);
			break;
		default:
			break;
		}


		Lib::Texture polygon("hoge");

		if (m_OnMouse == true) {
			DrawAlphaBox2D(polygon, m_Pos, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
		}

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

Vec2 Candle::GetPos() {
	return m_Pos;
}
float Candle::GetHp() {
	return m_CandleHp;
}
float Candle::GetRatio() {
	return m_HeightRatio;
}