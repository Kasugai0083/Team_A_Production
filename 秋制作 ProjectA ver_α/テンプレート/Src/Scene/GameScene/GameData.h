#pragma once

enum class SubGameScene {
	CENTER_VIEW,			//プレイヤールーム中央
	LEFT_VIEW,				//プレイヤールーム左
	RIGHT_VIEW,				//プレイヤールーム右
	WORKSHOP_VIEW,			//工房
	STORE_ROOM_VIEW,		//物置
	RECEPTION_ROOM_VIEW,	//客間
	CHILD_ROOM_VIEW,		//子供部屋
	RIGHT_CORRIDOR_VIEW,	//右廊下
	LEFT_CORRIDOR_VIEW,		//左廊下
};
class GameData {
public:


	//GameData() :
	//	m_ViewID(CENTER),
	//	m_ViewTmp(CENTER),
	//	m_MonitorID(MonitorView::NONE),
	//	m_MonitorTmp(MonitorView::WORKSHOP_VIEW)
	//{
	//}


	//SubGameScene CurrentViewID() { return m_ViewID;	};
	//const MonitorView CurrentMonitorID() { return m_MonitorID;};

	//void SetViewID(SubGameScene id_) {	m_ViewID = id_;	};

	//void SaveViewID() { 
	//	if (m_ViewID != NONE) {
	//		m_ViewTmp = m_ViewID;
	//	}
	//};

	//void LoadViewID() { m_ViewID = m_ViewTmp; }

	//void SetMonitorID(MonitorView view_) {	m_MonitorID = view_; }

	//void SaveMonitorID() { 
	//	if (m_MonitorID != MonitorView::NONE) {
	//		m_MonitorTmp = m_MonitorID;
	//	}
	//}

	//void LoadMonitorID() { m_MonitorID = m_MonitorTmp; }

private:
	//SubGameScene m_ViewID, m_ViewTmp;
	//MonitorView m_MonitorID, m_MonitorTmp;
};

GameData* GameView();