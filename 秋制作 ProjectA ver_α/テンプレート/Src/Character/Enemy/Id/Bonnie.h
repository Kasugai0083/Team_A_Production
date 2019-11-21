#ifndef BONNIE_H_
#define BONNIE_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/*
	バニー(エネミー)のクラス
*/
class Ume : public Enemy
{
public:
	/*
		コンストラクタ
	*/
	Ume():
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
	virtual ~Ume(){}
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
	virtual void LoadTex(SceneId id_) override;
	/*
	描画
	*/
	virtual void Draw() override;

private:
	const CharacterID m_CharId = CharacterID::UME;// キャラID定数

};

#endif