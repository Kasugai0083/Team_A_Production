#ifndef PUPPET_H_
#define PUPPET_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/EnemyTex.h"


/*
	パペット(エネミー)のクラス
*/	
class Margaret : public Enemy
{
public:
	/*
		コンストラクタ
	*/
	Margaret() :
		Enemy(RoomID::ROOM_CHILDREN, 360000)
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
	/*
		デストラクター
	*/
	virtual ~Margaret(){}

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
	virtual bool HasKill()const override { return m_HasKill; }

	/*
		引数に現在のシーンを入れる
		テクスチャのロード
	*/
	virtual void LoadTex(SceneId id_) override;
	/*
		描画
	*/
	virtual void Draw() override;

	/*
		キルアニメーション
	*/
	virtual void KillAnimation() override;

private:
	const CharacterID m_CharId = CharacterID::MARGARET;// キャラID定数
	const int MAX_COUNT = 3600;

	int m_TextureCategory = EnemyCategoryTextureList::MargaretPiza9;
};

#endif