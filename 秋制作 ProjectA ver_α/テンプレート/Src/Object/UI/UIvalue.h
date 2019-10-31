#pragma once

#include "../../Utility/Vec.h"
#include "../../Utility/Size.h"

#pragma region タイトルシーンのUI

//ゲームタイトルの値
const Vec2 TITLE_LOGO_POS = { 0.f,0.f };
const Size TITLE_LOGO_SIZE = { 1024.f,512.f };

//ニューゲームUIの値
const Vec2 NEWGAME_UI_POS = { 200.f,600.f };
const Size NEWGAME_UI_SIZE = { 498.f,146.f };

//コンテニューUIの値
const Vec2 CONTINUE_UI_POS = { 200.f,800.f };
const Size CONTINUE_UI_SIZE = { 498.f,146.f };

#pragma endregion

#pragma region モニターシーンのUI

//モニタールームのUIサイズ
const Size MONITOR_UI_SIZE = { 128.f, 64.f };

//モニタールームのUI群の座標
const Vec2 SPOWN_UI_POS = { 1500.f, 700.f };
const Vec2 LEFT_DUCT_UI_POS = { 1400.f,800.f };
const Vec2 RIGHT_DUCT_UI_POS = { 1600.f, 800.f };
const Vec2 PLAYER_ROOM_UI_POS = { 1500.f, 900.f };


#pragma endregion