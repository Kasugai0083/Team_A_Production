#ifndef CHARACTERID_H_
#define CHARACTERID_H_

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
