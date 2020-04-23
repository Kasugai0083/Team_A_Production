/**
*	@file Timer.h
*	@author 春日井
*	@brief シーンやエネミーを制御するためのタイマークラスを定義@n
*	試験的に佐藤先生のシングルトンを導入
*/

#ifndef TIMER_H_
#define TIMER_H_

#include <string>

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

	/**
	* 構造体 TIMERS の識別番号
	*/
	enum class Id {
		SCENE,
		CLEAR,
		MUSICBOX,
		MAX_TIMERS
	};

	//! タイマー変数をまとめた構造体
	struct TIMERS {
		//! シーン切り替えのクールタイム
		int m_Scene;	
		//! クリア時間を制御
		int m_Clear;	
		//! パペットの起動を制御
		int m_MusicBox;
	};

	/**
	* @fn void Init()
	* @brief TIMERS と m_HourCount を初期化
	*/
	void Init();

	/**
	* @fn void Init(Id id_)
	* @brief 識別番号で指定されたメンバ変数を初期化
	* param[in] id_ 識別番号
	*/
	void Init(Id id_);

	/**
	* @fn int GetTime(Id id_)
	* @brief 識別番号で指定されたメンバ変数を取得
	* @param[in] id_ 識別番号
	* @return 識別番号で指定されたメンバ変数の値
	*/
	int GetTime(Id id_);


	/**
	* @fn void Draw()
	* @brief m_Clear を描画@npocket_watchをマウスオーバーしている場合に時間が表示される
	*/
	void Draw();

	/** 
	* @fn void Update()
	* @brief メンバ変数の更新@nDraw 用に m_Minute, m_Hour, m_Sample に文字列を代入
	*/
	void Update();

	/**
	* @fn int GetClearTime()
	* @brief シーン遷移に必要な値を取得
	* @return m_HourCount の値を取得
	*/
	int GetClearTime() { return m_HourCount; };

private:
	Timer() {}	//コンストラクタ抑制
	~Timer() {}	//デストラクタ抑制

private:
	static Timer* p_Instance;	//自分自身の唯一の実体
private:
	//本来使いたい変数群

	//! TIMERS のインスタンス
	TIMERS Timers;		
	//! クリアに必要なカウント
	int m_HourCount;	

	int m_Timemag;

	//! デジタル時計風の描画に必要な文字列
	std::string m_Minute, m_Hour, m_Sample; 

};



#endif