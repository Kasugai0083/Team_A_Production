#pragma once

enum class MonitorView {
	WORKSHOP_VIEW,			//çHñ[
	STORE_ROOM_VIEW,		//ï®íu
	RECEPTION_ROOM_VIEW,	//ãqä‘
	CHILD_ROOM_VIEW,		//éqãüïîâÆ
	RIGHT_CORRIDOR_VIEW,	//âEòLâ∫
	LEFT_CORRIDOR_VIEW,		//ç∂òLâ∫
	NONE					//ñ≥Ç∆ÇÕàÍëÃÅBÅBÅB
};

class GameData {
public:
	enum SubGameScene {
		CENTER,
		LEFT,
		RIGHT,
		NONE,
	};

	GameData() :
		m_ViewID(CENTER),
		m_MonitorID(MonitorView::WORKSHOP_VIEW),
		m_HasMonitor(false)
	{
	}


	SubGameScene CurrentViewID() { return m_ViewID;	};
	const MonitorView CurrentMonitorID() { return m_MonitorID;};

	bool GetHasMonitor() { return m_HasMonitor; };

	void SetViewID(SubGameScene id_) {	m_ViewID = id_;	};

	void SetMonitorID(MonitorView view_) {	m_MonitorID = view_; }

private:
	SubGameScene m_ViewID, m_ViewTmp;
	MonitorView m_MonitorID, m_MonitorTmp;

	bool m_HasMonitor;
};

GameData* GameView();