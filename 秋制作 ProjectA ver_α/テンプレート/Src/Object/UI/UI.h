/**
*	@file UI.h
*	@author 春日井
*	@brief オブジェクトの葉（最終継承先）
*	@brief ユーザーインターフェースを管理するクラスを処理
*/

#ifndef UI_H_
#define UI_H_

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

		m_Tex = nullptr;
		m_Tex2 = nullptr;
		m_OnHitTex = nullptr;
		m_OnHitTex2 = nullptr;

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

	/**
	* @fn void UpdateTitleUI()
	* @brief TitleScene で使われている UI の更新処理
	*/
	void UpdateTitleUI();

private:
	//! テクスチャの情報を格納
	Texture* m_Tex, *m_OnHitTex;
	Texture* m_Tex2, *m_OnHitTex2;
	//! マスク着脱情報
	bool m_HasMask;	
	//! マウスが重なったとき true
	bool m_OnMouse;		
	//! 座標情報
	Vec2 m_Pos;			
	//! サイズ情報
	Size m_Size;		

};

#endif