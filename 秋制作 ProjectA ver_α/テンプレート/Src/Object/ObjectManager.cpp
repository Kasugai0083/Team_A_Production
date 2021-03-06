#include "ObjectManager.h"
#include "UI/UI.h"
#include "Item/Item.h"
#include "../Engine/Input.h"
#include "Item/Id/Candle.h"
#include "Item/Id/Fire.h"
#include "Item/Id/PlayerItem.h"
#include "../Texture/Texture.h"

ObjectManager* ObjManager() 
{
	static ObjectManager obj;
	return &obj;
}

ObjectManager::ObjectManager() 
{

	for (auto& objects : m_pObjects) 
	{
		if (objects == nullptr) 
		{
			return;
		}
	}

}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::Init()
{

	for (auto& objects : m_pObjects) 
	{
		if (objects == nullptr)
		{
			continue;
		}
		objects->Init();
	}
}

void ObjectManager::Update()
{
	for (auto& objects : m_pObjects) 
	{
		if (objects == nullptr)
		{
			continue;
		}
		objects->Update();
	}
}

void ObjectManager::Draw()
{

	for (auto& objects : m_pObjects)
	{
		if (objects == nullptr) 
		{
			continue;
		}
		objects->Draw();
	}

}

void ObjectManager::LoadTex() 
{
	for (auto& objects : m_pObjects) 
	{
		if (objects == nullptr) 
		{
			continue;
		}
		objects->LoadTex();
	}
}

void ObjectManager::Release(ObjID id_) 
{

	delete m_pObjects[static_cast<int>(id_)];
	m_pObjects[static_cast<int>(id_)] = nullptr;
}

void ObjectManager::ReleaseTitleObj() 
{
	delete m_pObjects[static_cast<int>(ObjID::TITLE_LOGO)];
	m_pObjects[static_cast<int>(ObjID::TITLE_LOGO)] = nullptr;

	delete m_pObjects[static_cast<int>(ObjID::BUTTON_NEW_GAME)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_NEW_GAME)] = nullptr;

	delete m_pObjects[static_cast<int>(ObjID::BUTTON_CONTINUE)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_CONTINUE)] = nullptr;

	ReleaseCategoryTexture(TEXTURE_CATEGORY_TITLE_OBJECT);

}

