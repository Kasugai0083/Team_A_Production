#ifndef UI_H_
#define UI_H_

/**
* オブジェクトの葉（最終継承先）@n
* UserInterface を管理するクラスを格納
*/

#include "UIvalue.h"
#include "../../Texture/Texture.h"
#include "../Object.h"

/**
* @brief UIを管理するクラス@n
*/
class UI : public Object {
public:

	/**
	* @fn UI(ObjID id_)
	* @brief コンストラクタ@nメンバ変数の初期化@n
	* @param[in] id_ で指定された ObjID を代入
	*/
	UI(ObjID id_) {
		m_Id = id_;
		m_HasMask = false;
	};

	/**
	* @fn void Init()
	* @brief 各種データを m_Id に基づいて初期化@n
	* 画像読み込み@n座標の指定@nアイテムの大きさを設定@n
	*/
	void Init()override;

	/**
	* @fn void Update()
	* @brief UIの生存情報の更新@n
	* GameScene に実装されている UI の処理
	*/
	void Update()override;

	/**
	* @fn void Draw()
	* @brief 生存情報に基づいて描画@n
	* マウスが重なっている場合、黒ポリゴンを重ねる
	*/
	void Draw()override;

	/**
	* @fn bool HasOnMouse()
	* @brief m_OnMouse を取得する
	* @return マウスが重なっていた時 true@n
	* マウスが重なっていない時 false
	*/
	bool HasOnMouse()override {	return m_OnMouse; };

	/**
	* @fn bool HasMask()
	* @brief m_HasMask を取得する
	* @return マスクを被っている時 true@n
	* マスクを被っていない時 false
	*/
	bool HasMask()override { return m_HasMask; };

private:
	/**
	* Update で呼び出される関数
	*/

	/**
	* @fn void UpdateGameUI()
	* @brief GameScene で使われている UI の更新処理
	*/
	void UpdateGameUI();

private:
	Texture* m_Tex;		//!< テクスチャの情報を格納
	bool m_HasMask;		//!< マスク着脱情報
	bool m_OnMouse;		//!< マウスが重なったとき true
	Vec2 m_Pos;			//!< 座標情報
	Size m_Size;		//!< サイズ情報


};

#endif