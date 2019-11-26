#include "Puppet.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Timer/Timer.h"
#include "../../../Object/Item/Id/PlayerItem.h"

void Margaret::Init()
{
}

void Margaret::Update()
{
	m_iFrameCount++;

	Timer* pTimerInstance = Timer::GetInstance();

	if (m_IsActive == false && pTimerInstance->GetTime(Timer::Id::MUSICBOX) >= END_STEP) {

		m_iFrameCount = 0;
		m_IsActive = true;
	}

	if (m_IsActive == false) { return; }
	// 死んでたらここより下の処理にはいかない

	if (m_iFrameCount >= 300) {
		// ↓ゲームオーバー処理↓ //
		m_HasKill = true;
	}

}

void Margaret::LoadTex(SceneId id_)
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

void Margaret::Draw()
{
	if (m_IsActive == false)
	{
		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::CHILD_ROOM_VIEW) {

			DrawTexture(1000.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPuppetTex));
		}
	}
}

void Margaret::KillAnimation()
{
}