void ObjectManager::ReleaseGameObj() 
{
	delete m_pObjects[static_cast<int>(ObjID::CANDLE_RIGHT)];
	m_pObjects[static_cast<int>(ObjID::CANDLE_RIGHT)] = nullptr;

	delete m_pObjects[static_cast<int>(ObjID::CANDLE_EFFECT_RIGHT)];
	m_pObjects[static_cast<int>(ObjID::CANDLE_EFFECT_RIGHT)] = nullptr;

	delete m_pObjects[static_cast<int>(ObjID::CANDLE_LEFT)];
	m_pObjects[static_cast<int>(ObjID::CANDLE_LEFT)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::CANDLE_EFFECT_LEFT)];
	m_pObjects[static_cast<int>(ObjID::CANDLE_EFFECT_LEFT)] = nullptr;

	delete m_pObjects[static_cast<int>(ObjID::CANDLE_CENTER)];
	m_pObjects[static_cast<int>(ObjID::CANDLE_CENTER)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::CANDLE_EFFECT_CENTER)];
	m_pObjects[static_cast<int>(ObjID::CANDLE_EFFECT_CENTER)] = nullptr;

	delete m_pObjects[static_cast<int>(ObjID::CANDLE_STAND_CENTER)];
	m_pObjects[static_cast<int>(ObjID::CANDLE_STAND_CENTER)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::CANDLE_STAND_LEFT)];
	m_pObjects[static_cast<int>(ObjID::CANDLE_STAND_LEFT)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::CANDLE_STAND_RIGHT)];
	m_pObjects[static_cast<int>(ObjID::CANDLE_STAND_RIGHT)] = nullptr;

	delete m_pObjects[static_cast<int>(ObjID::FIRE_CENTER)];
	m_pObjects[static_cast<int>(ObjID::FIRE_CENTER)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::FIRE_RIGHT)];
	m_pObjects[static_cast<int>(ObjID::FIRE_RIGHT)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::FIRE_LEFT)];
	m_pObjects[static_cast<int>(ObjID::FIRE_LEFT)] = nullptr;

	delete m_pObjects[static_cast<int>(ObjID::CRYSTAL)];
	m_pObjects[static_cast<int>(ObjID::CRYSTAL)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::POCKET_WATCH)];
	m_pObjects[static_cast<int>(ObjID::POCKET_WATCH)] = nullptr;

	delete m_pObjects[static_cast<int>(ObjID::GAME_BASE_UI)];
	m_pObjects[static_cast<int>(ObjID::GAME_BASE_UI)] = nullptr;

	delete m_pObjects[static_cast<int>(ObjID::BUTTON_CONTROL_UI)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_CONTROL_UI)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::BUTTON_ON_CONTROL_UI)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_CONTROL_UI)] = nullptr;

	delete m_pObjects[static_cast<int>(ObjID::MO_MASK_UI)];
	m_pObjects[static_cast<int>(ObjID::MO_MASK_UI)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::DESCRIPTION_UI)];
	m_pObjects[static_cast<int>(ObjID::DESCRIPTION_UI)] = nullptr;

	delete m_pObjects[static_cast<int>(ObjID::BUTTON_WORKSHOP)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_WORKSHOP)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::BUTTON_STORE_ROOM)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_STORE_ROOM)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::BUTTON_RECEPTION_ROOM)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_RECEPTION_ROOM)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::BUTTON_CHILD_ROOM)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_CHILD_ROOM)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::BUTTON_RIGHT_CORRIDOR)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_RIGHT_CORRIDOR)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::BUTTON_LEFT_CORRIDOR)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_LEFT_CORRIDOR)] = nullptr;

	delete m_pObjects[static_cast<int>(ObjID::BUTTON_ON_WORKSHOP)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_WORKSHOP)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::BUTTON_ON_STORE_ROOM)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_STORE_ROOM)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::BUTTON_ON_RECEPTION_ROOM)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_RECEPTION_ROOM)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::BUTTON_ON_CHILD_ROOM)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_CHILD_ROOM)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::BUTTON_ON_RIGHT_CORRIDOR)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_RIGHT_CORRIDOR)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::BUTTON_ON_LEFT_CORRIDOR)];
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_LEFT_CORRIDOR)] = nullptr;

	delete m_pObjects[static_cast<int>(ObjID::MONITOR_MAP)];
	m_pObjects[static_cast<int>(ObjID::MONITOR_MAP)] = nullptr;
	delete m_pObjects[static_cast<int>(ObjID::MONITOR_PLAYER)];
	m_pObjects[static_cast<int>(ObjID::MONITOR_PLAYER)] = nullptr;

	ReleaseCategoryTexture(TEXTURE_CATEGORY_GAME_OBJECT);
}

