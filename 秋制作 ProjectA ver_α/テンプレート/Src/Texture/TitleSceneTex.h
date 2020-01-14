#pragma once
/** @brief タイトル用テクスチャのリスト */
enum TitleCategoryTextureList
{
	TitleBgTex,				//!< 背景
	TitleLogoTex,

	TitleNewGameUITex,
	TitleNewGameOnHitUITex,

	TitleContinueUITex,
	TitleContinueOnHitUITex,

	TitleDaysUITex,
	TitleDaysOnHitUITex,

	TitleFreeTex,

	TitleTextureMax			//!< リスト最大数
};

#define TEXTURE_CATEGORY_TITLE (SceneId::TitleScene)			//!< タイトルカテゴリー
