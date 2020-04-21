#ifndef CHARACTERMANAGER_H_
#define CHARACTERMANAGER_H_

/**
*	@file	CharacterManager.h
*	@author 中本
*	@brief	キャラクターを管理するクラスを処理
*/


#include "Character.h"
#include "CharacterID.h"
#include "../Utility/RoomID.h"

/**
* @brief	キャラクターマネージャークラス
* @details	キャラクター全体を管理するクラス
*/
class CharacterManager {

public:
	/**
	* @fn		CharacterManager()
	* @brief	コンストラクタ
	*/
	CharacterManager();

	/**
	* @fn		~CharacterManager()
	* @brief	デストラクタ
	*/
	~CharacterManager();

	/**
	* @fn		void Initialize()
	* @brief	キャラクター全体を初期化するための関数
	*/
	void Initialize();

	/**
	* @fn		void Update()
	* @brief	キャラクター全体を更新するための関数
	*/
	void Update();

	/**
	* @fn		void Draw()
	* @brief	キャラクター全体を描画するための関数
	*/
	void Draw();

	/**
	* @fn			Character* GetCharacter(int id)
	* @brief		キャラクターのインスタンスを取得する関数
	* @param[in]	int(id_)	欲しいキャラクターのID
	*/
	Character* GetCharacter(int id_) {
		return m_Charas[id_];
	}

	/*
		m_Charas変数をdeleteする関数
		ClearSceneで一度だけ行う

		またはゲームが終了したときに行われる
	*/

	/**
	* @fn		void Release()
	* @brief	キャラクターを解放する関数
	*/
	void Release();

	/**
	* @fn		void Draw()
	* @brief	エネミーのキルアニメーション関数
	*/
	void KillAnimation();

	/*
		エネミーがプレイヤーを殺したかどうかを返す関数
	*/

	/**
	* @fn		bool HasKill()
	* @brief	エネミーがプレイヤーを殺したかどうかを返す関数
	* @return	bool true : 殺した	false : 殺してない
	*/
	bool HasKill();

	/**
	* @fn		const bool CanKill() const
	* @brief	エネミーがプレイヤーを殺せる状態かどうかを返す関数
	* @return	bool true : 殺せる	false : 殺せない
	*/
	const bool CanKill() const;

	/**
	* @fn		void CreateCharacter()
	* @brief	キャラクターを作成関数
c
	*/
	void CreateCharacter();

	/*
		引数の部屋に敵がいるかどうか
		[roomId_] -> RoomID
	*/

	/**
	* @fn			bool IsSameRoom(RoomID roomId_)
	* @brief		引数の部屋に敵がいるかどうかを調べる関数
	* @param[in]	int(id_)	部屋のID
	* @return		bool true : いる	false : いない
	*/
	bool IsSameRoom(RoomID roomId_);

private:

	Character* m_Charas[8];	//! キャラクターのインスタンスを保存するポインタ変数
};

extern CharacterManager g_Manager;

#endif