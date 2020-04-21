/**
*	@file Botan.h
*	@author 中地
*			春日井
*	@brief キャラクター「牡丹」を管理するクラスを処理
*/

#ifndef TITLE_OBJECTTEX_H_
#define TITLE_OBJECTTEX_H_

#include "GameSceneTex.h"

enum TitleObjectCategoryTextureList {

	// TITLE_SCENE_OBJECT
	OBJECT_TITLELOGO_TEX,

	OBJECT_NEWGAME_TEX,
	OBJECT_NEWGAME_ONHIT_TEX,

	OBJECT_CONTINUE_TEX,
	OBJECT_CONTINUE_ONHIT_TEX,

	OBJECT_DAYS_TEX,
	OBJECT_DAYS_ONHIT_TEX,

	TITLE_OBJECT_TEXTURE_MAX,			//!< リスト最大数
};

#define TEXTURE_CATEGORY_TITLE_OBJECT (SceneId::TitleObjectScene)				//!< ゲーム本編カテゴリー

#endif