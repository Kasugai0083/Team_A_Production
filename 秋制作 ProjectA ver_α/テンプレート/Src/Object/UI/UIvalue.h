/**
*	@file Botan.h
*	@author 春日井
*	@brief キャラクター「牡丹」を管理するクラスを処理
*/

#pragma once

/**
* UI のサイズと座標情報を登録
*/

#include "../../Utility/Vec.h"
#include "../../Utility/Size.h"

#pragma region タイトルシーンのUI

//ゲームタイトルの値
const Vec2 TITLE_LOGO_POS = { 1564.f,28.f };
const Size TITLE_LOGO_SIZE = { 256.f,1024.f };

//ニューゲームUIの値
const Vec2 NEWGAME_UI_POS = { 456.f, 284.f };
const Size NEWGAME_UI_SIZE = { 256.f, 512.f };

//コンテニューUIの値
const Vec2 CONTINUE_UI_POS = { 200.f, 284.f };
const Size CONTINUE_UI_SIZE = { 256.f, 512.f };

//コンテニューUIの値
const Vec2 DAYS_UI_POS = { 200.f, 220.f };
const Size DAYS_UI_SIZE = { 256.f, 64.f };



#pragma endregion

#pragma region ゲームシーンのUI

//ゲームUIのベース
const Size GAME_BASE_UI_SIZE = { 1920.f, 64.f };
const Vec2 GAME_BASE_UI_POS = {1920.f - GAME_BASE_UI_SIZE.Width, 1072.f - GAME_BASE_UI_SIZE.Height};

//マスクUI
const Size GAME_MASK_UI_SIZE = { 1024.f, 80.f };
const Vec2 GAME_MASK_UI_POS = {(1920.f / 2.f) - (GAME_MASK_UI_SIZE.Width / 2.f), 1008.f};

//操作ボタン
const Size GAME_CONTROL_UI_SIZE = { 256.f, 64.f };
const Vec2 GAME_CONTROL_UI_POS = {1920.f - (GAME_CONTROL_UI_SIZE.Width + 32.f), 1072.f - GAME_CONTROL_UI_SIZE.Height};

//操作説明
const Size GAME_DESCRIPTION_UI_SIZE = { 1920.f, 1080.f };
const Vec2 GAME_DESCRIPTION_UI_POS = {0.f, 0.f };

#pragma endregion

#pragma region モニターシーンのUI

//モニタールームのUIサイズ
const Size MONITOR_BUTTON_SIZE = { 32.f,32.f };

//モニタールームのマップ
const Vec2 MAP_UI_POS = {1350.f, 400.f};
const Vec2 MAP_PLAYER_UI_POS = {1580.f, 920.f};

//モニタールームの各種ボタン座標
const Vec2 WORKSHOP_BUTTON_POS = {1585.f, 445.f};
const Vec2 STORE_ROOM_BUTTON_POS = {1415.f, 565.f};
const Vec2 RECEPTION_ROOM_BUTTON_POS = {1585.f, 565.f};
const Vec2 CHILD_ROOM_BUTTON_POS = {1750.f, 565.f};
const Vec2 LEFT_CORRIDOR_BUTTON_POS = {1465.f, 800.f};
const Vec2 RIGHT_CORRIDOR_BUTTON_POS = {1705.f, 800.f};

#pragma endregion