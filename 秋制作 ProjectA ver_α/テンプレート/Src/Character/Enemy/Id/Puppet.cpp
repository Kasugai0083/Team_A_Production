#include "Puppet.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Timer/Timer.h"
#include "../../../Object/Item/Id/PlayerItem.h"

void Puppet::Init()
{
	m_iFrameCount = 0;
	m_IsDeath	  = true;
	m_HasKill	  = false;
	m_RoomId	  = RoomID::ROOM_CHILDREN;
}

void Puppet::Update()
{
	m_iFrameCount++;

		Timer* pTimerInstance = Timer::GetInstance();

		if (m_IsDeath == true && pTimerInstance->GetTime(Timer::Id::MUSICBOX) >= END_STEP) {

			m_iFrameCount = 0;
			m_IsDeath = false;
		}

		if (m_IsDeath == true) { return; }
		// 死んでたらここより下の処理にはいかない

		if (m_iFrameCount >= 300) {
			// ↓ゲームオーバー処理↓ //
			m_HasKill = true;
		}

}

void Puppet::LoadTex(SceneId id_)
{
	switch (id_)
	{
	case CenterScene:
		LoadTexture("Res/Game/Enemy/The_Puppet.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterPuppet);
		break;

	case MonitorScene:
		LoadTexture("Res/Game/Enemy/The_Puppet.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPuppetTex);
		break;
	default:
		break;
	}
}

void Puppet::Draw()
{
	if (m_IsDeath != true) { return; }
	// 生きていたらここより下の処理にはいかない

	if (GetCurrentSceneId() == SceneId::MonitorScene 
		&& MonitorFunc()->Get() == MonitorTransition::Id::Spown) {

		DrawTexture(1000.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPuppetTex));
	}
}