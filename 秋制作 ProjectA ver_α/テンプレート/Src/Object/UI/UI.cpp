#include "UI.h"
#include "../../Engine/Input.h"
#include "../../Engine/Calculation.h"
#include "../../Texture/Texture.h"
#include "../../Engine/Graphics.h"
#include "../ObjectManager.h"
#include "UIID.h"

Object* g_pTitleLogo;


void UI::Init(){
	switch (m_ID) {
	case UserInterfaceID::TITLE_LOGO:
		m_Pos = TITLE_LOGO_POS;
		m_Size = TITLE_LOGO_SIZE;
		LoadTexture("Res/Title/TitleLogo.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleLogoTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleLogoTex);
		break;
	case UserInterfaceID::BUTTON_NEW_GAME:
		m_Pos = NEWGAME_UI_POS;
		m_Size = NEWGAME_UI_SIZE;
		LoadTexture("Res/Title/TitleMenuStart.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleNewGameUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleNewGameUITex);
		break;
	case UserInterfaceID::BUTTON_CONTINUE:
		m_Pos = CONTINUE_UI_POS;
		m_Size = CONTINUE_UI_SIZE;
		LoadTexture("Res/Title/TitleMenuHelp.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleContinueUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleContinueUITex);
		break;
	case UserInterfaceID::BUTTON_WORKSHOP:
		m_Pos = WORKSHOP_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/button_1.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom1Tex);
		LoadTexture("Res/Game/Monitor/MonitorUI/on_button_1.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom1Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom1Tex);
		break;
	case UserInterfaceID::BUTTON_STORE_ROOM:
		m_Pos = STORE_ROOM_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/button_2.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom2Tex);
		LoadTexture("Res/Game/Monitor/MonitorUI/on_button_2.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom2Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom2Tex);
		break;
	case UserInterfaceID::BUTTON_RECEPTION_ROOM:
		m_Pos = RECEPTION_ROOM_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/button_3.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom3Tex);
		LoadTexture("Res/Game/Monitor/MonitorUI/on_button_3.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom3Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom3Tex);
		break;
	case UserInterfaceID::BUTTON_CHILD_ROOM:
		m_Pos = CHILD_ROOM_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/button_4.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom4Tex);
		LoadTexture("Res/Game/Monitor/MonitorUI/on_button_4.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom4Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom4Tex);
		break;
	case UserInterfaceID::BUTTON_RIGHT_CORRIDOR:
		m_Pos = RIGHT_CORRIDOR_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/button_5.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom5Tex);
		LoadTexture("Res/Game/Monitor/MonitorUI/on_button_5.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom5Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom5Tex);
		break;
	case UserInterfaceID::BUTTON_LEFT_CORRIDOR:
		m_Pos = LEFT_CORRIDOR_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/button_6.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom6Tex);
		LoadTexture("Res/Game/Monitor/MonitorUI/on_button_6.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom6Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom6Tex);
		break;
	case UserInterfaceID::MONITOR_MAP:
		m_Pos = MAP_UI_POS;
		m_Size = {0.f,0.f};
		LoadTexture("Res/Game/Monitor/MonitorUI/map.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorMapTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorMapTex);
		break;
	case UserInterfaceID::PLAYER_ROOM:
		m_Pos = PLAYER_ROOM_UI_POS;
		m_Size = {0.f,0.f};
		LoadTexture("Res/Game/Monitor/MonitorUI/PlayerRoomUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPlayerRoomUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPlayerRoomUITex);
		break;
	case UserInterfaceID::CLEAR_LOGO:
		m_Pos = TITLE_LOGO_POS;
		m_Size = TITLE_LOGO_SIZE;
		LoadTexture("Res/Title/TitleMenuHelp.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleContinueUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleContinueUITex);
		break;
	
	}

};

void UI::Draw(){

	DrawTexture(m_Pos.X, m_Pos.Y, m_Tex);

	Lib::Texture polygon("hoge");

	if (m_OnMouse == true) {
		DrawAlphaBox2D(polygon, m_Pos, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
	}
		
}

void UI::Update() {
	if (HasRectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
		m_OnMouse = true;
	}
	else {
		m_OnMouse = false;
	}
}

bool UI::HasOnMouse() {
	return m_OnMouse;
}