#include "UI.h"
#include "../../Engine/Input.h"
#include "../../Engine/Calculation.h"
#include "../../Texture/Texture.h"
#include "../../Engine/Graphics.h"
#include "../ObjectManager.h"
#include "..//..//Character/CharacterManager.h"

Object* g_pTitleLogo;


void UI::Init(){

	m_IsDeath = true;

	switch (m_Id) {
	case ObjID::TITLE_LOGO:
		m_Pos = TITLE_LOGO_POS;
		m_Size = TITLE_LOGO_SIZE;
		LoadTexture("Res/Title/TitleLogo.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleLogoTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleLogoTex);
		break;
	case ObjID::BUTTON_NEW_GAME:
		m_Pos = NEWGAME_UI_POS;
		m_Size = NEWGAME_UI_SIZE;
		LoadTexture("Res/Title/TitleMenuStart.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleNewGameUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleNewGameUITex);
		break;
	case ObjID::BUTTON_CONTINUE:
		m_Pos = CONTINUE_UI_POS;
		m_Size = CONTINUE_UI_SIZE;
		LoadTexture("Res/Title/TitleMenuHelp.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleContinueUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleContinueUITex);		
		break;	
	case ObjID::GAME_BASE_UI:
		m_Pos = GAME_BASE_UI_POS;
		m_Size = GAME_BASE_UI_SIZE;
		LoadTexture("Res/Game/UI/base_ui_bar.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMainUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMainUITex);
		break;
	case ObjID::BUTTON_CONTROL_UI:
		m_Pos = GAME_CONTROL_UI_POS;
		m_Size = GAME_CONTROL_UI_SIZE;
		LoadTexture("Res/Game/UI/control_ui_bar.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameControlUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameControlUITex);
		break;
	case ObjID::BUTTON_ON_CONTROL_UI:
		m_Pos = GAME_CONTROL_UI_POS;
		m_Size = GAME_CONTROL_UI_SIZE;
		LoadTexture("Res/Game/UI/onhit_control_ui_bar.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameOnHitControlUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameOnHitControlUITex);
		break;
	case ObjID::MO_MASK_UI:
		m_Pos = GAME_MASK_UI_POS;
		m_Size = GAME_MASK_UI_SIZE;
		LoadTexture("Res/Game/UI/mask_ui_bar.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMaskUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMaskUITex);
		break;
	case ObjID::DESCRIPTION_UI:
		m_Pos = GAME_DESCRIPTION_UI_POS;
		m_Size = GAME_DESCRIPTION_UI_SIZE;
		LoadTexture("Res/Game/UI/control_ui_main.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameDescriptionUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameDescriptionUITex);
		break;
	case ObjID::BUTTON_WORKSHOP:
		m_Pos = WORKSHOP_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/button_1.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom1Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom1Tex);
		break;
	case ObjID::BUTTON_STORE_ROOM:
		m_Pos = STORE_ROOM_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/button_2.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom2Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom2Tex);
		break;
	case ObjID::BUTTON_RECEPTION_ROOM:
		m_Pos = RECEPTION_ROOM_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/button_3.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom3Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom3Tex);
		break;
	case ObjID::BUTTON_CHILD_ROOM:
		m_Pos = CHILD_ROOM_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/button_4.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom4Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom4Tex);
		break;
	case ObjID::BUTTON_RIGHT_CORRIDOR:
		m_Pos = RIGHT_CORRIDOR_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/button_5.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom5Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom5Tex);
		break;
	case ObjID::BUTTON_LEFT_CORRIDOR:
		m_Pos = LEFT_CORRIDOR_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/button_6.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom6Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom6Tex);
		break;
	case ObjID::BUTTON_ON_WORKSHOP:
		m_Pos = WORKSHOP_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/on_button_1.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom1Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom1Tex);
		break;
	case ObjID::BUTTON_ON_STORE_ROOM:
		m_Pos = STORE_ROOM_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/on_button_2.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom2Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom2Tex);
		break;
	case ObjID::BUTTON_ON_RECEPTION_ROOM:
		m_Pos = RECEPTION_ROOM_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/on_button_3.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom3Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom3Tex);
		break;
	case ObjID::BUTTON_ON_CHILD_ROOM:
		m_Pos = CHILD_ROOM_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/on_button_4.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom4Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom4Tex);
		break;
	case ObjID::BUTTON_ON_RIGHT_CORRIDOR:
		m_Pos = RIGHT_CORRIDOR_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/on_button_5.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom5Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom5Tex);
		break;
	case ObjID::BUTTON_ON_LEFT_CORRIDOR:
		m_Pos = LEFT_CORRIDOR_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/on_button_6.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom6Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom6Tex);
		break;
	case ObjID::MONITOR_MAP:
		m_Pos = MAP_UI_POS;
		m_Size = {0.f,0.f};
		LoadTexture("Res/Game/Monitor/MonitorUI/map.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorMapTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorMapTex);
		break;	
	}

};

