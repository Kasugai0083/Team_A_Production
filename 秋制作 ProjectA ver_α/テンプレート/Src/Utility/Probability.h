/**
*	@file Botan.h
*	@author	中本
*	@brief キャラクター「牡丹」を管理するクラスを処理
*/

#ifndef PROBABILITY_H_
#define PROBABILITY_H_

// 確率をしてくれるクラス
class Probability
{
public:
	// 引数に確率を入れる
	// 1.0fで100%
	bool GetRandomValue(int floor, int ceil, int val);
};

#endif