#ifndef BOTAN_H_
#define BOTAN_H_

/**
*	@file Botan.h
*	@author 中本
*	@brief キャラクター「牡丹」を管理するクラスを処理
*/


#include "../../Enemy/Enemy.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"


/**
* @brief	エネミー[ボタン]を管理するクラス
* @details	ボタンの挙動や描画を実装している
*/
class Botan : public Enemy
{
public:
	/**
	* @fn		Botan()
	* @brief	コンストラクタ
	*/
	Botan() :
		Enemy(RoomID::ROOM_VOID, EnemyID::BOTAN)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}

		m_AnimationTex.m_Counter = 0;
		m_AnimationTex.m_Length = 3;
		m_AnimationTex.m_Speed = 15;

		for (int i = 0; i < m_AnimationTex.m_Length; i++) {
			m_AnimationTex.m_TextureData[i] = new Texture();
		}
	}

	/**
	* @fn		~Botan()
	* @brief	デストラクタ
	*/
	virtual ~Botan(){}

	/**
	* @fn		void Init()
	* @brief	初期化関数
	*/
	virtual void Init() override;

	/**
	* @fn		void Update()
	* @brief	更新関数
	*/
	virtual void Update() override;

	/**
	* @fn		void Draw()
	* @brief	描画関数
	*/
	virtual void Draw() override;

	/**
	* @fn		void KillAnimation()
	* @brief	キルアニメーションの描画関数
	*/
	virtual void KillAnimation() override;

	/**
	* @fn		bool SpawnJudgement() const
	* @brief	m_SpawnJudgementを返す
	* @return	bool
	*/
	bool SpawnJudgement() const override { return m_SpawnJudgement; }

private:

	bool m_SpawnJudgement;	//! ボタンがスポーンしてもいいかどうかを保存する変数
};

#endif