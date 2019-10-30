#pragma once

#include "../UI.h"
#include "../../../Scene/Scene.h"


class RightDuct : public UI {
public:

	void Init()override {
		m_Pos = RIGHT_DUCT_UI_POS;
		m_Size = MONITOR_UI_SIZE;

		LoadTexture("Res/Game/Monitor/MonitorUI/OnRightDuctUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctUITex);

		LoadTexture("Res/Game/Monitor/MonitorUI/RightDuctUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctUITex);

		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctUITex);
	};

private:

};


class BlackRightDuct : public UI {
public:

	void Init()override {
		m_Pos = RIGHT_DUCT_UI_POS;
		m_Size = MONITOR_UI_SIZE;

		LoadTexture("Res/Game/Monitor/MonitorUI/OnRightDuctUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnRightDuctUITex);

		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnRightDuctUITex);
	};

	void Draw()override {
		DrawTexture(m_Pos.X, m_Pos.Y, m_Tex);
	}

private:

};