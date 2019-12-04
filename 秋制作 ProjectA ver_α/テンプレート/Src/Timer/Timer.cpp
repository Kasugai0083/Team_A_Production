#include "Timer.h"
#include "..//Scene/Scene.h"
#include "..//Engine/Graphics.h"

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

void UnitedStrings(int counter_, char strings_[20]) {
	for (int i = 0; i < 20; ++i) {
		if (strings_[i] == NULL) {
			if (counter_ >= 1000) {
				strings_[i] = '0' + (counter_ / 1000);
				strings_[i + 1] = '0' + (counter_ % 1000 / 100);
				strings_[i + 2] = '0' + (counter_ % 1000 %100 / 10);
				strings_[i + 3] = '0' + (counter_ % 1000 % 100 % 10);
			}
			else if (counter_ >= 1000 && counter_ >= 100) {
				strings_[i] = '0' + (counter_ / 100);
				strings_[i + 1] = '0' + (counter_ % 100 / 10);
				strings_[i + 2] = '0' + (counter_ % 100 % 10);
			}
			else if (counter_ >= 100 && counter_ >= 10) {
				strings_[i] = '0' + (counter_ / 10);
				strings_[i + 1] = '0' + (counter_ % 10);
			}
			else {
				strings_[i] = '0' + (counter_ % 1000 % 100 % 10);
			}

		}
	}
}

void Timer::Draw() {

	char Clock2[4] = {NULL,NULL,NULL,NULL};

	UnitedStrings(Timers.m_Clear,Clock2);

	char* Clock = Clock2;

	DrawFont(100.f,1010.f, Clock, Large, Black);

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