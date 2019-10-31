#include "Foxy.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"

void Foxy::Init()
{
	m_iFrameCount = 0;
	m_IsDeath     = true;
	m_HasKill     = false;
	m_RoomId      = RoomID::SPAWN_ROOM;
}

void Foxy::Update()
{
#pragma region 参照用変数
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
