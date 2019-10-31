#pragma once

#include "../UI.h"
#include "../../../Scene/Scene.h"


class PlayerRoom : public UI {
public:

	void Init()override {

		m_Pos = PLAYER_ROOM_UI_POS;
		m_Size = MONITOR_UI_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/PlayerRoomUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPlayerRoomUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPlayerRoomUITex);

	};

	void Draw()override {
		DrawTexture(m_Pos.X, m_Pos.Y, m_Tex);
	}

private:

};