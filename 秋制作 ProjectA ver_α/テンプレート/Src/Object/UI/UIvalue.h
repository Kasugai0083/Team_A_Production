#pragma once

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

#pragma endregion

#pragma region ゲームシーンのUI

const Size GAME_BASE_UI_SIZE = { 1920.f, 64.f };
const Vec2 GAME_BASE_UI_POS = {1920.f - GAME_BASE_UI_SIZE.Width, 1080.f - GAME_BASE_UI_SIZE.Height};

const Size GAME_MASK_UI_SIZE = { 1024.f, 64.f };
const Vec2 GAME_MASK_UI_POS = {(1920.f / 2.f) - (GAME_MASK_UI_SIZE.Width / 2.f), 1080.f - GAME_MASK_UI_SIZE.Height};

const Size GAME_CONTROL_UI_SIZE = { 256.f, 64.f };
const Vec2 GAME_CONTROL_UI_POS = {1920.f - (GAME_CONTROL_UI_SIZE.Width + 32.f), 1080.f - GAME_CONTROL_UI_SIZE.Height};

const Size GAME_DESCRIPTION_UI_SIZE = { 256.f, 256.f };
const Vec2 GAME_DESCRIPTION_UI_POS = {1920.f - (GAME_DESCRIPTION_UI_SIZE.Width + 32.f), 1080.f - (GAME_CONTROL_UI_SIZE.Height + GAME_DESCRIPTION_UI_SIZE.Height) };

#pragma endregion

#pragma region モニターシーンのUI

//モニタールームのUIサイズ
const Size MONITOR_UI_SIZE = { 128.f, 64.f };

const Size MONITOR_BUTTON_SIZE = { 32.f,32.f };

//モニタールームのUI群の座標
const Vec2 SPOWN_UI_POS = { 1500.f, 700.f };
const Vec2 LEFT_DUCT_UI_POS = { 1400.f,800.f };
const Vec2 RIGHT_DUCT_UI_POS = { 1600.f, 800.f };
const Vec2 PLAYER_ROOM_UI_POS = { 1500.f, 900.f };

const Vec2 MAP_UI_POS = {1200.f, 400.f};
const Vec2 WORKSHOP_BUTTON_POS = {1600.f, 430.f};
const Vec2 STORE_ROOM_BUTTON_POS = {1375.f, 550.f};
const Vec2 RECEPTION_ROOM_BUTTON_POS = {1600.f, 550.f};
const Vec2 CHILD_ROOM_BUTTON_POS = {1825.f, 550.f};
const Vec2 LEFT_CORRIDOR_BUTTON_POS = {1375.f, 700.f};
const Vec2 RIGHT_CORRIDOR_BUTTON_POS = {1720.f, 700.f};

#pragma endregion