void ObjectManager::CreateTitleObj()
{
	m_pObjects[static_cast<int>(ObjID::TITLE_LOGO)] = new UI(ObjID::TITLE_LOGO);
	m_pObjects[static_cast<int>(ObjID::BUTTON_NEW_GAME)] = new UI(ObjID::BUTTON_NEW_GAME);
	m_pObjects[static_cast<int>(ObjID::BUTTON_CONTINUE)] = new UI(ObjID::BUTTON_CONTINUE);
}
void ObjectManager::CreateGameObj()
{

	m_pObjects[static_cast<int>(ObjID::CANDLE_RIGHT)] = new Candle(ObjID::CANDLE_RIGHT);
	m_pObjects[static_cast<int>(ObjID::CANDLE_EFFECT_RIGHT)] = new Candle(ObjID::CANDLE_EFFECT_RIGHT);

	m_pObjects[static_cast<int>(ObjID::CANDLE_LEFT)] = new Candle(ObjID::CANDLE_LEFT);
	m_pObjects[static_cast<int>(ObjID::CANDLE_EFFECT_LEFT)] = new Candle(ObjID::CANDLE_EFFECT_LEFT);

	m_pObjects[static_cast<int>(ObjID::CANDLE_CENTER)] = new Candle(ObjID::CANDLE_CENTER);
	m_pObjects[static_cast<int>(ObjID::CANDLE_EFFECT_CENTER)] = new Candle(ObjID::CANDLE_EFFECT_CENTER);

	m_pObjects[static_cast<int>(ObjID::CANDLE_STAND_CENTER)] = new Candle(ObjID::CANDLE_STAND_CENTER);
	m_pObjects[static_cast<int>(ObjID::CANDLE_STAND_LEFT)] = new Candle(ObjID::CANDLE_STAND_LEFT);
	m_pObjects[static_cast<int>(ObjID::CANDLE_STAND_RIGHT)] = new Candle(ObjID::CANDLE_STAND_RIGHT);

	m_pObjects[static_cast<int>(ObjID::FIRE_CENTER)] = new Fire(ObjID::FIRE_CENTER);
	m_pObjects[static_cast<int>(ObjID::FIRE_RIGHT)] = new Fire(ObjID::FIRE_RIGHT);
	m_pObjects[static_cast<int>(ObjID::FIRE_LEFT)] = new Fire(ObjID::FIRE_LEFT);

	m_pObjects[static_cast<int>(ObjID::CRYSTAL)] = new Crystal;
	m_pObjects[static_cast<int>(ObjID::POCKET_WATCH)] = new Watch;

	m_pObjects[static_cast<int>(ObjID::GAME_BASE_UI)] = new UI(ObjID::GAME_BASE_UI);

	m_pObjects[static_cast<int>(ObjID::BUTTON_CONTROL_UI)] = new UI(ObjID::BUTTON_CONTROL_UI);
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_CONTROL_UI)] = new UI(ObjID::BUTTON_ON_CONTROL_UI);

	m_pObjects[static_cast<int>(ObjID::MO_MASK_UI)] = new UI(ObjID::MO_MASK_UI);
	m_pObjects[static_cast<int>(ObjID::DESCRIPTION_UI)] = new UI(ObjID::DESCRIPTION_UI);

	m_pObjects[static_cast<int>(ObjID::BUTTON_WORKSHOP)] = new UI(ObjID::BUTTON_WORKSHOP);
	m_pObjects[static_cast<int>(ObjID::BUTTON_STORE_ROOM)] = new UI(ObjID::BUTTON_STORE_ROOM);
	m_pObjects[static_cast<int>(ObjID::BUTTON_RECEPTION_ROOM)] = new UI(ObjID::BUTTON_RECEPTION_ROOM);
	m_pObjects[static_cast<int>(ObjID::BUTTON_CHILD_ROOM)] = new UI(ObjID::BUTTON_CHILD_ROOM);
	m_pObjects[static_cast<int>(ObjID::BUTTON_RIGHT_CORRIDOR)] = new UI(ObjID::BUTTON_RIGHT_CORRIDOR);
	m_pObjects[static_cast<int>(ObjID::BUTTON_LEFT_CORRIDOR)] = new UI(ObjID::BUTTON_LEFT_CORRIDOR);

	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_WORKSHOP)] = new UI(ObjID::BUTTON_ON_WORKSHOP);
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_STORE_ROOM)] = new UI(ObjID::BUTTON_ON_STORE_ROOM);
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_RECEPTION_ROOM)] = new UI(ObjID::BUTTON_ON_RECEPTION_ROOM);
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_CHILD_ROOM)] = new UI(ObjID::BUTTON_ON_CHILD_ROOM);
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_RIGHT_CORRIDOR)] = new UI(ObjID::BUTTON_ON_RIGHT_CORRIDOR);
	m_pObjects[static_cast<int>(ObjID::BUTTON_ON_LEFT_CORRIDOR)] = new UI(ObjID::BUTTON_ON_LEFT_CORRIDOR);

	m_pObjects[static_cast<int>(ObjID::MONITOR_MAP)] = new UI(ObjID::MONITOR_MAP);
	m_pObjects[static_cast<int>(ObjID::MONITOR_PLAYER)] = new UI(ObjID::MONITOR_PLAYER);
}

void ObjectManager::Release()
{
	for (auto& objects : m_pObjects)
	{
		if (objects == nullptr)
		{
			continue;
		}
		delete objects;
		objects = nullptr;
	}
	ReleaseCategoryTexture(TEXTURE_CATEGORY_TITLE_OBJECT);
	ReleaseCategoryTexture(TEXTURE_CATEGORY_GAME_OBJECT);
}

bool ObjectManager::HasOnMouse(ObjID id_)
{
	if (m_pObjects[static_cast<int>(id_)]->HasOnMouse() == true) {
		return true;
	}
	return false;
}
