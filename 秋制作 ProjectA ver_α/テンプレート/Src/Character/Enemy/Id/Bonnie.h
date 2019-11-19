#ifndef BONNIE_H_
#define BONNIE_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"

/*
	バニー(エネミー)のクラス
*/
class Bonnie : public Enemy
{
public:
	/*
		コンストラクタ
	*/
	Bonnie() :
		Enemy(RoomID::ROOM_WORK, 0)
	{}
	/*
		デストラクタ
	*/
	virtual ~Bonnie() final{}
	/*
		初期化
	*/
	virtual void Init() final;

	/*
		挙動
	*/
	virtual void Update() final;
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
	virtual void Draw() final;

private:
	const CharacterID m_CharId = CharacterID::BONNIE;// キャラID定数

};

#endif