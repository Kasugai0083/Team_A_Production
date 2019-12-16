#pragma once

enum class MonitorView {
	WORKSHOP_VIEW,
	STORE_ROOM_VIEW,
	RECEPTION_ROOM_VIEW,
	CHILD_ROOM_VIEW,
	RIGHT_CORRIDOR_VIEW,
	LEFT_CORRIDOR_VIEW
};

class GameData {
public:
	enum SubGameScene {
		CENTER,
		LEFT,
		RIGHT,
	};

	GameData() :
		m_ViewID(CENTER),
		m_MonitorID(MonitorView::WORKSHOP_VIEW),
		m_HasMonitor(false)
	{
	}

	void Update();

	SubGameScene CurrentViewID() { return m_ViewID;	};
	MonitorView CurrentMonitorID() { return m_MonitorID;};
	bool GetHasMonitor() { return m_HasMonitor; };

	void SetViewID(SubGameScene id_) {	m_ViewID = id_;	};

	void SetMonitorID(MonitorView view_) {	m_MonitorID = view_; }

private:
	SubGameScene m_ViewID;
	MonitorView m_MonitorID;

	bool m_HasMonitor;
};

GameData* GameView();