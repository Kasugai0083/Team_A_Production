#include "Candle.h"
#include "..//..//ObjectManager.h"
#include "../ItemValue.h"
#include "../../../Character/CharacterManager.h"
#include "../../../Engine/Audio/Audio.h"
#include "../../../Data/GameData.h"

void Candle::Init() {

	m_CandleHp = 1.f;


	switch (m_Id) {
	case ObjID::CANDLE_LEFT:
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_BIG_TEX);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = CANDLE_BIG_LEFT_POS;

		m_HeightRatio = (m_Frame.Height - (m_Frame.Height * m_CandleHp));

		m_Pos.Y = CANDLE_BIG_LEFT_POS.Y + m_HeightRatio;

		m_Size = CANDLE_BIG_SIZE;
		m_Frame = CANDLE_BIG_FRAME;

		break;
	case ObjID::CANDLE_RIGHT:
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_BIG_TEX);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = { (735.f - CANDLE_BIG_SIZE.Width / 2), (612.5f) };

		m_HeightRatio = (m_Frame.Height - (m_Frame.Height * m_CandleHp));

		m_Pos.Y = (612.5f) + m_HeightRatio;


		m_Size = CANDLE_BIG_SIZE;
		m_Frame = CANDLE_BIG_FRAME;

		break;
	case ObjID::CANDLE_CENTER:

		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_SMALL_TEX);

		if (m_pTex == nullptr) {
			return;
		}
		m_Pos = CANDLE_SMALL_POS;

		m_HeightRatio = (m_Frame.Height - (m_Frame.Height * m_CandleHp));

		m_Pos.Y = CANDLE_SMALL_POS.Y + m_HeightRatio / 2;

		m_Size = CANDLE_SMALL_SIZE;
		m_Frame = CANDLE_SMALL_FRAME;

		break;
	case ObjID::CANDLE_STAND_CENTER:
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_STAND_CENTER_TEX);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = CANDLE_STAND_CENTER_POS;
		m_Size = CANDLE_STAND_CENTER_SIZE;
		m_Frame = CANDLE_STAND_CENTER_FRAME;

		break;
	case ObjID::CANDLE_STAND_RIGHT:
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_STAND_SIDE_TEX);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = {(720.f - (CANDLE_STAND_RIGHT_SIZE.Width / 2)), (930.f - (CANDLE_STAND_RIGHT_SIZE.Height / 2))};
		m_Size = CANDLE_STAND_RIGHT_SIZE;
		m_Frame = CANDLE_STAND_RIGHT_FRAME;

		break;
	case ObjID::CANDLE_STAND_LEFT:
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_STAND_SIDE_TEX);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = CANDLE_STAND_LEFT_POS;
		m_Size = CANDLE_STAND_LEFT_SIZE;
		m_Frame = CANDLE_STAND_LEFT_FRAME;

		break;
	case ObjID::CANDLE_EFFECT_CENTER:
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_CENTER_EFFECT_TEX);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = { 0.0f, 0.0f };
		m_Size = {0.f, 0.f};
		m_Frame = { 2048.f, 2048.f };

		break;
	case ObjID::CANDLE_EFFECT_RIGHT:
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_RIGHT_EFFECT_TEX);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = { 5.0f, 0.0f };
		m_Size = { 0.f, 0.f };
		m_Frame = { 2048.f, 2048.f };

		break;
	case ObjID::CANDLE_EFFECT_LEFT:
		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_LEFT_EFFECT_TEX);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = { 128.0f, 0.0f };
		m_Size = { 0.f, 0.f };
		m_Frame = { 2048.f, 2048.f };

		break;
	}
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

	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (pPlayer == nullptr) {
		return;
	}

	if (pPlayer->HasMonitor() == false) {

		if (GetCurrentSceneId() == GameScene) {

			switch (pPlayer->CurrentViewID())
			{
			case SubGameScene::CENTER_VIEW:
				if (m_Id == ObjID::CANDLE_STAND_CENTER) {
					m_IsDeath = false;
				}
				else if (m_Id == ObjID::CANDLE_STAND_LEFT || m_Id == ObjID::CANDLE_STAND_RIGHT) {
					m_IsDeath = true;
				}
				CandleSwitch(false, true, true);
				break;
			case SubGameScene::RIGHT_VIEW:
				if (m_Id == ObjID::CANDLE_STAND_RIGHT) {
					m_IsDeath = false;
				}
				else if (m_Id == ObjID::CANDLE_STAND_CENTER || m_Id == ObjID::CANDLE_STAND_LEFT) {
					m_IsDeath = true;
				}
				CandleSwitch(true, true, false);
				break;
			case SubGameScene::LEFT_VIEW:
				if (m_Id == ObjID::CANDLE_STAND_LEFT) {
					m_IsDeath = false;
				}
				else if (m_Id == ObjID::CANDLE_STAND_CENTER || m_Id == ObjID::CANDLE_STAND_RIGHT) {
					m_IsDeath = true;
				}
				CandleSwitch(true, false, true);
				break;
			}
		}
		else {
			m_IsDeath = true;
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
			m_CandleHp -= GameData::GetInstance()->GetGameParam().m_MeltRatio;

			m_HeightRatio = (m_Size.Height - (m_Size.Height * m_CandleHp));

			m_Pos.Y = CANDLE_BIG_LEFT_POS.Y + m_HeightRatio;

			break;
		case ObjID::CANDLE_RIGHT:

			m_CandleHp -= GameData::GetInstance()->GetGameParam().m_MeltRatio;

			m_HeightRatio = (m_Size.Height - (m_Size.Height * m_CandleHp));

			m_Pos.Y = CANDLE_BIG_RIGHT_POS.Y + m_HeightRatio;

			break;
		case ObjID::CANDLE_CENTER:

			m_CandleHp -= GameData::GetInstance()->GetGameParam().m_MeltRatio;

			m_HeightRatio = (m_Size.Height - (m_Size.Height * m_CandleHp));

			m_Pos.Y = CANDLE_SMALL_POS.Y + m_HeightRatio;

			break;
		}

	}

}

