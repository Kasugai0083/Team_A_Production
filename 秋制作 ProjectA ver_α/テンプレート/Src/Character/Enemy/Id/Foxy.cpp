#include "Foxy.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"

void Foxy::Init()
{
	m_iFrameCount = 0;
	m_IsDeath     = true;
	m_HasKill     = false;
	m_RoomId      = RoomID::ROOM_STORAGE;
}

void Foxy::Update()
{
#pragma region 参照用変数
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);
	if (pPlayer == nullptr) {

		return;
	}
#pragma endregion

	m_iFrameCount++;

	if (m_IsDeath == true && m_iFrameCount >= 300) {

		m_iFrameCount = 0;
		m_IsDeath     = false;
		m_RoomId      = RoomID::ROOM_STORAGE;
	}

	if (m_IsDeath == true) { return; }
	// 死んでたらここより下の処理にはいかない

#pragma region フォクシーの移動
	switch (m_RoomId)
	{
	case RoomID::ROOM_STORAGE:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::HALL_BACK;
		}
		break;

	case RoomID::HALL_BACK:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::HALL_FRONT;
		}
		break;

	case RoomID::HALL_FRONT:
		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::ROOM_PRAYER;
		}
		break;
	default:
		break;
	}
#pragma endregion

	switch (m_RoomId)
	{
	case RoomID::HALL_BACK:
	case RoomID::HALL_FRONT:

		if (pPlayer->HasLight() == true) {

			m_iFrameCount = 0;
		}
		break;

	case RoomID::ROOM_PRAYER:

		m_iFrameCount = 0;
		m_HasKill = true;
		break;
	default:
		break;
	}
}

void Foxy::LoadTex(SceneId id_)
{
}

void Foxy::Draw()
{
}
