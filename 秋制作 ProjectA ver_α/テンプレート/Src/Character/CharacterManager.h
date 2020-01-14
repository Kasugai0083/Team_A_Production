#ifndef CHARACTERMANAGER_H_
#define CHARACTERMANAGER_H_

#include "Character.h"
#include "CharacterID.h"

// キャラクターマネージャークラス
class CharacterManager {

public:
	/*
		コンストラクタ
	*/
	CharacterManager();
	/*
		デストラクタ
	*/
	~CharacterManager();

	/*
		初期化
	*/
	void Initialize();

	/*
		更新
	*/
	void Update();

	/*
		引数に指定したidのインスタンスのアドレスを返す
	*/
	Character* GetCharacter(int id) {
		return m_Charas[id];
	}

	/*
		描画
	*/
	void Draw();

	/*
		m_Charas変数をdeleteする関数
		ClearSceneで一度だけ行う

		またはゲームが終了したときに行われる
	*/
	void Release();

	/*
		テクスチャの読み込み関数
	*/
	void LoadTex();

	/*
		キルアニメーション
	*/
	void KillAnimation();

	/*
		エネミーがプレイヤーを殺したかどうかを返す関数
	*/
	bool RefKill();

	void CreateCharacter();

private:

	Character* m_Charas[8];
};

extern CharacterManager g_Manager;

#endif