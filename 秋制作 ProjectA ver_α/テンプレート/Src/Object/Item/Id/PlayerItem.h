#pragma once

/**
* オブジェクトの葉（最終継承先）\n
* 水晶を管理するクラスを格納
*/

#include "../Item.h"
#include "../../../Scene/Scene.h"
#include "../../../Engine/Calculation.h"
#include "../../../Timer/Timer.h"
#include "../../../Engine/Input.h"
#include "../../../Scene/GameScene/GameData.h"

/**
* @brief 水晶を管理するクラス
*/
class Crystal : public Item {
public:
	Crystal() { m_IsDeath = true; };	//!< コンストラクタ
	~Crystal() {};						//!< デストラクタ

	/**
	*@fn void Init()
	*@brief 水晶の初期化\n
	*		テクスチャの読み込み\n
	*		座標の指定\n
	*		オブジェクトサイズの指定
	*/
	void Init()override {

		LoadTexture("Res/Game/Item/Crystal.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCrystalTex);
		LoadTexture("Res/Game/Item/crystal_effect.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameOnHitCrystalTex);

		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCrystalTex);	
		m_pOnHitTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameOnHitCrystalTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = CRYSTAL_POS;
		m_Size = CRYSTAL_SIZE;

	};

	/**
	*@fn void Update()
	*@brief 水晶の更新\n
	*		ゲームシーン以外では死亡\n
	*		死んでいなければ当たり判定を取る\n
	*/
	void Update()override {

		if (GetCurrentSceneId() == GameScene) {

			if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER) {
				m_IsDeath = false;
			}
			else {
				m_IsDeath = true;

			}
		}
		else {
			m_IsDeath = true;
		}

		if (m_IsDeath == false) {
			if (HasRectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
				m_OnMouse = true;
			}
			else {
				m_OnMouse = false;
			}
		}
	}


	/**
	*@fn void Draw()
	*@brief 水晶の描画\n
	*		死亡していなければ描画\n
	*		マウスオーバーでエフェクトの追加\n
	*/
	void Draw()override {

		if (m_IsDeath == false) {
			if (m_OnMouse == true) {
				DrawTexture(m_Pos, m_pOnHitTex);
			}
			DrawTexture(m_Pos.X, m_Pos.Y, m_pTex);
		}
	}

private:
	Texture* m_pOnHitTex;
};

/**
* @brief 時計を管理するクラス
*/
class Watch : public Item {
public:
	Watch() { m_IsDeath = true; };	//!< コンストラクタ
	~Watch() {};						//!< デストラクタ

	/**
	*@fn void Init()
	*@brief 水晶の初期化\n
	*		テクスチャの読み込み\n
	*		座標の指定\n
	*		オブジェクトサイズの指定
	*/
	void Init()override {

		LoadTexture("Res/Game/Item/pocket_watch.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameWatchTex);
		LoadTexture("Res/Game/Item/pocket_watch.pngl_effect.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameOnHitWatchlTex);

		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameWatchTex);
		m_pOnHitTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameOnHitWatchlTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = WATCH_POS;
		m_Size = WATCH_SIZE;

	};

	/**
	*@fn void Update()
	*@brief 水晶の更新\n
	*		ゲームシーン以外では死亡\n
	*		死んでいなければ当たり判定を取る\n
	*/
	void Update()override {

		if (GetCurrentSceneId() == GameScene) {

			if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER) {
				m_IsDeath = false;
			}
			else {
				m_IsDeath = true;

			}
		}
		else {
			m_IsDeath = true;
		}

		if (m_IsDeath == false) {
			if (HasRectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
				m_OnMouse = true;
			}
			else {
				m_OnMouse = false;
			}
		}
	}


	/**
	*@fn void Draw()
	*@brief 水晶の描画\n
	*		死亡していなければ描画\n
	*		マウスオーバーでエフェクトの追加\n
	*/
	void Draw()override {

		if (m_IsDeath == false) {
			if (m_OnMouse == true) {
				DrawTexture(m_Pos, m_pOnHitTex);
			}
			DrawTexture(m_Pos.X, m_Pos.Y, m_pTex);
		}
	}

private:
	Texture* m_pOnHitTex;
};

