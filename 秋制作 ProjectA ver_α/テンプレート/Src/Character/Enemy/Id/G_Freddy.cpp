#include "G_Freddy.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"

void G_Freddy::Init()
{
	m_HasKill = false;
	m_pPlayer = g_Manager.GetCharacter(PLAYER);
	if (m_pPlayer == nullptr) {

		return;
	}
}

void G_Freddy::Update()
{

}

void G_Freddy::LoadTex(SceneId id_)
{
}

void G_Freddy::Draw()
{
}
