#include "../Utility/Vec.h"
#include "../Texture/Texture.h"
#include "Calculation.h"
#include "../Character/Player/Player.h"
#include "..//Engine/Input.h"
#include <math.h>

Texture* wall_tex;
Texture* player_tex;

Position GetPosition(float X, float Y) {
	Position PositionTmp;	

	PositionTmp.m_X = X;
	PositionTmp.m_Y = Y;

	return PositionTmp;
}

float GetImageRatio(float a, float b) {
	return (a / b);
}

//2048まで対応
float GetIntegratedImageRatio(float a, float b) {

	a *= b;

	if (a > 1024 && a <= 2048) {
		return (a / 2048.0f) / b;
	}
	else if (a > 512 && a <= 1024) {
		return (a / 1024) / b;
	}
	else if (a > 256 && a <= 512) {
		return (a / 512) / b;
	}
	else if (a > 128 && a <= 256) {
		return (a / 256) / b;
	}
	else if (a > 64 && a <= 128) {
		return (a / 128) / b;
	}
	else if (a > 32 && a <= 64) {
		return (a / 64) / b;
	}
	else if (a > 16 && a <= 32) {
		return (a / 32) / b;
	}
	else if (a > 8 && a <= 16) {
		return (a / 16) / b;
	}
	else if (a > 4 && a <= 8) {
		return (a / 8) / b;
	}
	else if (a > 2 && a <= 4) {
		return (a / 4) / b;
	}
}

//二点間のラジアンを計算
double GetRadian(double startX, double startY, double endX, double endY) {

	//double radian = atan2(startY - endY, startX - endX);
	double radian = atan2(endY - startY, endX - startX);

	return radian;

}

//ラジアンを度数に変換
double GetDegree(double rad) {

	float degree = rad * 180 / PI;

	return degree;

}

float GetVecLong(float X, float Y) {

	float VecLong = sqrt(pow(X, 2) + pow(Y, 2));

	return VecLong;
}



bool RectangleHit(Texture* texture_data, float X1, float X2, float Y1, float Y2) {

	if (X1 >= X2 && X1 <= X2 + texture_data->Width) {
		if (Y1 >= Y2 && Y1 <= Y2 + texture_data->Height) {
			return true;
		}
	}

	return false;

}

bool RectangleHit(float X1, float Y1, float X2, float Y2, float X3, float Y3) {

	if (X1 >= X2  && X1 <= X3) {
		if (Y1 >= Y2 && Y1 <= Y3)  {
			return true;
		}
	}

	return false;

}

bool AdvRectangleHit(float X1, float X2, float Y1, float Y2, float wide1, float wide2, float height1, float height2) {

	float center_x1 = X1 + (wide1 / 2);
	float center_y1 = Y1 + (height1 / 2);
	float center_x2 = X2 + (wide2 / 2);
	float center_y2 = Y2 + (height2 / 2);

	if (fabsf(center_x1 - center_x2) < ((wide1 / 2)) + (wide2 / 2)) {
		if (fabsf(center_y1 - center_y2 ) < ((height1 / 2)) + (height2 / 2) ) {
			return true;
		}
	}

	return false;

}


