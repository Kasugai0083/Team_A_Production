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
	m_HourCount = 0;
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

	counter_ /= 60;

	if (counter_ >= 1000) {
		strings_[0] = '0' + (counter_ / 1000);
		strings_[1] = '0' + (counter_ % 1000 / 100);
		strings_[2] = '0' + (counter_ % 1000 %100 / 10);
		strings_[3] = '0' + (counter_ % 1000 % 100 % 10);
	}
	else if (counter_ >= 1000 && counter_ >= 100) {
		strings_[0] = '0' + (counter_ / 100);
		strings_[1] = '0' + (counter_ % 100 / 10);
		strings_[2] = '0' + (counter_ % 100 % 10);
	}
	else if (counter_ >= 100 && counter_ >= 10) {
		strings_[0] = '0' + (counter_ / 10);
		strings_[1] = '0' + (counter_ % 10);
	}
	else {
		strings_[0] = '0' + (counter_ % 1000 % 100 % 10);
	}

}

void Timer::Draw() {

	int TIME = Timers.m_Clear / 10;

	if (TIME == 60) {
		Timers.m_Clear = 0;
		m_HourCount++;
	}

	std::string m_Minute = "0", m_Hour = "00";

	//左上のサンプル
	std::string timer = std::to_string(TIME);

	//左下のデジタル時計表示
	m_Hour = std::to_string(m_HourCount);
	m_Minute = std::to_string(TIME);

	if (TIME < 10) {
		std::string zero_plus = "0";
		m_Minute = zero_plus + m_Minute;
	}



	DrawFont(100.f,100.f, timer.c_str(), Large, White);
	DrawFont(100.f,1014.f, m_Hour.c_str(), Large, Black);
	DrawFont(132.f,1014.f, ":", Large, Black);
	DrawFont(164.f,1014.f, m_Minute.c_str(), Large, Black);

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