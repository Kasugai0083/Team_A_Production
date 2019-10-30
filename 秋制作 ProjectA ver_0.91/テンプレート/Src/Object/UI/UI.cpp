#include "UI.h"
#include "../../Engine/Input.h"
#include "../../Engine/Calculation.h"
#include "../../Texture/Texture.h"
#include "../../Engine/Graphics.h"
#include "../ObjectManager.h"


Object* g_TitleLogo;

UI::UI() {
		m_Pos = {0.f, 0.f};
		m_Size = {0.f, 0.f};
		m_OnMouse = false;
}


//void UI::Init(const ItemId id, bool OnBlack) {
//	
//	g_TitleLogo = UIManager()->GetObj(TITLE_LOGO);
//
//	switch (id) {
//	case TITLE_LOGO:
//		m_Pos = TITLE_LOGO_POS;
//		m_Size = TITLE_LOGO_SIZE;
//		LoadTexture("Res/Title/TitleLogo.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleLogoTex);
//		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleLogoTex);
//		break;
//	case NEW_GAME:
//		m_Pos = NEWGAME_UI_POS;
//		m_Size = NEWGAME_UI_SIZE;
//		LoadTexture("Res/Title/TitleMenuStart.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleNewGameUITex);
//		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleNewGameUITex);
//		break;
//	case CONTINUE:
//		m_Pos = CONTINUE_UI_POS;
//		m_Size = CONTINUE_UI_SIZE;
//		LoadTexture("Res/Title/TitleMenuHelp.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleContinueUITex);
//		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleContinueUITex);
//		break;
//	case MONITOR_SPOWN:
//		m_Pos = SPOWN_UI_POS;
//		m_Size = MONITOR_UI_SIZE;
//		if (OnBlack == true) {
//			LoadTexture("Res/Game/Monitor/MonitorUI/OnSpownUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownUITex);
//		}
//		else {
//			LoadTexture("Res/Game/Monitor/MonitorUI/SpownUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownUITex);
//		}
//		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownUITex);
//		break;
//	case LEFT_DUCT:
//		m_Pos = LEFT_DUCT_UI_POS;
//		m_Size = MONITOR_UI_SIZE;
//		if (OnBlack == true) {
//			LoadTexture("Res/Game/Monitor/MonitorUI/OnLeftDuctUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctUITex);
//		}
//		else {
//			LoadTexture("Res/Game/Monitor/MonitorUI/LeftDuctUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctUITex);
//		}
//		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctUITex);
//		break;
//	case RIGHT_DUCT:
//		m_Pos = RIGHT_DUCT_UI_POS;
//		m_Size = MONITOR_UI_SIZE;
//		if (OnBlack == true) {
//			LoadTexture("Res/Game/Monitor/MonitorUI/OnRightDuctUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctUITex);
//		}
//		else {
//			LoadTexture("Res/Game/Monitor/MonitorUI/RightDuctUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctUITex);
//		}
//		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctUITex);
//		break;
//	case PLAYER_ROOM:
//		m_Pos = PLAYER_ROOM_UI_POS;
//		m_Size = MONITOR_UI_SIZE;
//		LoadTexture("Res/Game/Monitor/MonitorUI/PlayerRoomUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPlayerRoomUITex);
//		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPlayerRoomUITex);
//		break;
//	default:
//		break;
//	}
//
//
//
//
//}

void UI::Draw(){

	DrawTexture(m_Pos.X, m_Pos.Y, m_Tex);

	Lib::Texture polygon("hoge");

	if (m_OnMouse == true) {
		DrawAlphaBox2D(polygon, m_Pos, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
	}
		
}

void UI::Update() {
	if (RectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
		m_OnMouse = true;
	}
	else {
		m_OnMouse = false;
	}
}

bool UI::HasOnMouse() {
	return m_OnMouse;
}