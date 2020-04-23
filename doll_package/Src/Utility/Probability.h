/**
*	@file	Probability.h
*	@author	中本
*	@brief	確率を出すためのクラスを処理
*/

#ifndef PROBABILITY_H_
#define PROBABILITY_H_

/**
* @brief	確率を出すクラス
* @details	フォクシーの挙動や描画を実装している
*/
class Probability
{
public:
	/**
	* @fn			bool GetRandomValue(int floor_, int ceil_, int val_)
	* @brief		引数[floor_]以上[ceil_]以下のなかからランダムな値をだし[val_]と一致したらTrueを返す関数
	* @param[in]	int(floor_)	ああ
	* @param[in]	int(ceil_)	エネミーのID
	* @param[in]	int(val_)	エネミーのID
	* @return		bool	
	*/
	bool GetRandomValue(int floor_, int ceil_, int val_);
};

#endif