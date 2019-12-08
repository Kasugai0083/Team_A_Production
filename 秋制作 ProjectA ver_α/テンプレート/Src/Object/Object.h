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

	Object() {}; //!< コンストラクタ
	~Object() {}; //!< デストラクタ

	virtual void Init() = 0; //!< Init の仮想関数

	virtual void Update() = 0;

	virtual bool HasOnMouse() = 0;
	
	virtual void Draw() = 0;

	virtual Vec2 GetPos() { return m_Pos; };
	virtual float GetHp() { return 0; };
	virtual float GetRatio() { return 0; };
	virtual bool HasCaLight() { return 0; };

	virtual bool HasMask() { return 0; };
protected:

	bool m_IsDeath;
	ObjID m_Id;

private:
	Vec2 m_Pos;
};
