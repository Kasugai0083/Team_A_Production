#ifndef OHAGI_H_
#define OHAGI_H_

/**
*	@file	Ohagi.h
*	@author 中本
*	@brief	キャラクター「オハギ」を管理するクラスを処理
*/


#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/**
* @brief	エネミー[オハギ]を管理するクラス
* @details	オハギの挙動や描画を実装している
*/
class Ohagi : public Enemy
{
public:
	/**
	* @fn		Ohagi()
	* @brief	コンストラクタ
	*/
	Ohagi() :
		Enemy(RoomID::ROOM_WORK, EnemyID::OHAGI)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}

		m_AnimationTex.m_Counter = 0;
		m_AnimationTex.m_Length  = 3;
		m_AnimationTex.m_Speed   = 15;

		for (int i = 0; i < m_AnimationTex.m_Length; i++) {
			m_AnimationTex.m_TextureData[i] = new Texture();
		}
	}

	/**
	* @fn		~Ohagi()
	* @brief	デストラクタ
	*/
	virtual ~Ohagi(){}

	/**
	* @fn		void Init()
	* @brief	初期化関数
	*/
	virtual void Init() override;

	/**
	* @fn		void Init()
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
};

#endif