void UI::Draw(){

	if (m_IsDeath == false) {
		DrawTexture(m_Pos.X, m_Pos.Y, m_Tex);

		Lib::Texture polygon("hoge");

		switch (m_Id) {
		case ObjID::BUTTON_NEW_GAME:
			if (m_OnMouse == true) {
				DrawAlphaBox2D(polygon, m_Pos, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
			}
			break;
		case ObjID::BUTTON_CONTINUE:
			if (m_OnMouse == true) {
				DrawAlphaBox2D(polygon, m_Pos, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
			}
			break;
		case ObjID::MO_MASK_UI:
			if (m_OnMouse == true) {
				DrawAlphaBox2D(polygon, m_Pos, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
			}
			break;
		}

	}
		
}

void UI::Update() {

	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (GetCurrentSceneId() == SceneId::TitleScene) {
		switch (m_Id)
		{
		case ObjID::TITLE_LOGO:
		case ObjID::BUTTON_NEW_GAME:
		case ObjID::BUTTON_CONTINUE:
			m_IsDeath = false;
			break;
		default:
			m_IsDeath = true;
			break;
		}
	}
	else if (GetCurrentSceneId() == SceneId::GameScene) {
		if (pPlayer->HasMonitor() == false) {
			switch (m_Id)
			{
			case ObjID::GAME_BASE_UI:
			case ObjID::BUTTON_CONTROL_UI:
			case ObjID::MO_MASK_UI:
				m_IsDeath = false;
				break;
			default:
				m_IsDeath = true;
				break;
			}
		}else {
			switch (m_Id)
			{
			case ObjID::BUTTON_WORKSHOP:
			case ObjID::BUTTON_STORE_ROOM:
			case ObjID::BUTTON_RECEPTION_ROOM:
			case ObjID::BUTTON_CHILD_ROOM:
			case ObjID::BUTTON_RIGHT_CORRIDOR:
			case ObjID::BUTTON_LEFT_CORRIDOR:
			case ObjID::BUTTON_ON_WORKSHOP:
			case ObjID::BUTTON_ON_STORE_ROOM:
			case ObjID::BUTTON_ON_RECEPTION_ROOM:
			case ObjID::BUTTON_ON_CHILD_ROOM:
			case ObjID::BUTTON_ON_RIGHT_CORRIDOR:
			case ObjID::BUTTON_ON_LEFT_CORRIDOR:
			case ObjID::MONITOR_MAP:
				m_IsDeath = false;
				break;
			default:
				m_IsDeath = true;
				break;
			}

			switch (pPlayer->CurrentMonitorID())
			{
			case MonitorView::WORKSHOP_VIEW:

				switch (m_Id)
				{
				case ObjID::BUTTON_ON_STORE_ROOM:
				case ObjID::BUTTON_ON_RECEPTION_ROOM:
				case ObjID::BUTTON_ON_CHILD_ROOM:
				case ObjID::BUTTON_ON_RIGHT_CORRIDOR:
				case ObjID::BUTTON_ON_LEFT_CORRIDOR:
					m_IsDeath = true;
					break;
				default:
					break;
				}
				break;
			case MonitorView::STORE_ROOM_VIEW:
				switch (m_Id)
				{
				case ObjID::BUTTON_ON_WORKSHOP:
				case ObjID::BUTTON_ON_RECEPTION_ROOM:
				case ObjID::BUTTON_ON_CHILD_ROOM:
				case ObjID::BUTTON_ON_RIGHT_CORRIDOR:
				case ObjID::BUTTON_ON_LEFT_CORRIDOR:
					m_IsDeath = true;
					break;
				default:
					break;
				}
				break;
			case MonitorView::RECEPTION_ROOM_VIEW:
				switch (m_Id)
				{
				case ObjID::BUTTON_ON_WORKSHOP:
				case ObjID::BUTTON_ON_STORE_ROOM:
				case ObjID::BUTTON_ON_CHILD_ROOM:
				case ObjID::BUTTON_ON_RIGHT_CORRIDOR:
				case ObjID::BUTTON_ON_LEFT_CORRIDOR:
					m_IsDeath = true;
				default:
					break;
				}
				break;
			case MonitorView::CHILD_ROOM_VIEW:
				switch (m_Id)
				{
				case ObjID::BUTTON_ON_WORKSHOP:
				case ObjID::BUTTON_ON_STORE_ROOM:
				case ObjID::BUTTON_ON_RECEPTION_ROOM:
				case ObjID::BUTTON_ON_RIGHT_CORRIDOR:
				case ObjID::BUTTON_ON_LEFT_CORRIDOR:
					m_IsDeath = true;
				default:
					break;
				}
				break;
			case MonitorView::RIGHT_CORRIDOR_VIEW:
				switch (m_Id)
				{
				case ObjID::BUTTON_ON_WORKSHOP:
				case ObjID::BUTTON_ON_STORE_ROOM:
				case ObjID::BUTTON_ON_RECEPTION_ROOM:
				case ObjID::BUTTON_ON_CHILD_ROOM:
				case ObjID::BUTTON_ON_LEFT_CORRIDOR:
					m_IsDeath = true;
				default:
					break;
				}
				break;
			case MonitorView::LEFT_CORRIDOR_VIEW:
				switch (m_Id)
				{
				case ObjID::BUTTON_ON_WORKSHOP:
				case ObjID::BUTTON_ON_STORE_ROOM:
				case ObjID::BUTTON_ON_RECEPTION_ROOM:
				case ObjID::BUTTON_ON_CHILD_ROOM:
				case ObjID::BUTTON_ON_RIGHT_CORRIDOR:
					m_IsDeath = true;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}
	}
	UpdateGameUI();

	if (m_IsDeath == false) {
		if (HasRectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
			m_OnMouse = true;
		}
		else {
			m_OnMouse = false;
		}
	}
}

void UI::UpdateGameUI() {

	static bool HasPull = false;
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (GetCurrentSceneId() == SceneId::GameScene) {

		if (pPlayer->HasMonitor() == false) {
			if (HasPull == true) {
				switch (m_Id) {
				case ObjID::BUTTON_ON_CONTROL_UI:
					m_IsDeath = false;
					break;
				case ObjID::DESCRIPTION_UI:
					m_IsDeath = false;
					break;
				}
			}

			if (m_OnMouse == true) {
				switch (m_Id)
				{
				case ObjID::BUTTON_CONTROL_UI:
					if (OnMouseDown(Left) == true) {
						HasPull = true;
					}
					break;
				case ObjID::MO_MASK_UI:
					m_HasMask = true;
					break;

				}
			}
			else {

				switch (m_Id)
				{
				case ObjID::BUTTON_CONTROL_UI:
					HasPull = false;
					break;
				case ObjID::MO_MASK_UI:
					m_HasMask = false;
					break;
				}
			}
		}
		else {
			switch (m_Id)
			{
			case ObjID::BUTTON_CONTROL_UI:
				HasPull = false;
				break;
			case ObjID::MO_MASK_UI:
				m_HasMask = false;
				break;
			}
		}

	}
}