#ifndef CHARACTERID_H_
#define CHARACTERID_H_

enum CharacterID {

	OHAGI,		// 正面
	SAKURA,		// 右
	UME,		// 左
	RAN,		// 正面にいて光で撃退
	BOTAN,		// カメラから戻ってきたらたまにいるやつ
	MARGARET,	// オルゴール

	PLAYER,		// プレイヤー
	ENEMY_NUM = PLAYER,

	MAX_CHARACTER,
};

#endif
