/**
*	@file	RoomID.h
*	@author	中本
*	@brief  部屋を区別するためのID
*/

#ifndef ROOMID_H_
#define ROOMID_H_

/**
*	@enum       RoomID
*	@brief      部屋の定数
*/
enum RoomID {

	ROOM_WORK,			//! 工房
	ROOM_STORAGE,		//! 物置
	ROOM_CHILDREN,		//! 子供部屋

	ROOM_RECEPTION,		//! 応接間
	HALL_BACK,			//! 後広間
	HALL_FRONT,			//! 前広間
	LEFT_CORRIDOR,		//! 左廊下
	RIGHT_CORRIDOR,		//! 右廊下
	LEFT_SHOJI,			//! 左障子
	RIGHT_SHOJI,		//! 右障子

	ROOM_PRAYER,		//! 祈祷室
	ROOM_RIGHT_PRAYER,	//! 右祈祷室
	ROOM_LEFT_PRAYER,	//! 左祈祷室

	ROOM_VOID,			//! 亜空間
};


#endif