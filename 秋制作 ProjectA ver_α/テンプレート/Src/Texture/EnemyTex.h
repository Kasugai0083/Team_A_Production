#ifndef ENEMYTEX_H_
#define ENEMYTEX_H_

#include "GameSceneTex.h"

enum EnemyCategoryTextureList
{
	FredyFarTex,	// フレディ(200*200)のテクスチャ
	FredyNearTex,	// フレディ(350*350)のテクスチャ

	EnemyBoonieTex,	// テスト用
	
	EnemyBonnieTex,	// バニー(512*512)のテクスチャー
	BonnieSpawnTex,	// バニー(350*350)のテクスチャー
	BonnieLookTex,	// バニー(300*300)のテクスチャー

	ChicaTex,
	ChicaSpawnTex,
	ChicaLookTex,

	RanTex,		// ラン(512*512)のテクスチャ
	RanFarTex,	// ラン(200*200)のテクスチャ
	RanNearTex,	// ラン(350*350)のテクスチャ


	EnemyBotanTex,	// ボタンテクスチャ

	MargaretEyeUITex,	// マーガレットの目のUI
	MargaretPiza1,
	MargaretPiza2,
	MargaretPiza3,
	MargaretPiza4,
	MargaretPiza5,
	MargaretPiza6,
	MargaretPiza7,
	MargaretPiza8,
	MargaretPiza9,

	EnemyTextureMax,
};

#define TEXTURE_CATEGORY_ENEMY (SceneId::EnemyScene)				//!< ゲーム本編カテゴリー

#endif