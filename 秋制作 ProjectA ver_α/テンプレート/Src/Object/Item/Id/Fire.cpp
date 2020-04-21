#include "Fire.h"
#include "../ItemValue.h"
#include "../../../Character/CharacterManager.h"

void Fire::Init() 
{
	switch (m_Id)
	{
	case ObjID::FIRE_CENTER:
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_FIRE_TEX);

		if (m_pTex == nullptr) 
		{
			return;
		}

		m_Pos = { (960.f - FIRE_SIZE.Width / 2), 632.5f - FIRE_SIZE.Height };
		m_Size = FIRE_SIZE;
		m_Frame = FIRE_FRAME;
		m_pObject = ObjManager()->GetObj(ObjID::CANDLE_CENTER);
		break;
	case ObjID::FIRE_RIGHT:
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_FIRE_SMALL_TEX);

		if (m_pTex == nullptr)
		{
			return;
		}

		m_Pos = FIRE_BIG_RIGHT_POS;
		m_Size = FIRE_SIDE_SIZE;
		m_Frame = FIRE_SIDE_FRAME;
		m_pObject = ObjManager()->GetObj(ObjID::CANDLE_RIGHT);

		break;
	case ObjID::FIRE_LEFT:
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_FIRE_SMALL_TEX);

		if (m_pTex == nullptr)
		{
			return;
		}

		m_Pos = FIRE_BIG_LEFT_POS;
		m_Size = FIRE_SIDE_SIZE;
		m_Frame = FIRE_SIDE_FRAME;
		m_pObject = ObjManager()->GetObj(ObjID::CANDLE_LEFT);

		break;
	default:
		break;
	}

};

void Fire::FireSwitch(bool center_switch_, bool left_switch_, bool right_switch_)
{
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

void Fire::SceneDeath()
{

	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (GetCurrentSceneId() == GameScene)
	{

		switch (pPlayer->CurrentViewID())
		{
		case SubGameScene::CENTER_VIEW:
			FireSwitch(false, true, true);
			break;
		case SubGameScene::RIGHT_VIEW:
			FireSwitch(true, true, false);
			break;
		case SubGameScene::LEFT_VIEW:
			FireSwitch(true, false, true);
			break;
		}

	}
}

void Fire::Update() 
{
	float HeightRatio = 0.f;

	SceneDeath();

	if (m_IsDeath == false) 
	{
		switch (m_Id)
		{
		case ObjID::FIRE_CENTER:

			if (m_pObject->HasCaLight() == true)
			{

				if (m_pObject->GetRatio() != NULL) 
				{
					HeightRatio = m_pObject->GetRatio();
				}

				m_Pos.Y = FIRE_SMALL_POS.Y + HeightRatio;
			}
			break;
		case ObjID::FIRE_RIGHT:
			if (m_pObject->HasCaLight() == true) 
			{
				if (m_pObject->GetRatio() != NULL) 
				{
					HeightRatio = m_pObject->GetRatio();
				}

				m_Pos.Y = FIRE_BIG_RIGHT_POS.Y + HeightRatio;

			}
			break;
		case ObjID::FIRE_LEFT:
			if (m_pObject->HasCaLight() == true) 
			{
				if (m_pObject->GetRatio() != NULL) 
				{
					HeightRatio = m_pObject->GetRatio();
				}
				m_Pos.Y = FIRE_BIG_LEFT_POS.Y + HeightRatio;

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

void Fire::Draw() 
{
	if (m_pObject != nullptr)
	{
		if (m_pObject->HasCaLight() == true && m_IsDeath == false)
		{
			DrawTexture(m_Pos.X, m_Pos.Y, m_pTex, 0.f, 0.99f, 1.f);
		}
	}
}