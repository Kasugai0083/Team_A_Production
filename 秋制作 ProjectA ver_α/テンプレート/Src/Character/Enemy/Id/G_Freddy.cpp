#include "G_Freddy.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"

G_Freddy::G_Freddy()
{
}

G_Freddy::~G_Freddy()
{
}

void G_Freddy::Init()
{
	m_iFrameCount = 0;
	m_IsDeath     = true;
	m_HasKill     = false;
	m_RoomId      = RoomID::ROOM_PRAYER;
}

void G_Freddy::Update()
{
#pragma region QÆ—p•Ï”
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
