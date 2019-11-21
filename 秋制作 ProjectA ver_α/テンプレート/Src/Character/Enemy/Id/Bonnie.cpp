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
	// Ž€‚ñ‚Å‚½‚ç‚±‚±‚æ‚è‰º‚Ìˆ—‚É‚Í‚¢‚©‚È‚¢

#pragma region ƒEƒ‚ÌˆÚ“®
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

}

void Ume::LoadTex(SceneId id_)
{
}

void Ume::Draw()
{
}
