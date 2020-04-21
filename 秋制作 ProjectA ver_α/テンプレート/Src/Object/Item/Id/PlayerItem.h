/**
*	@file Botan.h
*	@author 春日井
*	@brief キャラクター「牡丹」を管理するクラスを処理
*/

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
#include "../..//..//Data/GameData.h"
#include "../../../Character/CharacterManager.h"

/**
* @brief 水晶を管理するクラス
*/
class Crystal : public Item {
public:
	//! コンストラクタ
	Crystal() { m_IsDeath = true; };
	//! デストラクタ
	~Crystal() {};						

	/**
	*@fn void Init()
	*@brief 水晶の初期化@n
	*テクスチャの読み込み@n
	*座標の指定@n
	*オブジェクトサイズの指定
	*/
	void Init()override {


		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CRYSTAL_TEX);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = CRYSTAL_POS;
		m_Size = CRYSTAL_SIZE;

	};

	/**
	*@fn void Update()
	*@brief 水晶の更新\n
	*ゲームシーン以外では死亡\n
	*死んでいなければ当たり判定を取る\n
	*/
	void Update()override {

		Character* pPlayer = g_Manager.GetCharacter(PLAYER);

		if (pPlayer->HasMonitor() == false) {
			if (GetCurrentSceneId() == GameScene) {

				if (pPlayer->CurrentViewID() == SubGameScene::CENTER_VIEW) {
					m_IsDeath = false;
				}
				else {
					m_IsDeath = true;
				}
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
	*死亡していなければ描画\n
	*マウスオーバーでエフェクトの追加\n
	*/
	void Draw()override {

		if (m_IsDeath == false) {
			/*if (m_OnMouse == true) {
				DrawTexture(m_Pos, m_pOnHitTex);
			}*/
			DrawTexture(m_Pos.X, m_Pos.Y, m_pTex);
		}
	}

private:
	//! マウスオーバー時の画像
	Texture* m_pOnHitTex;
};

/**
* @brief 時計を管理するクラス
*/
class Watch : public Item {
public:
	//! コンストラクタ
	Watch() { m_IsDeath = true; };
	//! デストラクタ
	~Watch() {};					

	/**
	*@fn void Init()
	*@brief 時計の初期化\n
	*テクスチャの読み込み\n
	*座標の指定\n
	*オブジェクトサイズの指定
	*/
	void Init()override {


		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_WATCH_TEX);
		m_pOnHitTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_ONHITWATCH_TEX);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = WATCH_POS;
		m_Size = WATCH_SIZE;

	};

	/**
	*@fn void Update()
	*@brief 時計の更新\n
	*ゲームシーン以外では死亡\n
	*死んでいなければ当たり判定を取る\n
	*/
	void Update()override {

		Character* pPlayer = g_Manager.GetCharacter(PLAYER);

		if (pPlayer->HasMonitor() == false) {
			if (GetCurrentSceneId() == GameScene) {

				if (pPlayer->CurrentViewID() == SubGameScene::CENTER_VIEW) {
					m_IsDeath = false;
				}
				else {
					m_IsDeath = true;
					m_OnMouse = false;
				}
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

		if (pPlayer->HasMask() == true) {
			m_OnMouse = false;
		}

	}


	/**
	*@fn void Draw()
	*@brief 時計の描画\n
	*死亡していなければ描画\n
	*マウスオーバーでエフェクトの追加\n
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
	//! マウスオーバー時の画像
	Texture* m_pOnHitTex;
};

