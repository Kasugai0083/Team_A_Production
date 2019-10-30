#include "Enemy.h"
#include "../CharacterManager.h"
#include "../CharacterID.h"
#include "../../Src/Scene/Scene.h"
#include "../../Src/Engine/Graphics.h"
#include "../../Src/Texture/Texture.h"
#include "..//..//Timer/Timer.h"
#include "..//..//Scene/Scene.h"

//////////////////////////////////////////////
//　仮
class Timar {

public:
	int GetTime() {
		return m_Time;
	}

	int GetMusicBox() {
		return m_MusicBox;
	}

private:
	int m_Time;
	int m_MusicBox;
};
////////////////////////////////////////////////
Timar g_time;

void Enemy::Init()
{
	m_FrameCount = 0; 
	m_IsDeath = true;
	m_IsPlayerKill = false;
}

void Enemy::Update()
{
	m_FrameCount++;

#pragma region 参照用変数
	Character* player = g_Manager.GetCharacter(PLAYER);

	Character* freddy   = g_Manager.GetCharacter(FREDDY);
	Character* bonnie   = g_Manager.GetCharacter(BONNIE);
	Character* chica    = g_Manager.GetCharacter(CHICA);
	Character* foxy     = g_Manager.GetCharacter(FOXY);
	Character* g_freddy = g_Manager.GetCharacter(G_FREDDY);
	Character* puppet   = g_Manager.GetCharacter(PUPPET);

	Timar* timer = &g_time;
#pragma endregion

	switch (m_Id)
	{
	case FREDDY:
		// フレディの処理start
		if (m_IsDeath == true &&  m_FrameCount >= 600) {

			m_FrameCount = 0;
			m_IsDeath = false;
			m_RoomId = RoomID::SPAWN_ROOM;
		}

		if (m_IsDeath == true) { return; }
		// 死んでたらここより下の処理にはいかない

		if (m_FrameCount >= 800 && m_RoomId == RoomID::SPAWN_ROOM) {

			m_FrameCount = 0;
			m_RoomId = RoomID::CENTER_DUCT;
		}

		if (m_FrameCount >= 1000 && m_RoomId == RoomID::CENTER_DUCT) {
			m_FrameCount = 0;
			m_RoomId = RoomID::PLAYER_ROOM;
		}

		if (m_FrameCount >= 180 && m_RoomId == RoomID::PLAYER_ROOM) {
			//ゲームオーバー処理
			m_IsPlayerKill = true;
		}

		if (m_RoomId == RoomID::PLAYER_ROOM && player->GetIsMask() == true) {

			m_IsDeath = true;
			m_FrameCount = 0;
		}		

		// フレディの処理end----------------------------------------------------------------------------------
		break;
	case BONNIE:
		// バニーの処理start
		if (m_IsDeath == true) { return; }


		// バニーの処理end------------------------------------------------------------------------------------
		break;
	case CHICA:
		// チカの処理start
		if (m_IsDeath == true && m_FrameCount == 1200) {

			m_FrameCount = 0;
			m_IsDeath = false;
			m_RoomId = RoomID::SPAWN_ROOM;
		}

		if (m_IsDeath == true) { return; }
		// 死んでたらここより下の処理にはいかない

		if (m_FrameCount >= 1200 && m_RoomId == RoomID::SPAWN_ROOM) {

			m_FrameCount = 0;
			m_RoomId = RoomID::RIGHT_DUCT;
		}

		if (m_FrameCount >= 1200 && m_RoomId == RoomID::RIGHT_DUCT) {

			m_FrameCount = 0;
			m_RoomId = RoomID::RIGHT_ROOM;
		}
		if (m_FrameCount >= 1200 && m_RoomId == RoomID::RIGHT_ROOM) {

			m_FrameCount = 0;
			m_RoomId = RoomID::PLAYER_ROOM;
		}

		if (m_FrameCount >= 120 && m_RoomId == RoomID::PLAYER_ROOM) {
			// ゲームオーバー処理
			m_IsPlayerKill = true;
		}

		if (m_RoomId == RoomID::PLAYER_ROOM && player->GetIsMask() == true) {

			m_IsDeath = true;
			m_FrameCount = 0;
		}

		// チカの処理end----------------------------------------------------------------------------------------
		break;
	case FOXY:
		// フォクシーの処理start
		if (m_IsDeath == true) { return; }

		// フォクシーの処理end-----------------------------------------------------------------------------------
		break;
	case G_FREDDY:
		// Gフレディーの処理start
		if (m_IsDeath == true) { return; }

		// Gフレディーの処理end----------------------------------------------------------------------------------
		break;
	case PUPPET:
		// パペットの処理start
		if (m_IsDeath == true && TimerFunc()->Get(Timer::Id::MusicBox) <= 900) {

			m_FrameCount = 0;
			m_IsDeath = false;
		}

		if (m_IsDeath == true) { return; }
		// 死んでたらここより下の処理にはいかない

		if (m_FrameCount >= 1200) {
			// ↓ゲームオーバー処理↓ //
			
		}

		// パペットの処理end
		break;

	default:
		break;
	}
}


