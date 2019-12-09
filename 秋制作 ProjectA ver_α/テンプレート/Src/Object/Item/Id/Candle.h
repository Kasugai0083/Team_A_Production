#pragma once

/**
* オブジェクトの葉（最終継承先）@n
* 蝋燭を管理するクラスを格納
*/

#include "../Item.h"
#include "../../../Scene/Scene.h"
#include "../../../Scene/GameScene/GameData.h"
#include "../../../Engine/Input.h"
#include "../../../Engine/Calculation.h"

const float MELT_RATIO = 0.001f; //!< @brief 蝋燭が溶ける速度

/**
* @brief 蝋燭に纏わるオブジェクトを管理するクラス@n
* 蝋燭、燭台、蝋燭のエフェクト@n
*/
class Candle : public Item {
public:

	/**
	* @fn Candle(ObjID id_)
	* @brief コンストラクタ@n各種メンバ変数の初期化@n
	* @param[in] id_ で指定された ObjID を代入
	*/
	Candle(ObjID id_)
	{
		m_Id = id_;
		m_IsDeath = true;
		m_HeightRatio = NULL;
		m_HasCaLight = false;
		m_CandleHp = 1.f;

	};

	/**
	* @fn void Init()
	* @brief 各種データを m_Id に基づいて初期化@n
	* 画像読み込み@n座標の指定@nアイテムの大きさを設定@n画像の大きさを設定@n
	*/
	void Init()override;

	/**
	* @fn void Update()
	* @brief 蝋燭の更新@n蝋燭の生死管理@nキャンドル明滅の管理@n
	* キャンドルが溶けて座標が下がる処理
	*/
	void Update()override;

	/**
	* @fn void Draw()
	* @brief m_Id に基づいて描画@n
	* 蝋燭の場合 => ヘルスに応じて溶けるように描画される@n
	* それ以外   => 指定された座標とサイズで描画
	*/
	void Draw() override;

	/**
	* @fn float GetHp()
	* @brief インスタンス化して利用する
	* @return float インスタンスの m_CandleHp を返す
	*/
	float GetHp()override	  { return m_CandleHp;	 };

	/**
	* @fn float GetRatio()
	* @brief インスタンス化して利用する
	* @return float インスタンスの m_HeightRatio を返す
	*/
	float GetRatio()override  { return m_HeightRatio;};

	/**
	* @fn float HasCaLight()
	* @brief インスタンス化して利用する
	* @return float インスタンスの m_HasCaLight を返す
	*/
	bool HasCaLight()override {	return m_HasCaLight; };

private:
	/**
	* Update内で使用される関数群
	*/

	/**
	* @fn void SceneDeath()
	* @brief GameScene 以外でキャンドルを死亡させる@n
	* GameView 情報によってキャンドルの生死を管理する@n
	*/
	void SceneDeath();

	/**
	* @fn void SceneDeath()
	* @brief キャンドルの生死を管理するスイッチ
	* @param[in] center_switch_  true だと CANDLE_CENTER 生存
	* @param[in] left_switch_  true だと CANDLE_LEFT 生存
	* @param[in] right_switch_  true だと CANDLE_RIGHT 生存
	*/
	void CandleSwitch(bool center_switch_, bool left_switch_, bool right_switch_);

	/**
	* @fn void MeltCandle(ObjID id_)
	* @brief キャンドルを溶かすために計算する関数
	* @param[in] id_ 指定したキャンドルを溶かす
	*/
	void MeltCandle(ObjID id_);

	/**
	* @fn void EffectUpdate()
	* @brief キャンドルエフェクトの生死情報を管理
	*/
	void EffectUpdate();

private:
	//! @brief キャンドルが点灯情報
	bool m_HasCaLight;

	//! @brief キャンドルのHP
	float m_CandleHp; 

	//! @brief キャンドルの高さ比率
	float m_HeightRatio; 
};

