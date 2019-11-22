/**
* @file Texture.h
* @brief テクスチャの読み込み、解放など、テクスチャに関する関数、定数の宣言
*/
#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../Scene/Scene.h"
#include "../Engine/Graphics.h"

/** @brief タイトル用テクスチャのリスト */
enum TitleCategoryTextureList
{
	TitleBgTex,				//!< 背景
	TitleLogoTex,		
	TitleNewGameUITex,
	TitleContinueUITex,

	TitleFreeTex,

	TitleTextureMax			//!< リスト最大数
};

/** @brief ゲーム本編用テクスチャのリスト */
enum GameCategoryTextureList
{
	GameMaskTex,				//!< 背景

	//item
	GameCandleBigTex,
	GameCandleSmallTex,
	GameCandleStandTex,
	GameCandleEffectTex,
	GameFireBigTex,
	GameFireSmallTex,
	GameCrystalTex,
	GameMusicBoxTex,

	GameLeftShojiFrontTex,
	GameLeftShojiBackTex,
	GameRightShojiFrontTex,
	GameRightShojiBackTex,

	GameFreeTex,

	GameTextureMax,			//!< リスト最大数
};

enum CenterCategoryTextureList {
	GameCenterBgTex,

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


	GameMonitorTextureMax,			//!< リスト最大数
};

/** @brief ヘルプ用テクスチャリスト */
enum ClearCategoryTextureList
{
	ClearBgTex,				//!< 背景
	ClearGameOverTex,
	ClearTextureMax,			//!< リスト最大数
};

#define TEXTURE_CATEGORY_TITLE (SceneId::TitleScene)			//!< タイトルカテゴリー
#define TEXTURE_CATEGORY_GAME (SceneId::GameScene)				//!< ゲーム本編カテゴリー
#define TEXTURE_CATEGORY_CENTER (SceneId::CenterScene)				//!< ゲーム本編カテゴリー
#define TEXTURE_CATEGORY_LEFT (SceneId::LeftScene)				//!< ゲーム本編カテゴリー
#define TEXTURE_CATEGORY_RIGHT (SceneId::RightScene)				//!< ゲーム本編カテゴリー
#define TEXTURE_CATEGORY_MONITOR (SceneId::MonitorScene)				//!< ゲーム本編カテゴリー
#define TEXTURE_CATEGORY_CLEAR (SceneId::ClearScene)				//!< ヘルプカテゴリー
#define MAX_TEXTURE_CATEGORY (SceneId::SceneIdMax)				//!< カテゴリー最大

/**
* @brief テクスチャデータ初期化関数@n
* ゲームで使用するテクスチャデータを保存出来るようにする
*/
void InitTexture();

/**
* @brief カテゴリー単位のテクスチャ解放関数@n
* 引数で指定されたカテゴリーのテクスチャを全て解放する
* @param[in] category_id 解放カテゴリー
*/
void ReleaseCategoryTexture(int category_id);

/**
* @brief テクスチャの全解放@n
* 読み込んでいるすべてのテクスチャを解放する@n
* ※この関数はEndEngineで使用されているので開発側で呼ぶ必要はない
*/
void AllReleaseTexture();

/**
* @brief テクスチャの読み込み@n
* 指定したされたパスのテクスチャを読み込み、カテゴリに登録する
* @return 読み込み結果(成功はtrue)
* @param[in] file_name 読み込むテクスチャ名(パス込み)
* @param[in] category_id 登録するカテゴリー
* @param[in] texture_id カテゴリー内のテクスチャID
*/
bool LoadTexture(const char* file_name, int category_id, int texture_id);

/**
* @brief テクスチャデータの取得@n
* 指定されたカテゴリのテクスチャデータを取得する
* @return テクスチャデータ(取得失敗時はnullptr)
* @param[in] 取得したいテクスチャのカテゴリ
* @param[in] 取得したいテクスチャのID
*/
Texture* GetTexture(int category_id, int texture_id);

#endif
