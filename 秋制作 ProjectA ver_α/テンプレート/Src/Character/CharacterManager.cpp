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
	m_Charas[PLAYER]	= new Player;

	m_Charas[OHAGI]     = new Ohagi;
	m_Charas[SAKURA]	= new Sakura;
	m_Charas[UME]		= new Ume;
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

void CharacterManager::LoadTex() {
	for (int i = 0; i < MAX_CHARACTER; i++) {
		if (m_Charas[i] != nullptr) {

			m_Charas[i]->LoadTex();
		}
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

bool CharacterManager::RefKill() {
	for (int i = OHAGI; i <= ENEMY_NUM; i++) {
		if (m_Charas[i]->HasKill() == true) {

			return true;
		}
	}
	return false;
}

