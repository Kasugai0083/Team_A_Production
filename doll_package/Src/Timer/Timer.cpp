#include "Timer.h"
#include "..//Scene/Scene.h"
#include "..//Engine/Graphics.h"
#include "../Object/ObjectManager.h"
#include "..//Character/CharacterManager.h"
#include "..//Data/GameData.h"

//staticなメンバ変数を初期化【コンストラクタではやらない】
Timer* Timer::p_Instance = nullptr;

void Timer::Init() {
	Timers.m_Scene = 0;
	Timers.m_Clear = 0;
	Timers.m_MusicBox = 0;
	m_HourCount = 0;

	// ここで時間の調整
	m_Timemag = Timers.m_Clear / GameData::GetInstance()->GetGameParam().m_TimeMagnification;

}
void Timer::Init(Id id_) {

	switch (id_) {
	case Id::SCENE:
		Timers.m_Scene = 0;	
		break;
	case Id::CLEAR:
		Timers.m_Clear = 0;
		break;
	case Id::MUSICBOX:
		Timers.m_MusicBox = 0;
		break;
	default:
		return;
		break;
	}

}

int Timer::GetTime(Id id_) {
	switch (id_){
	case Id::SCENE:
		return Timers.m_Scene;
		break;
	case Id::CLEAR:
		return Timers.m_Clear;
		break;	
	case Id::MUSICBOX:
		return Timers.m_MusicBox;
		break;
	default:
		return 0;
		break;
	}
}
void Timer::Update() {


	Timers.m_Scene++;
	Timers.m_Clear++;
	Timers.m_MusicBox++;

	m_Timemag = GameData::GetInstance()->GetGameParam().m_TimeMagnification;
	int TIME = Timers.m_Clear / m_Timemag;

	if (TIME == 60) {
		Timers.m_Clear = 0;
		m_HourCount++;
	}

	//左上のサンプル
	m_Sample = std::to_string(TIME);

	//左下のデジタル時計表示
	m_Hour = std::to_string(m_HourCount);
	m_Minute = std::to_string(TIME);

	if (TIME < 10) {
		std::string zero_plus = "0";
		m_Minute = zero_plus + m_Minute;
	}

}


void Timer::Draw() {
	Object* WatchInstance = ObjManager()->GetObj(ObjID::POCKET_WATCH);
	Object* pMaskUI = ObjManager()->GetObj(ObjID::MO_MASK_UI);

	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (pPlayer->HasMonitor() == false) {
		if (WatchInstance->HasOnMouse() == true) {
			DrawFont(30.f, 1014.f, "AM", Large, Yellow);
			DrawFont(130.f, 1014.f, m_Hour.c_str(), Large, Yellow);
			DrawFont(162.f, 1014.f, ":", Large, Yellow);
			DrawFont(194.f, 1014.f, m_Minute.c_str(), Large, Yellow);
		}
	}

}

