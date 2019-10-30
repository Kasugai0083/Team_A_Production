#ifndef CHARACTERID_H_
#define CHARACTERID_H_

enum CharacterID {


	FREDDY,		// 正面
	BONNIE,		// 右
	CHICA,		// 左
	FOXY,		// 正面にいて光で撃退
	G_FREDDY,	// カメラから戻ってきたらたまにおる
	PUPPET,		// オルゴール

	PLAYER,		// プレイヤー
	ENEMY_NUM = PLAYER,

	MAX_CHARACTER

};

//enum CharacterNum{
//	ENEMY_NUM = PLAYER
//};

#endif
