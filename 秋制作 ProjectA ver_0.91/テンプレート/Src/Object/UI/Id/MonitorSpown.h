#pragma once

#include "../UI.h"
#include "../../../Scene/Scene.h"


class MonitorSpown : public UI {
public:

	void Init()override {

		m_Pos = SPOWN_UI_POS;
		m_Size = MONITOR_UI_SIZE;

		LoadTexture("Res/Game/Monitor/MonitorUI/SpownUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownUITex);

		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownUITex);
	};

private:

};


class BlackMonitorSpown : public UI {
public:

	void Init()override {

		m_Pos = SPOWN_UI_POS;
		m_Size = MONITOR_UI_SIZE;

		LoadTexture("Res/Game/Monitor/MonitorUI/OnSpownUI.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnSpownUITex);

		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnSpownUITex);
	};

	void Draw()override {
		DrawTexture(m_Pos.X, m_Pos.Y, m_Tex);
	}

private:

};