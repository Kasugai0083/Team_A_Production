#include"../Audio/Sound.h"

DirectSound::DirectSound(HWND hwnd)
{
	// インターフェースの作成と初期化
	// 作成後はすぐにSetCooperativeLevel関数で協調レベルの設定を行わないといけない
	DirectSoundCreate8(nullptr, &m_pDSound8, nullptr);
	// 協調レベルの設定
	// ロックされたバッファがある場合呼び出さない
	m_pDSound8->SetCooperativeLevel(hwnd, DSSCL_NORMAL);

	// 新しいバッファーオブジェクトの特性を設定する構造体の作成と初期化
	DSBUFFERDESC desc = {};
	// 構造体のサイズを
	desc.dwSize = sizeof(DSBUFFERDESC);
	// バッファーオブジェクトの能力の指定するフラグ(複数指定可能)
	// 今回は( DSBCAPS_PRIMARYBUFFER = このバッファがプライマリバッファ
	//		   DSBCAPS_CTRLVOLUME    = このバッファにはボリューム制御機能がある
	desc.dwFlags = DSBCAPS_PRIMARYBUFFER | DSBCAPS_CTRLVOLUME;
	// 新しいバッファサイズの指定
	// 今回はdwFlagsでDSBCAPS_PRIMARYBUFFERを指定しているため「0」にする
	desc.dwBufferBytes = 0;
	// 0を指定
	desc.dwReserved = 0;
	// Waveフォーマットの指定
	// 今回はdwFlagsでDSBCAPS_PRIMARYBUFFERを指定しているため「NULL」にする
	desc.lpwfxFormat = nullptr;
	// よくわからないが、
	// dwFlagsでDSBCAPS_CTRL3Dを指定していない場合「GUID_NULL」
	desc.guid3DAlgorithm = GUID_NULL;

	// 上で作ったDSBUFFERDESC構造の情報を使い
	// サウンドバッファの作成を行う
	m_pDSound8->CreateSoundBuffer(&desc, &m_pPrimaryBuffer, nullptr);
}


IDirectSoundBuffer8* DirectSound::LoadWaveFile(std::string file_name_)
{
	// マルチメディアの入出力構造体
	// Handle Multi Media Input Output だと思うたぶん
	HMMIO hmmio = nullptr;
	// よくわからないがWAVAファイルの時は必要みたい
	MMIOINFO mminfo = {};
	// ファイルのオープン
	hmmio = mmioOpen((LPSTR)file_name_.c_str(), &mminfo, MMIO_READ);

	// ファイルのオープンに失敗した場合
	if (!hmmio) {
		MessageBox(0, "waveファイルのオープンに失敗", 0, MB_OK);
		return nullptr;
	}

	// 関数が戻すリターンコードを示す変数？
	MMRESULT result;
	// 
	MMCKINFO rif_chunk;
	// 
	rif_chunk.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	// リフチャンクの検索
	result = mmioDescend(hmmio, &rif_chunk, NULL, MMIO_FINDRIFF);

	// リフチャンクの検索に失敗した場合
	if (result != MMSYSERR_NOERROR) {
		mmioClose(hmmio, 0);
		return nullptr;
	}

	MMCKINFO fmt_chunk;
	fmt_chunk.ckid = mmioFOURCC('f', 'm', 't', ' ');
	// フォーマットチャンクの検索
	result = mmioDescend(hmmio, &fmt_chunk, &rif_chunk, MMIO_FINDCHUNK);

	// フォーマットチャンクの検索に失敗した場合
	if (result != MMSYSERR_NOERROR) {
		mmioClose(hmmio, 0);
		return nullptr;
	}

	// 音質やチャンネル数の情報を格納する
	WAVEFORMATEX format;
	DWORD fmsize = fmt_chunk.cksize;
	// ファイル内のデータを読み込む
	if (mmioRead(hmmio, (HPSTR)& format, fmsize) != fmsize) {
		mmioClose(hmmio, 0);
		return nullptr;
	}

	// データ検索のため一度戻る
	mmioAscend(hmmio, &fmt_chunk, 0);

	MMCKINFO data_chunk;
	data_chunk.ckid = mmioFOURCC('d', 'a', 't', 'a');
	// データチャンクの検索
	result = mmioDescend(hmmio, &data_chunk, &rif_chunk, MMIO_FINDCHUNK);
	// データチャンクの検索に失敗した場合
	if (result != MMSYSERR_NOERROR) {
		mmioClose(hmmio, 0);
		return nullptr;
	}

	// 波形データの情報を保存する
	DWORD data_size = data_chunk.cksize;
	BYTE* pwav_data = new BYTE[data_chunk.cksize];
	// 波形データの読み取り
	if (mmioRead(hmmio, (HPSTR)pwav_data, data_chunk.cksize) != data_chunk.cksize) {
		delete[] pwav_data;
		return nullptr;
	}

	// 正常読み込み
	mmioClose(hmmio, 0);

	// セカンダリバッファの設定
	DSBUFFERDESC desc = {};
	desc.dwSize          = sizeof(DSBUFFERDESC);
	desc.dwFlags         = DSBCAPS_CTRLVOLUME | DSBCAPS_GLOBALFOCUS |
						   	 DSBCAPS_CTRLPAN | DSBCAPS_CTRLFREQUENCY;
	desc.dwBufferBytes   = data_size;
	desc.dwReserved      = 0;
	desc.lpwfxFormat     = &format;
	desc.guid3DAlgorithm = GUID_NULL;

	IDirectSoundBuffer* pbuf = 0;
	m_pDSound8->CreateSoundBuffer(&desc, &pbuf, nullptr);

	//戻り値がIDirectSoundBufferの為、IDirectSoundBuffer8に戻す
	pbuf->QueryInterface(IID_IDirectSoundBuffer8, (void**)& m_pSecBuffer);
	pbuf->Release();


	// WAVデータ書き込み
	LPVOID write_data;
	DWORD  len;
	m_pSecBuffer->Lock(
		0,						// ロック開始位置
		0,						// メモリサイズ
		&write_data,			// ロック位置のポインタ
		&len,					// 大きさ
		NULL,					// 範囲を超えた場合のメモリ領域の指定
		NULL,
		DSBLOCK_ENTIREBUFFER	// ロックする大きさの指定
	);

	memcpy(write_data, pwav_data, len);
	m_pSecBuffer->Unlock(write_data, len, nullptr, 0);
	// 元音源を削除
	delete[] pwav_data;

	if (m_pSecBuffer == nullptr) {
		MessageBox(0, "waveファイルの読み込みに失敗", 0, MB_OK);
	}

	return m_pSecBuffer;
}


DirectSound::~DirectSound()
{
	m_pDSound8->Release();
	m_pPrimaryBuffer->Release();
}