void Enemy::Draw()
{
	switch (m_Id)
	{
	case FREDDY:
		// フレディの処理start
		if (m_IsDeath == true) { return; }
		
		if (GetCurrentSceneId() == SceneId::MonitorScene && m_RoomId == RoomID::SPAWN_ROOM
			&& MonitorFunc()->Get() == MonitorTransition::Id::Spown) {
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorFreddy));
		}

		if (GetCurrentSceneId() == SceneId::CenterScene && m_RoomId == RoomID::CENTER_DUCT) {
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterFreddy));
		}


		// フレディの処理end
		break;
	case BONNIE:
		// バニーの処理start
		if (m_IsDeath == true) { return; }


		// バニーの処理end
		break;
	case CHICA:
		// チカの処理start
		if (m_IsDeath == true) { return; }

		if (GetCurrentSceneId() == SceneId::MonitorScene && m_RoomId == RoomID::SPAWN_ROOM
			&& MonitorFunc()->Get() == MonitorTransition::Id::Spown) {

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChicaTex));
		}

		if (GetCurrentSceneId() == SceneId::MonitorScene && m_RoomId == RoomID::RIGHT_DUCT
			&& MonitorFunc()->Get() == MonitorTransition::Id::Right_Duct) {

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChicaTex));
		}

		if (GetCurrentSceneId() == SceneId::RightScene && m_RoomId == RoomID::RIGHT_ROOM) {

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightChicaTex));
		}
		// チカの処理end
		break;
	case FOXY:
		// フォクシーの処理start
		if (m_IsDeath == true) { return; }

		// フォクシーの処理end
		break;
	case G_FREDDY:
		// Gフレディーの処理start
		if (m_IsDeath == true) { return; }

		// Gフレディーの処理end
		break;
	case PUPPET:
		// パペットの処理start
		if (m_IsDeath == true) { return; }

		
		
		// パペットの処理end
		break;

	default:
		break;
	}
}

void Enemy::LoadTex(SceneId id) {
	switch(id)
	{
	case CenterScene:
		LoadTexture("Res/Game/Enemy/Freddy.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterFreddy);
		LoadTexture("Res/Game/Enemy/The_Puppet.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterPuppet);
		break;
	case RightScene:
		LoadTexture("Res/Game/Enemy/Chica.png", TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightChicaTex);
		break;
	case LeftScene:

		break;
	case MonitorScene:
		LoadTexture("Res/Game/Enemy/Freddy.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorFreddy);
		LoadTexture("Res/Game/Enemy/Chica.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChicaTex);
		LoadTexture("Res/Game/Enemy/The_Puppet.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPuppetTex);
		break;

	default:
		break;
	}
}
