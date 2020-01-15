#pragma once

/**
* オブジェクトの親(派生元)@n
* UI や Item に派生するクラスを格納
*/

#include "../Utility/Vec.h"
#include "../Utility/Size.h"
#include "../Texture/Texture.h"
#include "ObjectID.h"

/**
* @brief オブジェクトを管理するクラス
*/
class Object {
public:
	//! コンストラクタ
	Object() {};	
	//! デストラクタ
	~Object() {};	

	//! Init の純仮想関数
	virtual void Init() = 0;		

	//! Update の純仮想関数
	virtual void Update() = 0;		

	//! HasOnMouse の純仮想関数
	virtual bool HasOnMouse() = 0;	
	
	//! Draw の純仮想関数
	virtual void Draw() = 0;		

	/**
	* @fn float GetHp()
	* @brief Candle クラスで使用する GaetHp() の仮想関数
	* Candle をインスタンス化して使用する
	*/
	virtual float GetHp() { return 0; }; 

	/**
	* @fn float GetHp()
	* @brief Candle クラスで使用する GaetHp() の仮想関数
	* Candle をインスタンス化して使用する
	*/
	virtual float GetRatio() { return 0; };

	/**
	* @fn float HasCaLight()
	* @brief Candle クラスで使用する HasCaLight() の仮想関数
	* Candle をインスタンス化して使用する
	*/
	virtual bool HasCaLight() { return 0; };

	/**
	* @fn bool HasMas()
	* @brief UI クラスで使用する HasMask() の仮想関数
	* UI をインスタンス化して使用する
	*/
	virtual bool HasMask() { return 0; };

	virtual void LoadTex() { return ; }

protected:
	//! オブジェクトの生存情報
	bool m_IsDeath;
	//! オブジェクトの識別番号
	ObjID m_Id;		

private:

};
