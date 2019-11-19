#ifndef G_FREDDY_H_
#define G_FREDDY_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"

/*
	ゴールデンフレディ(エネミー)のクラス
*/
class G_Freddy : public Enemy
{
public:
	/*
		コンストラクタ
	*/
	G_Freddy() :
		Enemy(RoomID::ROOM_PRAYER,0)
	{
	}
	/*
		デストラクター
	*/
	virtual ~G_Freddy() final{}
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
	const CharacterID m_CharId = CharacterID::G_FREDDY;// キャラID定数
};

#endif