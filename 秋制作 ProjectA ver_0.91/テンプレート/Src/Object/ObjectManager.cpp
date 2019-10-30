#include "ObjectManager.h"
#include "UI/UI.h"
#include "Item/Item.h"
#include "ObjectID.h"
#include "UI/Id/TitleLogo.h"
#include "UI/Id/RightDuct.h"
#include "UI/Id/LeftDuct.h"
#include "UI/Id/NewGame.h"
#include "UI/Id/Continue.h"
#include "UI/Id/MonitorSpown.h"
#include "UI/Id/PlayerRoom.h"
#include "../Engine/Input.h"

//ObjectManager g_ObjManager;

ObjectManager* UIManager() {
	static ObjectManager obj;
	return &obj;
}

ObjectManager::ObjectManager() {

		m_Objects[object::TITLE_LOGO] = new TitleLogo;
		m_Objects[object::NEW_GAME] = new NewGame;
		m_Objects[object::CONTINUE] = new Continue;
		m_Objects[object::MONITOR_SPOWN] = new MonitorSpown;
		m_Objects[object::BLACK_MONITOR_SPOWN] = new BlackMonitorSpown;
		m_Objects[object::LEFT_DUCT] = new LeftDuct;
		m_Objects[object::BLACK_LEFT_DUCT] = new BlackLeftDuct;
		m_Objects[object::RIGHT_DUCT] = new RightDuct;
		m_Objects[object::BLACK_RIGHT_DUCT] = new BlackRightDuct;
		m_Objects[object::PLAYER_ROOM] = new PlayerRoom;
		m_Objects[object::CLEAR_LOGO] = new TitleLogo;

}

ObjectManager::~ObjectManager() {
	Release();
}

void ObjectManager::Init() {


	for (int i = 0; i < object::MAX_UI_NUM; i++) {
		m_Objects[i]->Init();
	}
}

void ObjectManager::Update()
{
	for (int i = 0; i < object::MAX_UI_NUM; i++) {
		m_Objects[i]->Update();
	}
}

void ObjectManager::Draw(object::UserInterfaceId id)
{
	m_Objects[id]->Draw();
}


void ObjectManager::Release()
{
	for (int i = 0; i < object::MAX_UI_NUM; i++) {
		delete m_Objects[i];
		m_Objects[i] = nullptr;
	}
}

bool ObjectManager::HasOnMouse(object::UserInterfaceId id) {

	if (m_Objects[id]->HasOnMouse() == true) {
		return true;
	}
	return false;
}

