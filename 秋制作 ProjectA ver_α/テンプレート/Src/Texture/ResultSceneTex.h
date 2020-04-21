/**
*	@file Botan.h
*	@author 中地
*			春日井
*	@brief キャラクター「牡丹」を管理するクラスを処理
*/

#pragma once

enum ClearCategoryTextureList
{
	ClearBgTex,				//!< 背景
	ClearGameEndTex,
	ClearGameOverTex,
	ClearTextureMax,			//!< リスト最大数
};

#define TEXTURE_CATEGORY_CLEAR (SceneId::ClearScene)				//!< ヘルプカテゴリー
