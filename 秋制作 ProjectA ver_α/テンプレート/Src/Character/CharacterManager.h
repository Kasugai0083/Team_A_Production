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
		引数に現在のシーンを入れる。
		引数のシーンのテクスチャを読み込む
	*/
	void LoadTex(SceneId id);

	bool RefKill();

private:
	void Release();

	Character* m_Charas[8];
};

extern CharacterManager g_Manager;

#endif