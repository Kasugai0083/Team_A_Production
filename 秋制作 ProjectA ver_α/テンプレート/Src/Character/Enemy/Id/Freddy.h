#ifndef FREDDY_H_
#define FREDDY_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"

/*
	フレディ(エネミー)のクラス
*/
class Freddy : public Enemy
{
public:
	Freddy();
	virtual ~Freddy() final;
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
	const CharacterID m_CharId = CharacterID::FREDDY;// キャラID定数
};

#endif