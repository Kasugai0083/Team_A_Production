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
	m_Charas[PLAYER] = new Player;	//アルファ

	m_Charas[FREDDY] = new Freddy;		//アルファ
	m_Charas[BONNIE] = new Bonnie;
	m_Charas[CHICA]  = new Chica;		//アルファ
	m_Charas[FOXY]   = new Foxy;
	m_Charas[G_FREDDY] = new G_Freddy;
	m_Charas[PUPPET] = new Puppet;		//アルファ
}

CharacterManager::~CharacterManager() {
	Release();
}

void CharacterManager::Initialize() {
	

	for (int i = 0; i < MAX_CHARACTER; i++) {
		m_Charas[i]->Init();
	}
}

void CharacterManager::Update()
{
	for (int i = 0; i < MAX_CHARACTER; i++) {
		m_Charas[i]->Update();
	}
}

void CharacterManager::Draw()
{
	for (int i = 0; i < MAX_CHARACTER; i++) {
		m_Charas[i]->Draw();
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
		m_Charas[i]->LoadTex(id);
	}
}

bool CharacterManager::RefKill() {
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (m_Charas[i]->HasKill() == true) {
			return true;
		}
	}
	return false;
}