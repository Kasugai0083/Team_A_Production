#ifndef SOUND_H_
#define SOUND_H_

/**
*	@file Botan.h
*	@author 中本
*	@brief キャラクター「牡丹」を管理するクラスを処理
*/

#include <dsound.h>
#include <string>

/*
	サウンドクラス
*/
class DirectSound
{
public:
	/*
		コンストラクタ
		インターフェースの作成と初期化
		サウンドバッファの作成と初期化
	*/
	DirectSound(HWND hwnd = nullptr);

	/*
		Waveファイルの読み込み関数
		引数にファイルのパスを入れる
		例:
			LoadWaveFile("Res/Sound/hoge.wave");
	*/
	IDirectSoundBuffer8* LoadWaveFile(std::string file_name_);

	/*
		デストラクタ
		インターフェースの解放
		サウンドバッファの解放
	*/
	~DirectSound();

private:
	IDirectSound8*		 m_pDSound8;		// サウンドインターフェース
	IDirectSoundBuffer*  m_pPrimaryBuffer;	// プライマリーバッファー
	IDirectSoundBuffer8* m_pSecBuffer;		// 

};


#endif