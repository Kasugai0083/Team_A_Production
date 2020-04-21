/**
*	@file OpeningSceneTex.h
*	@author 中地
*			春日井
*	@brief オープニングシーンの画像リスト
*/

#pragma once

/** @brief ゲーム本編用テクスチャのリスト */
enum OpeningCategoryTextureList
{
	OpeningDiary1Tex,				//!< 背景
	OpeningDiary2Tex,				//!< 背景
	OpeningDiary3Tex,				//!< 背景
	OpeningDiary4Tex,				//!< 背景

	OpeningDay1Tex,
	OpeningDay2Tex,
	OpeningDay3Tex,

	OpeningTextureMax,			//!< リスト最大数
};

#define TEXTURE_CATEGORY_OPENING (SceneId::OpeningScene)				//!< ゲーム本編カテゴリー
