#ifndef ENEMYTEX_H_
#define ENEMYTEX_H_

#include "GameSceneTex.h"

enum EnemyCategoryTextureList
{
	FredyFarTex,	// HALL_BACKの時のテクスチャ
	EnemyBoonieTex,	// テスト用
	
	EnemyBonnieTex,	// バニーのテクスチャー

	EnemyRanNearTex,	// 近ランのテクスチャ

	EnemyBotanTex,	// ボタンテクスチャ

	EnemyTextureMax,
};

#define TEXTURE_CATEGORY_ENEMY (SceneId::EnemyScene)				//!< ゲーム本編カテゴリー

#endif