void Candle::EffectUpdate() {
	Object* CenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);
	Object* LeftCandle = ObjManager()->GetObj(ObjID::CANDLE_LEFT);
	Object* RightCandle = ObjManager()->GetObj(ObjID::CANDLE_RIGHT);

	if (CenterCandle->HasCaLight() == true) {
		if (m_Id == ObjID::CANDLE_EFFECT_CENTER) {
			m_IsDeath = false;
		}
	}
	else {
		if (m_Id == ObjID::CANDLE_EFFECT_CENTER) {
			m_IsDeath = true;
		}
	}

	if (LeftCandle->HasCaLight() == true) {
		if (m_Id == ObjID::CANDLE_EFFECT_LEFT) {
			m_IsDeath = false;
		}
	}
	else {
		if (m_Id == ObjID::CANDLE_EFFECT_LEFT) {
			m_IsDeath = true;
		}
	}

	if (RightCandle->HasCaLight() == true) {
		if (m_Id == ObjID::CANDLE_EFFECT_RIGHT) {
			m_IsDeath = false;
		}
	}
	else {
		if (m_Id == ObjID::CANDLE_EFFECT_RIGHT) {
			m_IsDeath = true;
		}
	}
}

void Candle::Update(){

	Character* pPlayer = g_Manager.GetCharacter(PLAYER);



	SceneDeath();

	EffectUpdate();

	switch (m_Id)
	{
	case ObjID::CANDLE_CENTER:
		if (GetKeyDown(UP_KEY) == true) {
			m_IsDeath = false;
			m_CandleHp = 1.f;

			m_HeightRatio = (m_Size.Height - (m_Size.Height * m_CandleHp));

			m_Pos.Y = CANDLE_SMALL_POS.Y + m_HeightRatio;
		}
		break;
	default:
		break;
	}

	if (m_IsDeath == false && m_CandleHp > 0.f && pPlayer->HasMask() == false) {


		MeltCandle(ObjID::CANDLE_CENTER);
		MeltCandle(ObjID::CANDLE_LEFT);
		MeltCandle(ObjID::CANDLE_RIGHT);

		auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());

		static bool Once = false;

		if (OnMousePush(Right) == true) {
			switch (pPlayer->CurrentViewID())
			{
			case SubGameScene::CENTER_VIEW:
				if (!Once)
				{
					pAudio->Play("RousokuSE");
					Once = true;
				}
				if (m_Id == ObjID::CANDLE_CENTER) {
					m_HasCaLight = true;
				}

				break;
			case SubGameScene::RIGHT_VIEW:
				if (!Once)
				{
					pAudio->Play("RousokuSE");
					Once = true;
				}
				if (m_Id == ObjID::CANDLE_RIGHT) {
					m_HasCaLight = true;
				}

				break;
			case SubGameScene::LEFT_VIEW:
				if (!Once)
				{
					pAudio->Play("RousokuSE");
					Once = true;
				}
				if (m_Id == ObjID::CANDLE_LEFT) {
					m_HasCaLight = true;
				}
				break;
			}
		}
		else {
			m_HasCaLight = false;
			Once = false;
		}


		if (HasRectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
			m_OnMouse = true;
		}
		else {
			m_OnMouse = false;
		}
	}
	else {
		m_HasCaLight = false;
	}
}

void Candle::Draw(){

	Size test = m_Frame;

	test.Height *= m_CandleHp;

	if (m_IsDeath == false) {
		switch (m_Id)
		{
		case ObjID::CANDLE_CENTER:
			CandleDraw(m_Pos.X, m_Pos.Y, m_pTex, m_Size, m_Frame, m_CandleHp);
			break;
		case ObjID::CANDLE_LEFT:
		case ObjID::CANDLE_RIGHT:
			CandleDraw(m_Pos.X, m_Pos.Y, m_pTex, m_Frame, m_CandleHp);
			break;
		case ObjID::CANDLE_EFFECT_CENTER:
		case ObjID::CANDLE_EFFECT_LEFT:
		case ObjID::CANDLE_EFFECT_RIGHT:
		case ObjID::CANDLE_STAND_CENTER:
		case ObjID::CANDLE_STAND_LEFT:
		case ObjID::CANDLE_STAND_RIGHT:
			DrawTexture(m_Pos.X, m_Pos.Y, m_pTex, m_Frame);
			break;
		default:
			break;
		}
	}
}
