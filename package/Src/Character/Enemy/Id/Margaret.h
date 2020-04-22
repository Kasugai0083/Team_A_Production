#ifndef MARGARET_H_
#define MARGARET_H_

/**
*	@file	Margaret.h
*	@author 中本
*	@brief	キャラクター「マーガレット」を管理するクラスを処理
*/


#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/EnemyTex.h"


/**
* @brief	エネミー[マーガレット]を管理するクラス
* @details	マーガレットの挙動や描画を実装している
*/
class Margaret : public Enemy
{
public:
	/**
	* @fn		Margaret()
	* @brief	コンストラクタ
	*/
	Margaret() :
		Enemy(RoomID::ROOM_CHILDREN, EnemyID::MARGARET)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}

		m_iFrameCount = 3600;
		m_AnimationTex.m_Counter = 0;
		m_AnimationTex.m_Length = 3;
		m_AnimationTex.m_Speed = 15;

		for (int i = 0; i < m_AnimationTex.m_Length; i++) {
			m_AnimationTex.m_TextureData[i] = new Texture();
		}
	}

	/**
	* @fn		~Margaret()
	* @brief	デストラクタ
	*/
	virtual ~Margaret(){}

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

private:
	const int MAX_COUNT = 3600;

	int m_TextureCategory = EnemyCategoryTextureList::MARGARET_PIZA_9;
};

#endif