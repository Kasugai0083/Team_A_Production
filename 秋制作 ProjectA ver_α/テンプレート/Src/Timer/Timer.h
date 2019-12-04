#ifndef TIMER_H_
#define TIMER_H_

class Timer {

	//シングルトンデザインパターン
public:

	//実体を作る関数
	static void CreateInstance() {
		if (IsNull() == true) {
			p_Instance = new Timer;
		}
	}

	//実体を破棄する関数
	static void DestroyInstance() {
		if (IsNull() == false) {
			delete p_Instance;
		}
	}

	//実体が存在するか確認する変数
	static bool IsNull() {
		return p_Instance == nullptr;
	}

	//実体を取得する関数
	static Timer* GetInstance() {
		return p_Instance;
	}

public:
	//本来やりたい関数群

	enum Id {
		SCENE,
		CLEAR,
		MUSICBOX,
		MAX_TIMERS
	};

	struct TIMERS {
		int m_Scene;
		int m_Clear;
		int m_MusicBox;
	};

	void Init();
	void Init(Id id_);
	int GetTime(Id id_);

	void Draw();

	void Update();
	void Update(Id id_);

	void WindMusicBox();

private:
	Timer() {}	//コンストラクタ抑制
	~Timer() {}	//デストラクタ抑制

private:
	static Timer* p_Instance;	//自分自身の唯一の実体
private:
	//本来使いたい変数群
	TIMERS Timers;

};



#endif