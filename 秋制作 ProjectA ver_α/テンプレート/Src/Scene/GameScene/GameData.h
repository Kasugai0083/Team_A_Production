#pragma once

struct GameData {
	
	enum SubGameScene{
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
	
	void SetViewID(SubGameScene id_) {
		m_ViewID = id_;
	};

	SubGameScene m_ViewID;

};

GameData* PepshiMan();