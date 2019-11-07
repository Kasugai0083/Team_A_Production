#include "Timer.h"

//Timer* TimerFunc() { 
//	static Timer g_Timer;
//	return &g_Timer; 
//};

//staticなメンバ変数を初期化【コンストラクタではやらない】
Timer* Timer::p_Instance = nullptr;

void Timer::Init() {
	Timers.m_Scene = 0;
	Timers.m_Clear = 0;
	Timers.m_MusicBox = 0;
}
void Timer::Init(Id id_) {

	switch (id_) {
	case SCENE:
		Timers.m_Scene = 0;	
		break;
	case CLEAR:
		Timers.m_Clear = 0;
		break;
	case MUSICBOX:
		Timers.m_MusicBox = 0;
		break;
	default:
		return;
		break;
	}

}

int Timer::GetTime(Id id_) {
	switch (id_){
	case SCENE:
		return Timers.m_Scene;
		break;
	case CLEAR:
		return Timers.m_Clear;
		break;	
	case MUSICBOX:
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

}

void Timer::Update(Id id_) {
	switch (id_) {
	case SCENE:
		Timers.m_Scene++;
		break;
	case CLEAR:
		Timers.m_Clear++;
		break;
	case MUSICBOX:
		Timers.m_MusicBox++;
		break;
	default:
		break;
	}

}


void Timer::WindMusicBox() {
	Timers.m_MusicBox -= 3;
	if (Timers.m_MusicBox < 0) {
		Timers.m_MusicBox = 0;
	}
}