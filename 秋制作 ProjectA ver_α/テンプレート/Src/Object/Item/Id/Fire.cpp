#include "Fire.h"

void Fire::Init() {
	switch (m_Id)
	{
	case ObjID::FIRE_CENTER:
		LoadTexture("Res/Game/Item/Candle_Fire.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireSmallTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireSmallTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = FIRE_SMALL_POS;
		m_Size = FIRE_SMALL_SIZE;
		m_Frame = FIRE_SMALL_FRAME;
		m_pObject = ObjManager()->GetObj(ObjID::CANDLE_CENTER);
		break;
	case ObjID::FIRE_RIGHT:
		LoadTexture("Res/Game/Item/Candle_Fire_Right_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = FIRE_BIG_POS;
		m_Size = FIRE_BIG_SIZE;
		m_Frame = FIRE_BIG_FRAME;
		m_pObject = ObjManager()->GetObj(ObjID::CANDLE_RIGHT);

		break;
	case ObjID::FIRE_LEFT:
		LoadTexture("Res/Game/Item/Candle_Fire_Right_Left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameFireBigTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = FIRE_BIG_POS;
		m_Size = FIRE_BIG_SIZE;
		m_Frame = FIRE_BIG_FRAME;
		m_pObject = ObjManager()->GetObj(ObjID::CANDLE_LEFT);

		break;
	default:
		break;
	}

};

void Fire::FireSwitch(bool center_switch_, bool left_switch_, bool right_switch_) {
		switch (m_Id)
		{
		case ObjID::FIRE_CENTER:
			m_IsDeath = center_switch_;
			break;
		case ObjID::FIRE_LEFT:
			m_IsDeath = left_switch_;
			break;
		case ObjID::FIRE_RIGHT:
			m_IsDeath = right_switch_;
			break;
		}

}

void Fire::SceneDeath() {
	if (GetCurrentSceneId() == GameScene) {
		switch (GameView()->CurrentViewID())
		{
		case GameData::SubGameScene::CENTER:
			FireSwitch(false, true, true);
			break;
		case GameData::SubGameScene::RIGHT:
			FireSwitch(true, true, false);
			break;
		case GameData::SubGameScene::LEFT:
			FireSwitch(true, false, true);
			break;
		}

	}
}

void Fire::Update() {
	float HeightRatio = 0.f;

	SceneDeath();

	if (m_IsDeath == false) {
		switch (m_Id)
		{
		case ObjID::FIRE_CENTER:
			if (m_pObject->HasCaLight() == true) {

				if (m_pObject->GetRatio() != NULL) {
					HeightRatio = m_pObject->GetRatio();
				}

				m_Pos.Y = FIRE_SMALL_POS.Y + HeightRatio;
			}
			break;
		case ObjID::FIRE_RIGHT:
			if (m_pObject->HasCaLight() == true) {
				if (m_pObject->GetRatio() != NULL) {
					HeightRatio = m_pObject->GetRatio();
				}

				m_Pos.Y = FIRE_BIG_POS.Y + HeightRatio;

			}
			break;
		case ObjID::FIRE_LEFT:
			if (m_pObject->HasCaLight() == true) {
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
}

void Fire::Draw() {
	
	if (m_pObject != nullptr) {
		if (m_pObject->HasCaLight() == true && m_IsDeath == false) {
			DrawTexture(m_Pos.X, m_Pos.Y, m_pTex);

			Lib::Texture polygon("hoge");

			if (m_OnMouse == true) {
				DrawAlphaBox2D(polygon, m_Pos, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
			}

		}
	}
}