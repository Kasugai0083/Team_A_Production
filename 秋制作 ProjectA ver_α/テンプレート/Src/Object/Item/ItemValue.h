#ifndef ITEM_VALUE_H_
#define ITEM_VALUE_H_

#include "../../Utility/Vec.h"
#include "../../Utility/Size.h"

#pragma region ゲーム内オブジェクト

//亜空間座標
const Vec2 VOID_POS = { 9999.f, 9999.f };

//ろうそく（大）
const Size CANDLE_BIG_SIZE = { 46.f,256.f };
const Size CANDLE_BIG_FRAME = { 256.f,256.f };
const Vec2 CANDLE_BIG_POS = { (960.f - CANDLE_BIG_SIZE.Width / 2), (140.f) };


//ろうそく(小)
const Size CANDLE_SMALL_SIZE = { 12.f,64.f };
const Size CANDLE_SMALL_FRAME = { 64.f,64.f };
const Vec2 CANDLE_SMALL_POS = { (960.f - CANDLE_SMALL_SIZE.Width / 2),320.f };

//ろうそく(灯)
const Size CANDLE_EFFECT_SIZE = { 118.f,118.f };
const Size CANDLE_EFFECT_FRAME = { 128.f,128.f };
const Vec2 BIG_CANDLE_EFFECT_POS = { (960.f - CANDLE_EFFECT_SIZE.Width / 2),60.f };
const Vec2 SMALL_CANDLE_EFFECT_POS = { (960.f - CANDLE_EFFECT_SIZE.Width / 2),250.f };

//ろうそく(燭台)
const Size CANDLE_STAND_SIZE = { 110.f,512.f };
const Size CANDLE_STAND_FRAME = { 256.f,512.f };
const Vec2 CANDLE_STAND_POS = { (960.f - (CANDLE_STAND_SIZE.Width / 2)), (640.f - (CANDLE_STAND_SIZE.Height / 2)) };

//炎(大)
const Size FIRE_BIG_SIZE = { 55.f,114.f };
const Size FIRE_BIG_FRAME = { 256.f,256.f };
const Vec2 FIRE_BIG_POS = { (960.f - (FIRE_BIG_SIZE.Width / 2)), (90.f - (FIRE_BIG_SIZE.Height / 2)) };

//炎(小)
const Size FIRE_SMALL_SIZE = { 15.f,32.f };
const Size FIRE_SMALL_FRAME = { 64.f,64.f };
const Vec2 FIRE_SMALL_POS = { (960.f - FIRE_SMALL_SIZE.Width / 2), 290.f };

//水晶
const Size CRYSTAL_SIZE = { 181.f,174.f };
const Size CRYSTAL_FRAME = { 256.f,256.f };
const Vec2 CRYSTAL_POS = { (660.f - CRYSTAL_SIZE.Width / 2), (920.f - CRYSTAL_SIZE.Height / 2) };

//オルゴール
const Size MUSICBOX_SIZE = { 99.f,99.f };
const Size MUSICBOX_FRAME = { 128.f,128.f };
const Vec2 MUSICBOX_POS = { (1240.f - MUSICBOX_SIZE.Height / 2),(920.f - MUSICBOX_SIZE.Height / 2) };

#pragma endregion

#endif