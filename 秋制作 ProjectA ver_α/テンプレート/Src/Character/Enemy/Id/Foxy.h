#ifndef FOXY_H_
#define FOXY_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"
#include "../../../Texture/Texture.h"

/*
	フォクシー(エネミー)のクラス
*/
class Ran : public Enemy
{
public:
	/*
		コンストラクタ
	*/
	Ran() :
		Enemy(RoomID::ROOM_STORAGE, 0)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}

	}
	/*
		デストラクタ
	*/
	virtual ~Ran(){}
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
	virtual void LoadTex(SceneId id_) final;
	/*
	描画
	*/
	virtual void Draw() override;

	/*
		キルアニメーション
	*/
	virtual void KillAnimation() override;

private:
	// キャラID定数
	const CharacterID m_CharId = CharacterID::RAN;
	
	// アニメーション
	Texture* KillAnimationTex[3];
};

#endif 