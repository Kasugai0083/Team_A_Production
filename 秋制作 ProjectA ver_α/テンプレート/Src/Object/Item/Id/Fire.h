/**
*	@file Botan.h
*	@author 春日井
*	@brief キャラクター「牡丹」を管理するクラスを処理
*/

#pragma once

/**
* オブジェクトの葉（最終継承先）@n
* 蝋燭の火を管理するクラスを格納
*/

#include "../Item.h"
#include "../../../Scene/Scene.h"
#include "Candle.h"
#include "../../ObjectManager.h"

/**
* @brief 蝋燭の火を管理するクラス@n
*/
class Fire : public Item {
public:

	/**
	* @fn Fire(ObjID id_)
	* @brief コンストラクタ@nメンバ変数の初期化@n
	* @param[in] id_ で指定された ObjID を代入
	*/
	Fire(ObjID id_) {
		m_Id = id_;
		m_IsDeath = true;
	}

	/**
	* @fn void Init()
	* @brief 各種データを m_Id に基づいて初期化@n
	* 画像読み込み@n座標の指定@nアイテムの大きさを設定@n画像の大きさを設定@n
	* m_Id に基づいて Candle をインスタンス化
	*/
	void Init()override;

	/**
	* @fn void Update()
	* @brief 蝋燭の点灯情報に基づいて、火を更新@n
	* 火の生死管理@n
	* 蝋燭が溶けて火の座標が下がる処理
	*/
	void Update()override;

	/**
	* @fn void Draw()
	* @brief 蝋燭の点灯情報と自身の生存情報に基づいて描画@n
	*/
	void Draw()override;

private:
	/**
	* Update内で使用されている関数
	*/

	//! GameView 情報から生存情報を管理
	void SceneDeath();

	//! 生存情報を引数によって管理
	void FireSwitch(bool center_switch_, bool left_switch_, bool right_switch_);
private:
	//! @brief 蝋燭情報の取得用変数
	Object* m_pObject;	
};
