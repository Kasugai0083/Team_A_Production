#ifndef ITEM_VALUE_H_
#define ITEM_VALUE_H_

#include "../../Utility/Vec.h"
#include "../../Utility/Size.h"

#pragma region ゲーム内オブジェクト

//ろうそく（大）
const Vec2 CANDLE_BIG_POS = { 200.f,200.f };
const Size CANDLE_BIG_SIZE = { 46.f,256.f };
const Size CANDLE_BIG_FRAME = { 256.f,256.f };

//ろうそく(小)
const Vec2 CANDLE_SMALL_POS = { 200.f,200.f };
const Size CANDLE_SMALL_SIZE = { 12.f,64.f };
const Size CANDLE_SMALL_FRAME = { 64.f,64.f };

//ろうそく(灯)
const Vec2 CANDLE_EFFECT_POS = { 0.f,0.f };
const Size CANDLE_EFFECT_SIZE = { 118.f,118.f };
const Size CANDLE_EFFECT_FRAME = { 128.f,128.f };

//ろうそく(燭台)
const Vec2 CANDLE_STAND_POS = { 0.f,0.f };
const Size CANDLE_STAND_SIZE = { 110.f,512.f };
const Size CANDLE_STAND_FRAME = { 256.f,512.f };

//炎(大)
const Vec2 FIRE_BIG_POS = { 0.f,0.f };
const Size FIRE_BIG_SIZE = { 55.f,114.f };
const Size FIRE_BIG_FRAME = { 256.f,256.f };

//炎(小)
const Vec2 FIRE_SMALL_POS = { 0.f,0.f };
const Size FIRE_SMALL_SIZE = { 15.f,32.f };
const Size FIRE_SMALL_FRAME = { 64.f,64.f };

//水晶
const Vec2 CRYSTAL_POS = { 200.f,200.f };
const Size CRYSTAL_SIZE = { 181.f,174.f };
const Size CRYSTAL_FRAME = { 256.f,256.f };

//オルゴール
const Vec2 MUSICBOX_POS = { 1140.f,920.f };
const Size MUSICBOX_SIZE = { 99.f,99.f };
const Size MUSICBOX_FRAME = { 128.f,128.f };

#pragma endregion

#endif