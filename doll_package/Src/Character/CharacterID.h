#ifndef CHARACTERID_H_
#define CHARACTERID_H_

/**
*	@file Botan.h
*	@author 中本
*	@brief キャラクター「牡丹」を管理するクラスを処理
*/

/** 
*	@enum       CharacterID
*	@brief      Characterの定数
*/
enum CharacterID {
	PLAYER,	

	OHAGI,	
	UME,	
	SAKURA,	
	RAN,	
	BOTAN,	
	MARGARET,

	ENEMY_NUM = MARGARET,

	MAX_CHARACTER,
};

/**
*	@enum       EnemyID
*	@brief      Enemyの定数
*/
enum class EnemyID : int {
	OHAGI,	
	UME,	
	SAKURA,	
	RAN,	
	BOTAN,	
	MARGARET,

	MAX_ENEMY,
};

#endif