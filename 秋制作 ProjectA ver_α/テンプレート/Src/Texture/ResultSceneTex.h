/**
*	@file ResultSceneTex.h
*	@author 中地
*			春日井
*	@brief クリアシーンの画像リスト
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
