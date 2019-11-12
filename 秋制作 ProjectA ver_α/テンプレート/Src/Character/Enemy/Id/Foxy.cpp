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
#pragma region éQè∆ópïœêî
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);
	if (pPlayer == nullptr) {

		return;
	}
#pragma endregion

}

void Foxy::LoadTex(SceneId id_)
{
}

void Foxy::Draw()
{
}
