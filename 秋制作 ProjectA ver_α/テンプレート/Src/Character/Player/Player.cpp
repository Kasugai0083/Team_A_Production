#include "Player.h"
#include "../../Src/Engine/Input.h"
#include "../../Texture/Texture.h"
#include "../CharacterManager.h"
#include "..//..//Object/ObjectManager.h"
#include "..//..//Timer/Timer.h"

void Player::Init()
{
	m_IsMask = false;
	m_MaskAnimation = -540.f;
	LoadTexture("Res/Game/Player/Mask.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMaskTex);
}

// T1 => どのボタンを触れたか
// T2 => どの MonitorView に移動するか
// 糞ずるい気がするので変更する予定
template <class T1, class T2>
void Player::ButtonPush(T1 button_, T2 view_) {
	Timer* pTimerInstance = Timer::GetInstance();

	if (ObjManager()->HasOnMouse(button_) == true) {
		if (OnMouseDown(Left) == true) {
			m_ViewID = view_;
			pTimerInstance->Init(Timer::Id::SCENE);
		}
	}
}

bool Player::ControlMonitor() {

	Timer* pTimerInstance = Timer::GetInstance();
	if (pTimerInstance->GetTime(Timer::Id::SCENE) >= SCENE_WAIT) {

		ButtonPush(ObjID::BUTTON_WORKSHOP, SubGameScene::WORKSHOP_VIEW);
		ButtonPush(ObjID::BUTTON_LEFT_CORRIDOR, SubGameScene::LEFT_CORRIDOR_VIEW);
		ButtonPush(ObjID::BUTTON_RIGHT_CORRIDOR, SubGameScene::RIGHT_CORRIDOR_VIEW);
		ButtonPush(ObjID::BUTTON_STORE_ROOM, SubGameScene::STORE_ROOM_VIEW);
		ButtonPush(ObjID::BUTTON_RECEPTION_ROOM, SubGameScene::RECEPTION_ROOM_VIEW);
		ButtonPush(ObjID::BUTTON_CHILD_ROOM, SubGameScene::CHILD_ROOM_VIEW);

		if (GetKeyDown(SPACE_KEY) == true) {
			TmpMonitor = m_ViewID;
			m_ViewID = TmpRoom;

			m_HasGFreddySpown = true;

			pTimerInstance->Init(Timer::Id::SCENE);

			return true;
		}
	}
	return false;
}

// T1 => どのボタンを触れたか
// T2 => どの ViewScene に移動するか
// 糞ずるい気がするので変更する予定
template <class T1, class T2>
void Player::KeyPush(T1 button_, T2 view_) {
	Timer* pTimerInstance = Timer::GetInstance();

	if (GetKeyDown(button_) == true) {
		pTimerInstance->Init(Timer::Id::SCENE);
		m_ViewID = view_;
	}
}

bool Player::ControlGameScene() {

	Timer* pTimerInstance = Timer::GetInstance();
	if (pTimerInstance->GetTime(Timer::Id::SCENE) >= SCENE_WAIT) {

			switch (m_ViewID) {
			case SubGameScene::CENTER_VIEW:

				KeyPush(A_KEY, SubGameScene::LEFT_VIEW);
				KeyPush(D_KEY, SubGameScene::RIGHT_VIEW);

				break;
			case SubGameScene::RIGHT_VIEW:

				KeyPush(A_KEY, SubGameScene::CENTER_VIEW);

				break;
			case SubGameScene::LEFT_VIEW:

				KeyPush(D_KEY, SubGameScene::CENTER_VIEW);

				break;
			}
		

		if (GetKeyDown(SPACE_KEY) == true) {

			TmpRoom = m_ViewID;
			m_ViewID = TmpMonitor;

			pTimerInstance->Init(Timer::Id::SCENE);
			return true;
		}
	}
	return false;
}

void Player::Update()
{
	Object* pMaskUI = ObjManager()->GetObj(ObjID::MO_MASK_UI);

	//マスク被る・被らない
	if (pMaskUI->HasMask() == true) {
		m_IsMask = true;
	}
	else {
		m_IsMask = false;
	}

	if (GetCurrentSceneId() == SceneId::GameScene) {
		if (m_HasMonitor == false) {
			if (ControlGameScene() == true) {
				m_HasMonitor = true;
			}
		}
		else if((m_HasMonitor == true)){
			if (ControlMonitor() == true) {
				m_HasMonitor = false;
			}
		}
	}
	

	//エネミーが参照する値を変更
	if (g_Manager.RefKill() == true) {
		m_IsActive = false;
	}

	// 試しに追加
	Character* pBotan = g_Manager.GetCharacter(CharacterID::BOTAN);
	if (pBotan->SpawnJudgement() == true) {
		m_HasGFreddySpown = false;
	}

}

void Player::Draw() {
	OnMask();
}

void Player::OnMask() {
	if (GetCurrentSceneId() == SceneId::MonitorScene) {
		return;
	}

	if (m_IsMask == true) {
		if (m_MaskAnimation <= 1100.0f) {
			m_MaskAnimation += 50.f;
			if (m_MaskAnimation >= 1080.0f) {
				m_MaskAnimation = 1080.0f;
			}
		}
		DrawTexture(0.0f, (-1080.f + m_MaskAnimation), GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMaskTex));
	}
	else {
		if (m_MaskAnimation >= -1080.f) {
			m_MaskAnimation -= 100.f;
			if (m_MaskAnimation <= -540.f) {
				m_MaskAnimation = -540.f;
			}
		}
		DrawTexture(0.0f, (-1080.0f + m_MaskAnimation), GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMaskTex));
	}
}