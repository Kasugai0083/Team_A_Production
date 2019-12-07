#pragma once

/** @brief ゲーム本編用テクスチャのリスト */
enum GameCategoryTextureList
{
	GameMaskTex,				//!< 背景

	GameBlackFanceTex,	//!< 黒フィルター
	GameBlackFilterTex, //!< 黒フィルター(全体)

	//item
	GameCandleBigTex,
	GameCandleSmallTex,
	GameCandleStandTex,

	GameCandleCenterEffectTex,
	GameCandleLeftEffectTex,
	GameCandleRightEffectTex,
	
	GameFireBigTex,
	GameFireSmallTex,

	GameCrystalTex,
	GameOnHitCrystalTex,
	
	GameMusicBoxTex,

	GameLeftShojiFrontTex,
	GameLeftShojiBackTex,
	GameRightShojiFrontTex,
	GameRightShojiBackTex,

	GameMainUITex,
	GameMaskUITex,

	GameControlUITex,
	GameOnHitControlUITex,

	GameDescriptionUITex,

	GameFreeTex,

	GameTextureMax,			//!< リスト最大数
};

enum CenterCategoryTextureList {
	GameCenterBgTex,

	GameCenterDeskTex,	//!< センターシーンのデスク
	GameCenterBlackTex,	//!< センターシーンの黒テクスチャ

	GameCenterFreddy,
	GameCenterPuppet,

	GameCircle1Tex,
	GameCircle2Tex,
	GameCircle3Tex,
	GameCircle4Tex,
	GameCircle5Tex,
	GameCircle6Tex,
	GameCircle7Tex,
	GameCircle8Tex,



	GameCenterTextureMax,			//!< リスト最大数
};

enum RightCategoryTextureList {
	GameRightBgTex,

	GameRightChicaTex,

	GameRightTextureMax,			//!< リスト最大数
};

enum LeftCategoryTextureList {
	GameLeftBgTex,
	GameLeftTextureMax,			//!< リスト最大数
};

enum MonitorCategoryTextureList {

	GameMonitorDustTex,	//!< ダスト

	GameMonitorSpownBgTex,
	GameMonitorLeftDuctBgTex,
	GameMonitorRightDuctBgTex,

	GameMonitorChildRoomBgTex,
	GameMonitorResptionRoomBgTex,
	GameMonitorStoreRoomBgTex,

	GameMonitorSpownUITex,
	GameMonitorLeftDuctUITex,
	GameMonitorRightDuctUITex,

	GameMonitorOnSpownUITex,
	GameMonitorOnLeftDuctUITex,
	GameMonitorOnRightDuctUITex,

	GameMonitorPlayerRoomUITex,

	GameMonitorFreddy,
	GameMonitorChicaTex,
	GameMonitorPuppetTex,

	GameMonitorMapTex,

	GameMonitorButtom1Tex,
	GameMonitorButtom2Tex,
	GameMonitorButtom3Tex,
	GameMonitorButtom4Tex,
	GameMonitorButtom5Tex,
	GameMonitorButtom6Tex,

	GameMonitorOnButtom1Tex,
	GameMonitorOnButtom2Tex,
	GameMonitorOnButtom3Tex,
	GameMonitorOnButtom4Tex,
	GameMonitorOnButtom5Tex,
	GameMonitorOnButtom6Tex,




	GameMonitorTextureMax,			//!< リスト最大数
};

#define TEXTURE_CATEGORY_GAME (SceneId::GameScene)				//!< ゲーム本編カテゴリー
#define TEXTURE_CATEGORY_CENTER (SceneId::CenterScene)				//!< ゲーム本編カテゴリー
#define TEXTURE_CATEGORY_LEFT (SceneId::LeftScene)				//!< ゲーム本編カテゴリー
#define TEXTURE_CATEGORY_RIGHT (SceneId::RightScene)				//!< ゲーム本編カテゴリー
#define TEXTURE_CATEGORY_MONITOR (SceneId::MonitorScene)				//!< ゲーム本編カテゴリー