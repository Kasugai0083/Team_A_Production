#include "CharacterManager.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "CharacterID.h"
#include "Enemy/Id/Sakura.h"
#include "Enemy/Id/Ume.h"
#include "Enemy/Id/Oran.h"
#include "Enemy/Id/Ohagi.h"
#include "Enemy/Id/Botan.h"
#include "Enemy/Id/Margaret.h"

CharacterManager g_Manager;

CharacterManager::CharacterManager() {
}

CharacterManager::~CharacterManager() {
	Release();
}

void CharacterManager::Initialize() {
	

	for (int i = 0; i < MAX_CHARACTER; i++) {
		if (m_Charas[i] != nullptr) {

			m_Charas[i]->Init();
		}
	}
}

void CharacterManager::Update()
{
	for (int i = 0; i < MAX_CHARACTER; i++) {
		if (m_Charas[i] != nullptr) {

			m_Charas[i]->Update();
		}
	}
}

void CharacterManager::Draw()
{

	for (int i = 1; i < MAX_CHARACTER; i++) {
		if (m_Charas[i] != nullptr) {

			m_Charas[i]->Draw();
		}
	}

	m_Charas[PLAYER]->Draw();

}


void CharacterManager::Release()
{
	//Character�̗̈�����
	for (int i = 0; i < MAX_CHARACTER; i++) {
		delete m_Charas[i];
		m_Charas[i] = nullptr;
	}
}

void CharacterManager::KillAnimation()
{
	for (int i = OHAGI; i <= ENEMY_NUM; i++) {
		if (m_Charas[i] != nullptr) {
			m_Charas[i]->KillAnimation();
		}
	}
}

bool CharacterManager::HasKill()
{
	for (int i = OHAGI; i <= ENEMY_NUM; i++) {
		if (m_Charas[i]->HasKill() == true) {

			return true;
		}
	}
	return false;
}

const bool CharacterManager::CanKill() const
{
	for (int i = OHAGI; i <= ENEMY_NUM; i++) {
		if (m_Charas[i]->CanKill() == true) {

			return true;
		}
	}
	return false;
}

void CharacterManager::CreateCharacter()
{
	for (int i = 0; i < MAX_CHARACTER; i++) {
		if (m_Charas[i] != nullptr) {
			return;
		}
	}

	m_Charas[PLAYER]   = new Player;

	m_Charas[OHAGI]    = new Ohagi;
	m_Charas[SAKURA]   = new Sakura;
	m_Charas[UME]      = new Ume;
	m_Charas[RAN]      = new Ran;
	m_Charas[BOTAN]    = new Botan;
	m_Charas[MARGARET] = new Margaret;
}

bool CharacterManager::IsSameRoom(RoomID roomId_)
{
	for (int i = CharacterID::OHAGI; i <= ENEMY_NUM; i++)
	{
		if (m_Charas[i]->GetRoomID() == roomId_)
		{
			return true;
		}
	}

	return false;
}

