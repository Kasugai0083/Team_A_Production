#include "Bonnie.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Scene/GameScene/GameData.h"

void Ume::Init()
{
}

void Ume::Update()
{
	m_iFrameCount++;

	if (m_IsDeath == true && m_iFrameCount >= 2900) {

		m_iFrameCount = 0;
		m_IsDeath = false;
		m_RoomId = RoomID::ROOM_WORK;
	}

	if (m_IsDeath == true) { return; }
	// 死んでたらここより下の処理にはいかない

#pragma region ウメの移動
	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::ROOM_RECEPTION;
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::LEFT_CORRIDOR;
		}
		break;

	case RoomID::LEFT_CORRIDOR:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::LEFT_SHOJI;
		}
		break;

	case RoomID::LEFT_SHOJI:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::ROOM_LEFT_PRAYER;
		}
		break;
	}
#pragma endregion

	switch (m_RoomId)
	{
	case RoomID::LEFT_SHOJI:

		if (m_pPlayer->HasMask() == true) {

			m_iFrameCount = 0;
			m_IsDeath = true;
		}

		if (m_iFrameCount >= 300) {
			// ゲームオーバー処理
			m_HasKill = true;
		}
		break;
	}

}

void Ume::LoadTex(SceneId id_)
{
}

void Ume::Draw()
{
}
