/**
*	@file Botan.h
*	@author 中地
*			春日井
*	@brief キャラクター「牡丹」を管理するクラスを処理
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
