#ifndef AUDIO_H_
#define AUDIO_H_

#include <string>
#include <unordered_map>
#include "Sound.h"
#include "../../Engine/Window.h"

/*
	オーディオプレイヤークラス
*/
class AudioPlayer
{
public:
	static AudioPlayer* GetInstance(HWND hwnd_ = nullptr) {
		static AudioPlayer instance(hwnd_);
		return &instance;
	}

	/*
		Waveファイルの読み込み
	*/
	bool Load(std::string alias_, std::string file_name_);

	/*
		再生処理
	*/
	void Play(std::string alias_, int volume = -1000, bool is_loop = false);

	/*
		停止
	*/
	void Stop(std::string alias_);

	/*
		ボリューム設定
	*/
	void SetVolume(std::string alias_, int volume_);

	// 解放処理
	void Release(std::string alias_);


private:
	// コンストラクタ
	AudioPlayer(HWND hwnd) {
		// 再生先のウィンドウハンドルを取得
		m_pSound = new DirectSound(hwnd);
		ZeroMemory(&m_SoundData, 0, sizeof(IDirectSoundBuffer8));
	}

	/*
		サウンドファイルの検索
	*/
	IDirectSoundBuffer8* Find(std::string alias_);

	/*
		デストラクタ
	*/
	~AudioPlayer();

private:
	//
	DirectSound* m_pSound;
	// セカンダリバッファー
	std::unordered_map<std::string, IDirectSoundBuffer8*> m_SoundData;
	// データフォーマット構造体
	WAVEFORMATEX m_Format;
	// waveファイルのサイズ
	DWORD        m_Size;

};


#endif