#ifndef SAKURA_H_
#define SAKURA_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/*
	バニー(エネミー)のクラス
*/
class Sakura : public Enemy
{
public:
	/*
		コンストラクタ
	*/
	Sakura() :
		Enemy(RoomID::ROOM_WORK, EnemyID::SAKURA)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}

		m_AnimationTex.m_Counter = 0;
		m_AnimationTex.m_Length = 3;
		m_AnimationTex.m_Speed = 60;
		m_AnimationTex.m_KillingCounter = 0.f;


		for (int i = 0; i < m_AnimationTex.m_Length; i++) {
			m_AnimationTex.m_TextureData[i] = new Texture();
		}
	}
	/*
		デストラクタ
	*/
	virtual ~Sakura(){}
	/*
		初期化
	*/
	virtual void Init() override;

	/*
		挙動
	*/
	virtual void Update() override;
	/*
		m_IsKillを返す
	*/
	virtual bool HasKill()const final { return m_HasKill; }
	/*
		引数に現在のシーンを入れる
		テクスチャのロード
	*/
	virtual void LoadTex() override;
	/*
		描画
	*/
	virtual void Draw() override;

	/*
		キルアニメーション
	*/
	virtual void KillAnimation() override;


private:
	const CharacterID m_CharId = CharacterID::SAKURA;// キャラID定数

};

#endif