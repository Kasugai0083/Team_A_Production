#pragma once

/** @brief ゲーム本編用テクスチャのリスト */
enum OpeningCategoryTextureList
{
	OpeningDiaryTex,				//!< 背景

	OpeningDay1Tex,
	OpeningDay2Tex,
	OpeningDay3Tex,

	OpeningTextureMax,			//!< リスト最大数
};

#define TEXTURE_CATEGORY_OPENING (SceneId::OpeningScene)				//!< ゲーム本編カテゴリー
