#ifndef PUPPET_H_
#define PUPPET_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"

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
		Enemy(RoomID::ROOM_CHILDREN, 0, false)
	{}
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
};

#endif