#include "Foxy.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"

void Ran::Init()
{
}

void Ran::Update()
{
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

		if (m_pPlayer->HasLight() == true) {

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

void Ran::LoadTex(SceneId id_)
{
}

void Ran::Draw()
{
}
