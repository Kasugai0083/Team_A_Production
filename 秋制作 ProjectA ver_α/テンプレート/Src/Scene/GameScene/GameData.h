#pragma once

enum class MonitorView {
	WORKSHOP_VIEW,
	STORE_ROOM_VIEW,
	RECEPTION_ROOM_VIEW,
	CHILD_ROOM_VIEW,
	RIGHT_CORRIDOR_VIEW,
	LEFT_CORRIDOR_VIEW
};

struct GameData {
	
	enum SubGameScene {
		CENTER,
		LEFT,
		RIGHT,
	};

	GameData() :
		m_ViewID(CENTER)
	{}

	SubGameScene CurrentViewID() {
		return m_ViewID;
	};
	MonitorView CurrentMonitorID() {
		return m_MonitorID;
	};


	void SetViewID(SubGameScene id_) {
		m_ViewID = id_;
	};

	void SetMonitorID(MonitorView view_) {
		m_MonitorID = view_;
	}

	SubGameScene m_ViewID;
	MonitorView m_MonitorID;
};

GameData* GameView();