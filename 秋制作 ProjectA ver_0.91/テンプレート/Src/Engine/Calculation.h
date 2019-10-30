#ifndef CALCULATION_H_
#define CALCULATION_H_

#include "../Texture/Texture.h"

struct Position {
	float m_X;
	float m_Y;
};

Position GetPosition(float X, float Y);

#define PI 3.141592

//画像の比率を算出する
//a => 描画する画像サイズ
//b => 全体の画像サイズ
float GetImageRatio(float a, float b);
//統合画像の比率を算出する
//a => 描画する画像サイズ
//b => 統合画像の枚数
float GetIntegratedImageRatio(float a, float b);

//点と矩形の当たり判定
//X1, Y1 => GetMousPos()など利用
//X2 - X3 => 矩形の範囲を指定(横)
//Y2 - Y3 => 矩形の範囲を指定(縦)
bool RectangleHit(float X1, float Y1, float X2, float Y2, float X3, float Y3);
//画像サイズをtexture_dataからとる場合、座標の指定だけでOK
bool RectangleHit(Texture* texture_data, float X1, float X2, float Y1, float Y2);

//二点間のラジアンを計算
double GetRadian(double startX, double startY, double endX, double endY);
//ラジアンを度数法に変換する
double GetDegree(double rad);

//矩形と矩形の当たり判定
//X1, Y1 => 1つ目の座標を指定
//wide1, hight1 => 1つ目の矩形のサイズを指定
//X2, Y2 => ２つ目の座標を指定
//wide2, hight2 => ２つ目の矩形のサイズを指定
bool AdvRectangleHit(float X1, float X2, float Y1, float Y2, float wide1, float wide2, float height1, float height2);

#endif