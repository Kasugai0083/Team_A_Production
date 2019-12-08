#ifndef G_FREDDY_H_
#define G_FREDDY_H_

#include "../../Enemy/Enemy.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/*
	ゴールデンフレディ(エネミー)のクラス
*/
class Botan : public Enemy
{
public:
	/*
		コンストラクタ
	*/
	Botan() :
		Enemy(RoomID::ROOM_PRAYER, 0)
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
	virtual ~Botan(){}
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
		生成するかしないかの判定関数
		プレイヤーがモニターシーンの時に使う。
		trueで生成する
	*/
	bool SpawnJudgement(double probability_);

	// m_SpawnJudgementを返す
	bool SpawnJudgement() const override { return m_SpawnJudgement; }

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
	// キャラID定数
	const CharacterID m_CharId = CharacterID::BOTAN;

	// 試しに作ってみた
	// SpawnJudgement関数を使ったかどうか
	bool m_SpawnJudgement;
};

#endif