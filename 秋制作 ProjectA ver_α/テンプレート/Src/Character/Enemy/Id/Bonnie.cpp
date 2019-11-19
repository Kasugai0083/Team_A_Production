#include "Bonnie.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Scene/GameScene/GameData.h"

void Bonnie::Init()
{
	m_HasKill = false;
	m_pPlayer = g_Manager.GetCharacter(PLAYER);
	if (m_pPlayer == nullptr) {

		return;
	}
}

void Bonnie::Update()
{
}

void Bonnie::LoadTex(SceneId id_)
{
}

void Bonnie::Draw()
{
}
