#ifndef FREDDY_H_
#define FREDDY_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/*
	フレディ(エネミー)のクラス
*/
class Ohagi : public Enemy
{
public:
	/*
		コンストラクタ
	*/
	Ohagi() :
		Enemy(RoomID::ROOM_WORK, 0, false)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}
	}
	/*
		デストラクタ
	*/
	virtual ~Ohagi(){}
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
	const CharacterID m_CharId = CharacterID::OHAGI;// キャラID定数
};

#endif