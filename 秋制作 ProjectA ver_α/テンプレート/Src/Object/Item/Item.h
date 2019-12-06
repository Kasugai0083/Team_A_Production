#ifndef ITEM_H_
#define ITEM_H_

/**
* オブジェクトの継承クラス@n
* Candle, Fire, PlayerItem class に派生
*/


#include "../../Utility/Vec.h"
#include "../../Utility/Size.h"
#include "../../Texture/Texture.h"
#include "../Object.h"
#include "ItemValue.h"

/**
* @brief 最終継承先に使えそうな関数や変数を格納するクラス
*/
class Item : public Object {
public:

	Item();		//!< コンストラクタ
	~Item();	//!< デストラクタ

	void Draw()override;
	void Update()override;

	bool HasOnMouse()override;
	
protected:
	Texture* m_pTex;
	bool m_OnMouse;
	Vec2 m_Pos;
	Size m_Size;
	Size m_Frame;


};

#endif