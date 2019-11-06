#include "Bonnie.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Scene/GameScene/GameData.h"

void Bonnie::Init()
{
	m_iFrameCount = 0;
	m_IsDeath	 = true;
	m_HasKill	 = false;
	m_RoomId	 = RoomID::SPAWN_ROOM;
}

void Bonnie::Update()
{
#pragma region éQè∆ópïœêî
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);
	if (pPlayer == nullptr) {

		return;
	}
#pragma endregion

}

void Bonnie::LoadTex(SceneId id_)
{
}

void Bonnie::Draw()
{
}
