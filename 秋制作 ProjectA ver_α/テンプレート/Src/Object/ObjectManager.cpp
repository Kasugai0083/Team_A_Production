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
#include "UI/UIID.h"
#include "Item/Id/Fire.h"

ObjectManager* ObjManager() {
	static ObjectManager obj;
	return &obj;
}

ObjectManager::ObjectManager() {
	m_pUI[TITLE_LOGO] = new UI(UIType::NONE, TITLE_LOGO);

	m_pUI[BUTTON_NEW_GAME] = new UI(UIType::NONE, BUTTON_NEW_GAME);
	m_pUI[BUTTON_CONTINUE] = new UI(UIType::NONE, BUTTON_CONTINUE);
	m_pUI[BUTTON_WORKSHOP] = new UI(UIType::NONE, BUTTON_WORKSHOP);
	m_pUI[BUTTON_STORE_ROOM] = new UI(UIType::NONE, BUTTON_STORE_ROOM);
	m_pUI[BUTTON_RECEPTION_ROOM] = new UI(UIType::NONE, BUTTON_RECEPTION_ROOM);
	m_pUI[BUTTON_CHILD_ROOM] = new UI(UIType::NONE, BUTTON_CHILD_ROOM);
	m_pUI[BUTTON_RIGHT_CORRIDOR] = new UI(UIType::NONE, BUTTON_RIGHT_CORRIDOR);
	m_pUI[BUTTON_LEFT_CORRIDOR] = new UI(UIType::NONE, BUTTON_LEFT_CORRIDOR);

	m_pUI[BUTTON_ON_WORKSHOP] = new UI(UIType::NONE, BUTTON_ON_WORKSHOP);
	m_pUI[BUTTON_ON_STORE_ROOM] = new UI(UIType::NONE, BUTTON_ON_STORE_ROOM);
	m_pUI[BUTTON_ON_RECEPTION_ROOM] = new UI(UIType::NONE, BUTTON_ON_RECEPTION_ROOM);
	m_pUI[BUTTON_ON_CHILD_ROOM] = new UI(UIType::NONE, BUTTON_ON_CHILD_ROOM);
	m_pUI[BUTTON_ON_RIGHT_CORRIDOR] = new UI(UIType::NONE, BUTTON_ON_RIGHT_CORRIDOR);
	m_pUI[BUTTON_ON_LEFT_CORRIDOR] = new UI(UIType::NONE, BUTTON_ON_LEFT_CORRIDOR);

	m_pUI[MONITOR_MAP] = new UI(UIType::NONE, MONITOR_MAP);
	m_pUI[PLAYER_ROOM] = new UI(UIType::NONE, PLAYER_ROOM);
	m_pUI[CLEAR_LOGO] = new UI(UIType::NONE, CLEAR_LOGO);

	m_pObjects[object::CANDLE_RIGHT] = new Candle(CandleType::RIGHT_CANDLE);
	m_pObjects[object::CANDLE_LEFT] = new Candle(CandleType::LEFT_CANDLE);
	m_pObjects[object::CANDLE_CENTER] = new Candle(CandleType::CENTER_CANDLE);
	m_pObjects[object::CANDLE_EFFECT] = new Candle(CandleType::OTHER);
	m_pObjects[object::CANDLE_STAND] = new Candle(CandleType::OTHER);

	m_pObjects[object::FIRE_CENTER] = new Fire(FireID::CENTER_FIRE);
	m_pObjects[object::FIRE_RIGHT] = new Fire(FireID::RIGHT_FIRE);
	m_pObjects[object::FIRE_LEFT] = new Fire(FireID::LEFT_FIRE);

	m_pObjects[object::CRYSTAL] = new Crystal;
	m_pObjects[object::MUSICBOX] = new MusicBox;

	InitUI();

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

	m_pObjects[object::CANDLE_RIGHT]->Init(object::CANDLE_RIGHT);
	m_pObjects[object::CANDLE_LEFT]->Init(object::CANDLE_LEFT);
	m_pObjects[object::CANDLE_CENTER]->Init(object::CANDLE_CENTER);
	m_pObjects[object::CANDLE_EFFECT]->Init(object::CANDLE_EFFECT);
	m_pObjects[object::CANDLE_STAND]->Init(object::CANDLE_STAND);

}
void ObjectManager::InitUI() {


	for (int i = 0; i < MAX_UI_NUM; i++) {
		m_pUI[i]->Init();
	}

	for (int i = 0; i < MAX_UI_NUM; i++) {
		if (m_pUI == nullptr) {
			return;
		}
	}

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
	for (int i = 0; i < MAX_UI_NUM; i++) {
		m_pUI[i]->Update();
	}
}

void ObjectManager::Update(object::ObjectId id_)
{
	m_pObjects[id_]->Update();
}

void ObjectManager::UpdateUI(UserInterfaceID id_)
{
	m_pUI[id_]->Update();
}


void ObjectManager::Draw(object::ObjectId id_)
{
	m_pObjects[id_]->Draw();
}

void ObjectManager::Draw(object::ObjectId id_, Vec2 pos_)
{
	m_pObjects[id_]->Draw(pos_);
}

void ObjectManager::DrawUI(UserInterfaceID id_) {
	m_pUI[id_]->Draw();
}

void ObjectManager::SetPosition(object::ObjectId id_, Vec2 pos_) {
	m_pObjects[id_]->SetPosition(pos_);
}

void ObjectManager::Release()
{
	for (int i = 0; i < object::MAX_OBJECT_NUM; i++) {
		delete m_pObjects[i];
		m_pObjects[i] = nullptr;
	}	
	for (int i = 0; i < MAX_UI_NUM; i++) {
		delete m_pUI[i];
		m_pUI[i] = nullptr;
	}
}

bool ObjectManager::HasOnMouse(object::ObjectId id_) {

	if (m_pObjects[id_]->HasOnMouse() == true) {
		return true;
	}
	return false;
}
bool ObjectManager::HasOnMouseUI(UserInterfaceID id_) {

	if (m_pUI[id_]->HasOnMouse() == true) {
		return true;
	}
	return false;
}

bool ObjectManager::HasLight(CandleLight cl_) {
	return m_pObjects[object::CANDLE_CENTER]->HasLight(cl_);
}

void ObjectManager::InitCount() {
	m_pObjects[object::CANDLE_CENTER]->InitCount();
}
