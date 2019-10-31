#include "G_Freddy.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"

void G_Freddy::Init()
{
	m_iFrameCount = 0;
	m_IsDeath     = true;
	m_HasKill     = false;
	m_RoomId      = RoomID::SPAWN_ROOM;
}

void G_Freddy::Update()
{
#pragma region éQè∆ópïœêî
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);
	if (pPlayer == nullptr) {

		return;
	}
#pragma endregion

}

void G_Freddy::LoadTex(SceneId id_)
{
}

void G_Freddy::Draw()
{
}
