/**
*	@file TitleSceneTex.h
*	@author 中地
*			春日井
*	@brief タイトルシーンの画像リスト
*/


#pragma once
/** @brief タイトル用テクスチャのリスト */
enum TitleCategoryTextureList
{
	TitleBgTex,				//!< 背景

	TitleFreeTex,

	TitleTextureMax			//!< リスト最大数
};

#define TEXTURE_CATEGORY_TITLE (SceneId::TitleScene)			//!< タイトルカテゴリー
