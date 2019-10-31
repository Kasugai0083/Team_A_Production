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
	/*
		初期化
	*/
	void Init() override;

	/*
		挙動
	*/
	void Update() override;
	/*
		m_IsKillを返す
	*/
	bool HasKill()const override { return m_HasKill; }

	/*
		引数に現在のシーンを入れる
		テクスチャのロード
	*/
	void LoadTex(SceneId id_)override;
	/*
		描画
	*/
	void Draw() override;

private:
	const CharacterID m_CharId = CharacterID::FREDDY;// キャラID定数

	RoomID m_RoomId;		// どこの部屋にいるか変数
	int    m_iFrameCount;	// フレイムカウント用変数
	bool   m_IsDeath;		// 死んでるかどうか True:死んでいる False:生きている
	bool   m_HasKill;		// 殺したかどうか   True:殺した     False:殺してない
};

#endif