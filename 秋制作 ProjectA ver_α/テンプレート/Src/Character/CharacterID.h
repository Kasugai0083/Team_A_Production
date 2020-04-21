#ifndef CHARACTERID_H_
#define CHARACTERID_H_

/**
*	@file Botan.h
*	@author 春日井
*	@brief キャラクター「牡丹」を管理するクラスを処理
*/


enum CharacterID {
	PLAYER,		// プレイヤー

	OHAGI,		// 正面
	UME,		// 右
	SAKURA,		// 左
	RAN,		// 正面にいて光で撃退
	BOTAN,		// カメラから戻ってきたらたまにいるやつ
	MARGARET,	// オルゴール

	ENEMY_NUM = MARGARET,

	MAX_CHARACTER,
};

enum class EnemyID : int {
	
	OHAGI,		// 正面
	UME,		// 右
	SAKURA,		// 左
	RAN,		// 正面にいて光で撃退
	BOTAN,		// カメラから戻ってきたらたまにいるやつ
	MARGARET,	// オルゴール

	MAX_ENEMY,
	
};



#endif
