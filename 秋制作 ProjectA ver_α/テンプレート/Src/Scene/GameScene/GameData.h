#pragma once

enum class MonitorView {
	WORKSHOP_VIEW,			//工房
	STORE_ROOM_VIEW,		//物置
	RECEPTION_ROOM_VIEW,	//客間
	CHILD_ROOM_VIEW,		//子供部屋
	RIGHT_CORRIDOR_VIEW,	//右廊下
	LEFT_CORRIDOR_VIEW,		//左廊下
	NONE					//無とは一体。。。
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