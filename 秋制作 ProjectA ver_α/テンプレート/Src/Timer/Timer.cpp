#include "Timer.h"

Timer* TimerFunc() { 
	static Timer g_Timer;
	return &g_Timer; 
};

void Timer::Init() {
	Timers.m_Scene = 0;
	Timers.m_Clear = 0;
	Timers.m_MusicBox = 0;
}

int Timer::Get(Id id) {
	switch (id){
	case Scene:
		return Timers.m_Scene;
		break;
	case Clear:
		return Timers.m_Clear;
		break;	
	case MusicBox:
		return Timers.m_MusicBox;
		break;
	default:
		return 0;
		break;
	}
}

void Timer::Set(int val, Id id) {
	switch (id) {
	case Scene:
		Timers.m_Scene = val;
		break;
	case Clear:
		Timers.m_Clear = val;
		break;
	case MusicBox:
		Timers.m_MusicBox = val;
		break;
	default:
		break;
	}

}

void Timer::Update(Id id) {
	switch (id) {
	case Scene:
		Timers.m_Scene++;
		break;
	case Clear:
		Timers.m_Clear++;
		break;
	case MusicBox:
		Timers.m_MusicBox++;
		break;
	default:
		break;
	}

}


void Timer::CountDown(Id id) {
	switch (id) {
	case Scene:
		Timers.m_Scene--;
		break;
	case Clear:
		Timers.m_Clear--;
		break;
	case MusicBox:
		Timers.m_MusicBox -= 2;
		if (Timers.m_MusicBox < 0) {
			Timers.m_MusicBox = 0;
		}
		break;
	default:
		break;
	}

}