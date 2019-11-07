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

ObjectManager* ObjManager() {
	static ObjectManager obj;
	return &obj;
}

ObjectManager::ObjectManager() {

		m_pObjects[object::TITLE_LOGO] = new TitleLogo;
		m_pObjects[object::NEW_GAME] = new NewGame;
		m_pObjects[object::CONTINUE] = new Continue;
		m_pObjects[object::MONITOR_SPOWN] = new MonitorSpown;
		m_pObjects[object::BLACK_MONITOR_SPOWN] = new BlackMonitorSpown;
		m_pObjects[object::LEFT_DUCT] = new LeftDuct;
		m_pObjects[object::BLACK_LEFT_DUCT] = new BlackLeftDuct;
		m_pObjects[object::RIGHT_DUCT] = new RightDuct;
		m_pObjects[object::BLACK_RIGHT_DUCT] = new BlackRightDuct;
		m_pObjects[object::PLAYER_ROOM] = new PlayerRoom;
		m_pObjects[object::CLEAR_LOGO] = new TitleLogo;
		  
		m_pObjects[object::CANDLE_BIG] = new Candle;
		m_pObjects[object::CANDLE_SMALL] = new Candle;
		m_pObjects[object::CANDLE_EFFECT] = new Candle;
		m_pObjects[object::CANDLE_STAND] = new Candle;

		m_pObjects[object::FIRE_BIG] = new FireBig;
		m_pObjects[object::FIRE_SMALL] = new FireSmall;
		m_pObjects[object::CRYSTAL] = new Crystal;
		m_pObjects[object::MUSICBOX] = new MusicBox;

		for (int i = 0; i < object::MAX_OBJECT_NUM; i++) {
			if (m_pObjects == nullptr) {
				return;
			}
		}

}

ObjectManager::~ObjectManager() {
	Release();
}

void ObjectManager::Init() {
	for (int i = 0; i < object::MAX_OBJECT_NUM; i++) {
		m_pObjects[i]->Init();
	}

	m_pObjects[object::CANDLE_BIG]->Init(object::CANDLE_BIG);
	m_pObjects[object::CANDLE_SMALL]->Init(object::CANDLE_SMALL);
	m_pObjects[object::CANDLE_EFFECT]->Init(object::CANDLE_EFFECT);
	m_pObjects[object::CANDLE_STAND]->Init(object::CANDLE_STAND);

}

void ObjectManager::Init(object::ObjectId id_, Vec2 pos_) {

	m_pObjects[id_]->Init(pos_);
	m_pObjects[id_]->Init(id_, pos_);

}

void ObjectManager::Update()
{
	for (int i = 0; i < object::MAX_OBJECT_NUM; i++) {
		m_pObjects[i]->Update();
	}
}

void ObjectManager::Update(object::ObjectId id_)
{
	m_pObjects[id_]->Update();
}



void ObjectManager::Draw(object::ObjectId id_)
{
	m_pObjects[id_]->Draw();
}

void ObjectManager::Draw(object::ObjectId id_, Vec2 pos_)
{
	m_pObjects[id_]->Draw(pos_);
}


void ObjectManager::Release()
{
	for (int i = 0; i < object::MAX_OBJECT_NUM; i++) {
		delete m_pObjects[i];
		m_pObjects[i] = nullptr;
	}
}

bool ObjectManager::HasOnMouse(object::ObjectId id_) {

	if (m_pObjects[id_]->HasOnMouse() == true) {
		return true;
	}
	return false;
}

bool ObjectManager::HasCaLight(GameData::SubGameScene sce_) {
	switch (sce_)
	{
	case GameData::CENTER:
		return m_pObjects[object::CANDLE_BIG]->HasCenterCaLight();
		break;
	case GameData::LEFT:
		return m_pObjects[object::CANDLE_SMALL]->HasLeftCaLight();
		break;
	case GameData::RIGHT:
		return m_pObjects[object::CANDLE_SMALL]->HasRightCaLight();
		break;
	default:
		break;
	}
}


