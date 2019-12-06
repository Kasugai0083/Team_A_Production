#pragma once

#include "../Item.h"
#include "../../../Scene/Scene.h"
#include "../../../Scene/GameScene/GameData.h"
#include "../../../Engine/Input.h"
#include "../../../Engine/Calculation.h"

enum class CandleType {
	CENTER_CANDLE,
	LEFT_CANDLE,
	RIGHT_CANDLE,
	OTHER
};

const float CANDLE_MELT_BIG = 0.2f;
const float CANDLE_MELT_SMALL = 0.1f;

const float MELT_RATIO = 0.001f;

//struct StatusSave{
//	Size 
//};

class Candle : public Item {
public:

	Candle(ObjID id_)
	{
		m_Id = id_;
		m_IsDeath = true;
		m_HeightRatio = NULL;
		m_HasCaLight = false;
		m_CandleHp = 1.f;

	};
	void Init()override;

	void InitCount()override;
	void Update()override;

	void Draw() override;

	Vec2 GetPos()override;
	float GetHp()override;
	float GetRatio()override;
	bool HasCaLight()override;

private:

	void SceneDeath();
	void CandleSwitch(bool center_switch_, bool left_switch_, bool right_switch_);
	void MeltCandle(ObjID id_);
	void EffectUpdate();

	static int m_Count;
	static Candller m_Candller;

	bool m_HasCaLight;

	float m_CandleHp;
	float m_HeightRatio;

	static Candller m_Death;

};

