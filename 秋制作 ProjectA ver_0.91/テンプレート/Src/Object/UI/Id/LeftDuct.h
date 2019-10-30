#pragma once

#include "../UI.h"
#include "../../../Scene/Scene.h"


class LeftDuct : public UI {
public:

	void Init()override {

		m_Pos = LEFT_DUCT_UI_POS;
		m_Size = MONITOR_UI_SIZE;
	
		LoadTexture("Res/Game/Monitor/MonitorUI/LeftDuctUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctUITex);

		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctUITex);
	};

private:

};


class BlackLeftDuct : public UI {
public:

	void Init()override {


		m_Pos = LEFT_DUCT_UI_POS;
		m_Size = MONITOR_UI_SIZE;

		LoadTexture("Res/Game/Monitor/MonitorUI/OnLeftDuctUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnLeftDuctUITex);

		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnLeftDuctUITex);
	};

	void Draw()override {
		DrawTexture(m_Pos.X, m_Pos.Y, m_Tex);
	}

private:

};