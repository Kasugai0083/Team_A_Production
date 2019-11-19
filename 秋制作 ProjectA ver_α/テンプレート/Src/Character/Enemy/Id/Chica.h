#ifndef CHICA_H_
#define CHICA_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/*
	チカ(エネミー)のクラス
*/
class Chica : public Enemy
{
public:
	/*
		コンストラクタ
	*/
	Chica() :
		Enemy(RoomID::ROOM_WORK, 0, false)
	{
	}
	/*
		デストラクタ
	*/
	virtual ~Chica(){}
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

private:
	const CharacterID m_CharId = CharacterID::CHICA;// キャラID定数

};

#endif