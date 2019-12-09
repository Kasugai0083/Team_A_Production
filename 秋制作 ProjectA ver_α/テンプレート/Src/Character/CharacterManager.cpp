#include "CharacterManager.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "CharacterID.h"
#include "Enemy/Id/Bonnie.h"
#include "Enemy/Id/Chica.h"
#include "Enemy/Id/Foxy.h"
#include "Enemy/Id/Freddy.h"
#include "Enemy/Id/G_Freddy.h"
#include "Enemy/Id/Puppet.h"

CharacterManager g_Manager;

CharacterManager::CharacterManager() {
	m_Charas[PLAYER]	= new Player;

	m_Charas[OHAGI]     = new Ohagi;
	m_Charas[UME]		= new Ume;
	m_Charas[SAKURA]    = new Sakura;
	m_Charas[RAN]	    = new Ran;
	m_Charas[BOTAN]		= new Botan;
	m_Charas[MARGARET]  = new Margaret;
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
	for (int i = 0; i < MAX_CHARACTER; i++) {
		if (m_Charas[i] != nullptr) {

			m_Charas[i]->Draw();
		}
	}
}


void CharacterManager::Release()
{
	for (int i = 0; i < MAX_CHARACTER; i++) {
		delete m_Charas[i];
		m_Charas[i] = nullptr;
	}
}

void CharacterManager::LoadTex(SceneId id) {
	for (int i = 0; i < MAX_CHARACTER; i++) {
		if (m_Charas[i] != nullptr) {

			m_Charas[i]->LoadTex(id);
		}
	}
}

bool CharacterManager::RefKill() {
	for (int i = OHAGI; i <= ENEMY_NUM; i++) {
		if (m_Charas[i]->HasKill() == true) {

			return true;
		}
	}
	return false;
}