#ifndef TIMER_H_
#define TIMER_H_

class Timer {
public:
	enum Id {
		Scene,
		Clear,
		MusicBox,

	};

	struct TIMERS {
		int m_Scene;
		int m_Clear;
		int m_MusicBox;

	};

	void Init();
	void Init(Id id_);
	int Get(Id id_);
	void Set(int val_, Id id_);
	void Update(Id id_);
	void CountDown(Id id_);
private:
	TIMERS Timers;
};

Timer* TimerFunc();

#endif