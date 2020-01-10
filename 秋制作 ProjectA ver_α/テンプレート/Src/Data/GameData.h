#pragma once

enum class SubGameScene {
	CENTER_VIEW,			//プレイヤールーム中央
	LEFT_VIEW,				//プレイヤールーム左
	RIGHT_VIEW,				//プレイヤールーム右
	WORKSHOP_VIEW,			//工房
	STORE_ROOM_VIEW,		//物置
	RECEPTION_ROOM_VIEW,	//客間
	CHILD_ROOM_VIEW,		//子供部屋
	RIGHT_CORRIDOR_VIEW,	//右廊下
	LEFT_CORRIDOR_VIEW,		//左廊下
};

/**
* エネミーのスポーンする頻度\n
* DAYによって調整
*/
const float SPOWN_JUDGE_OHAGI = 1.0f;
const float SPOWN_JUDGE_SAKURA = 1.0f;
const float SPOWN_JUDGE_UME = 1.0f;
const float SPOWN_JUDGE_RAN = 1.0f;
const float SPOWN_JUDGE_BOTAN = 1.0f;

/**
* エネミーの移動速度\n
* プランナーが調整する項目
*/
const int MOVEMENT_SPEED_OHAGI = 300;
const int MOVEMENT_SPEED_SAKURA = 300;
const int MOVEMENT_SPEED_UME = 300;
const int MOVEMENT_SPEED_RAN = 300;
const int MOVEMENT_SPEED_BOTAN = 0;

//! 蝋燭が溶ける速度
const float MELT_RATIO = 0.001f; 

//! ここで時間の進みを変更
const int TIME_MAGNIFICATION = 100000000;
