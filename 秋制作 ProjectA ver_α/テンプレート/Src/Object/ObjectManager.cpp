#include "ObjectManager.h"
#include "UI/UI.h"
#include "Item/Item.h"
#include "ObjectID.h"
#include "../Engine/Input.h"
#include "Item/Id/Candle.h"
#include "Item/Id/Fire.h"
#include "Item/Id/PlayerItem.h"
#include "Item/Id/Fire.h"

ObjectManager* ObjManager() {
	static ObjectManager obj;
	return &obj;
}

ObjectManager::ObjectManager() {


	m_pObjects[static_cast<int>(ObjID::CANDLE_RIGHT)]				= new Candle(ObjID::CANDLE_RIGHT);
	m_pObjects[static_cast<int>(ObjID::CANDLE_EFFECT_RIGHT)]		= new Candle(ObjID::CANDLE_EFFECT_RIGHT);

	m_pObjects[static_cast<int>(ObjID::CANDLE_LEFT)]				= new Candle(ObjID::CANDLE_LEFT);
	m_pObjects[static_cast<int>(ObjID::CANDLE_EFFECT_LEFT)]			= new Candle(ObjID::CANDLE_EFFECT_LEFT);

	m_pObjects[static_cast<int>(ObjID::CANDLE_CENTER)]				= new Candle(ObjID::CANDLE_CENTER);
	m_pObjects[static_cast<int>(ObjID::CANDLE_EFFECT_CENTER)]		= new Candle(ObjID::CANDLE_EFFECT_CENTER);

	m_pObjects[static_cast<int>(ObjID::CANDLE_STAND)]				= new Candle(ObjID::CANDLE_STAND);

	m_pObjects[static_cast<int>(ObjID::FIRE_CENTER)]				= new Fire(ObjID::FIRE_CENTER);
	m_pObjects[static_cast<int>(ObjID::FIRE_RIGHT)]					= new Fire(ObjID::FIRE_RIGHT);
	m_pObjects[static_cast<int>(ObjID::FIRE_LEFT)]					= new Fire(ObjID::FIRE_LEFT);
		
	m_pObjects[static_cast<int>(ObjID::CRYSTAL)]					= new Crystal;

	m_pObjects[static_cast<int>(ObjID::TITLE_LOGO)]					= new UI(ObjID::TITLE_LOGO);
	m_pObjects[static_cast<int>(ObjID::BUTTON_NEW_GAME)]			= new UI(ObjID::BUTTON_NEW_GAME);
	m_pObjects[static_cast<int>(ObjID::BUTTON_CONTINUE)]			= new UI(ObjID::BUTTON_CONTINUE);
		
	m_pObjects[static_cast<int>(ObjID::GAME_BASE_UI)]				= new UI(ObjID::GAME_BASE_UI);

	m_pObjects[static_cast<int>(ObjID::BUTTON_CONTROL_UI)]			= new UI(ObjID::BUTTON_CONTROL_UI);
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_CONTROL_UI)]			= new UI(ObjID::BUTTON_ON_CONTROL_UI);
	
	m_pObjects[static_cast<int>(ObjID::MO_MASK_UI)]					= new UI(ObjID::MO_MASK_UI);
	m_pObjects[static_cast<int>(ObjID::DESCRIPTION_UI)]				= new UI(ObjID::DESCRIPTION_UI);
			
	m_pObjects[static_cast<int>(ObjID::BUTTON_WORKSHOP)]			= new UI(ObjID::BUTTON_WORKSHOP);
	m_pObjects[static_cast<int>(ObjID::BUTTON_STORE_ROOM)]			= new UI(ObjID::BUTTON_STORE_ROOM);
	m_pObjects[static_cast<int>(ObjID::BUTTON_RECEPTION_ROOM)]		= new UI(ObjID::BUTTON_RECEPTION_ROOM);
	m_pObjects[static_cast<int>(ObjID::BUTTON_CHILD_ROOM)]			= new UI(ObjID::BUTTON_CHILD_ROOM);
	m_pObjects[static_cast<int>(ObjID::BUTTON_RIGHT_CORRIDOR)]		= new UI(ObjID::BUTTON_RIGHT_CORRIDOR);
	m_pObjects[static_cast<int>(ObjID::BUTTON_LEFT_CORRIDOR)]		= new UI(ObjID::BUTTON_LEFT_CORRIDOR);
			
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_WORKSHOP)]			= new UI(ObjID::BUTTON_ON_WORKSHOP);
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_STORE_ROOM)]		= new UI(ObjID::BUTTON_ON_STORE_ROOM);
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_RECEPTION_ROOM)]	= new UI(ObjID::BUTTON_ON_RECEPTION_ROOM);
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_CHILD_ROOM)]		= new UI(ObjID::BUTTON_ON_CHILD_ROOM);
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_RIGHT_CORRIDOR)]	= new UI(ObjID::BUTTON_ON_RIGHT_CORRIDOR);
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_LEFT_CORRIDOR)]	= new UI(ObjID::BUTTON_ON_LEFT_CORRIDOR);
	
	m_pObjects[static_cast<int>(ObjID::MONITOR_MAP)]				= new UI(ObjID::MONITOR_MAP);
	m_pObjects[static_cast<int>(ObjID::PLAYER_ROOM)]				= new UI(ObjID::PLAYER_ROOM);
	m_pObjects[static_cast<int>(ObjID::CLEAR_LOGO)]					= new UI(ObjID::CLEAR_LOGO);


	for (auto& objects : m_pObjects) {
		if (objects == nullptr) {
			return;
		}
	}

}

ObjectManager::~ObjectManager() {
	Release();
}

void ObjectManager::Init() {

	for (auto& objects : m_pObjects) {
		if (objects == nullptr) {
			continue;
		}
		objects->Init();
	}
}

void ObjectManager::Update()
{
	for (auto& objects : m_pObjects) {
		if (objects == nullptr) {
			continue;
		}
		objects->Update();
	}
}

void ObjectManager::Draw()
{

	for (auto& objects : m_pObjects) {
		if (objects == nullptr) {
			continue;
		}
		objects->Draw();
	}

}

void ObjectManager::Release(int id) {

	delete m_pObjects[id];
	m_pObjects[id] = nullptr;
}


void ObjectManager::Release()
{
	for (auto& objects : m_pObjects) {
		if (objects == nullptr) {
			continue;
		}
		delete objects;
		objects = nullptr;
	}
}

bool ObjectManager::HasOnMouse(ObjID id_) {
	if (m_pObjects[static_cast<int>(id_)]->HasOnMouse() == true) {
		return true;
	}
	return false;
}


void ObjectManager::InitCount() {

	m_pObjects[static_cast<int>(ObjID::CANDLE_CENTER)]->InitCount();
	
}
