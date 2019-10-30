#include "CharacterManager.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "CharacterID.h"

CharacterManager g_Manager;

CharacterManager::CharacterManager() {
	m_Charas[PLAYER] = new Player;	//アルファ

	m_Charas[FREDDY] = new Enemy(FREDDY);		//アルファ
	m_Charas[BONNIE] = new Enemy(BONNIE);
	m_Charas[CHICA]  = new Enemy(CHICA);		//アルファ
	m_Charas[FOXY]   = new Enemy(FOXY);
	m_Charas[G_FREDDY] = new Enemy(G_FREDDY);
	m_Charas[PUPPET] = new Enemy(PUPPET);		//アルファ
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
		if (m_Charas[i]->GetIsKill() == true) {
			return true;
		}
	}
	return false;
}