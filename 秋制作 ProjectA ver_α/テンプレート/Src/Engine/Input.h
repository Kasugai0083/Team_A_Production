
/**
* @file Input.h
* @brief 入力に関する関数、定数の宣言
*/
#ifndef INPUT_H_
#define INPUT_H_

#include <Windows.h>
#include "../Utility/Vec.h"

// キー情報GetKeyシリーズの関数で使用する
#define CLEAR_KEY	0x0000		// キークリア用
#define UP_KEY		0x0001		// 上キー
#define DOWN_KEY	0x0002		// 下キー
#define LEFT_KEY	0x0004		// 左キー
#define RIGHT_KEY	0x0008		// 右キー
#define RETURN_KEY	0x0010		// リターンキー
#define W_KEY		0x0020		// Wキー
#define A_KEY		0x0040		// Aキー
#define S_KEY		0x0080		// Sキー
#define D_KEY		0x0100		// Dキー
#define ESCAPE_KEY	0x0200		// ESCキー
#define CONTROL_KEY	0x0400		// ESCキー
#define SPACE_KEY	0x0800		// Spaceキー

// デバック用
#define ONE_KEY		0x1000		// 1キー
#define TWO_KEY		0x2000		// 2キー
#define THREE_KEY	0x4000		// 3キー
#define FOUR_KEY	0x8000		// 4キー
#define FIVE_KEY	0x10000		// 5キー
#define SIX_KEY		0x20000		// 6キー



/** @brief マウスボタンの種類 */
enum MouseButton
{
	Left,		//!< 左
	Right,		//!< 右
	Center,		//!< 真ん中
};

/**
* @brief Input機能初期化関数@n
* デバイスの入力取得に必要な初期化を行う
* ※InitEngineで実行されるので開発側が実行する必要はない
* @return 初期化結果(成功はtrue)
*/
bool InitInput();

/**
* @brief Input機能終了関数@n
* Input機能を終了させる@n
* ※EndEngineで実行されるので開発側が実行する必要はない
*/
void EndInput();

/**
* @brief 入力情報の更新@n
* デバイスの入力情報の更新を行う@n
* 毎フレームに１度必ず実行する必要がある
*/
void UpdateInput();

/**
* @brief クリックした瞬間判定関数@n
* 指定したマウスのボタンがクリックされた瞬間かどうかを判定する
* @return 判定結果(押された瞬間ならtrue)
* @param[in] button_type 判定したいボタンの種類
*/
bool OnMouseDown(MouseButton button_type);

/**
* @brief クリック中判定関数@n
* 指定したマウスのボタンがクリック中かどうかを判定する
* @return 判定結果(クリック中瞬間ならtrue)
* @param[in] button_type 判定したいボタンの種類
*/
bool OnMousePush(MouseButton button_type);

/**
* @brief クリック終了判定関数@n
* 指定したマウスのボタンがクリックを終了した瞬間かどうかを判定する
* @return 判定結果(クリックをやめた瞬間ならtrue)
* @param[in] button_type 判定したいボタンの種類
*/
bool OnMouseUp(MouseButton button_type);

/** @brief マウスの座標取得関数 */
Vec2 GetMousePos();

/*
	キーを押してるかを判定
		戻り値：
			押されてる => true
			押されてない => false

		引数：
			DWORD key_code
				判断したいキーコード

		内容
			キーが押されているならtrue、押されていないならfalseを返す
*/
bool GetKey(DWORD key_code);

/*
	キーを押した瞬間を判定
		戻り値：
			押した瞬間 => true
			押した瞬間じゃない => false

		引数：
			DWORD key_code
				判断したいキーコード

		内容
			キーが押された瞬間ならtrue、押されてない瞬間ならfalse
*/
bool GetKeyDown(DWORD key_code);

/*
	キーを離した瞬間を判定
		戻り値：
			離した瞬間 => true
			離した瞬間じゃない => false

		引数：
			DWORD key_code
				判断したいキーコード

		内容
			キーが離した瞬間ならtrue、離した瞬間じゃないならfalse
*/
bool GetKeyUp(DWORD key_code);
#endif
