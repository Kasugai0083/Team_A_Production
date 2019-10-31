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
#include "Item/Id/Candle.h"
#include "Item/Id/Fire.h"
#include "Item/Id/PlayerItem.h"

//ObjectManager g_ObjManager;

ObjectManager* ObjManager() {
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

		m_Objects[object::CANDLE_BIG] = new CandleBig;
		m_Objects[object::CANDLE_SMALL] = new CandleSmall;
		m_Objects[object::CANDLE_EFFECT] = new CandleEffect;
		m_Objects[object::CANDLE_STAND] = new CandleStand;
		m_Objects[object::FIRE_BIG] = new FireBig;
		m_Objects[object::FIRE_SMALL] = new FireSmall;
		m_Objects[object::CRYSTAL] = new Crystal;
		m_Objects[object::MUSICBOX] = new MusicBox;

}

ObjectManager::~ObjectManager() {
	Release();
}

void ObjectManager::Init() {


	for (int i = 0; i < object::MAX_OBJECT_NUM; i++) {
		m_Objects[i]->Init();
	}
}

void ObjectManager::Init(object::ObjectId id_, Vec2 pos_) {

	m_Objects[id_]->Init(pos_);

}

void ObjectManager::Update()
{
	for (int i = 0; i < object::MAX_OBJECT_NUM; i++) {
		m_Objects[i]->Update();
	}
}

void ObjectManager::Draw(object::ObjectId id)
{
	m_Objects[id]->Draw();
}


void ObjectManager::Release()
{
	for (int i = 0; i < object::MAX_OBJECT_NUM; i++) {
		delete m_Objects[i];
		m_Objects[i] = nullptr;
	}
}

bool ObjectManager::HasOnMouse(object::ObjectId id) {

	if (m_Objects[id]->HasOnMouse() == true) {
		return true;
	}
	return false;
}

