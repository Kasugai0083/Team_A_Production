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
			m_MonitorViewID = view_;
			pTimerInstance->Init(Timer::Id::SCENE);
		}
	}
}

bool Player::ControlMonitor() {

	Timer* pTimerInstance = Timer::GetInstance();
	if (pTimerInstance->GetTime(Timer::Id::SCENE) >= SCENE_WAIT) {

		ButtonPush(ObjID::BUTTON_WORKSHOP, MonitorView::WORKSHOP_VIEW);
		ButtonPush(ObjID::BUTTON_LEFT_CORRIDOR, MonitorView::LEFT_CORRIDOR_VIEW);
		ButtonPush(ObjID::BUTTON_RIGHT_CORRIDOR, MonitorView::RIGHT_CORRIDOR_VIEW);
		ButtonPush(ObjID::BUTTON_STORE_ROOM, MonitorView::STORE_ROOM_VIEW);
		ButtonPush(ObjID::BUTTON_RECEPTION_ROOM, MonitorView::RECEPTION_ROOM_VIEW);
		ButtonPush(ObjID::BUTTON_CHILD_ROOM, MonitorView::CHILD_ROOM_VIEW);

		if (GetKey(SPACE_KEY) == true) {

			//一旦コメントアウト
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

	if (GetKey(button_) == true) {
		pTimerInstance->Init(Timer::Id::SCENE);
		m_ViewID = view_;
	}
}

bool Player::ControlGameScene() {

	Timer* pTimerInstance = Timer::GetInstance();
	if (pTimerInstance->GetTime(Timer::Id::SCENE) >= SCENE_WAIT) {

			switch (m_ViewID) {
			case SubGameScene::CENTER:

				KeyPush(A_KEY, SubGameScene::LEFT);
				KeyPush(D_KEY, SubGameScene::RIGHT);

				break;
			case SubGameScene::RIGHT:

				KeyPush(A_KEY, SubGameScene::CENTER);

				break;
			case SubGameScene::LEFT:

				KeyPush(D_KEY, SubGameScene::CENTER);

				break;
			}
		

		if (GetKey(SPACE_KEY) == true) {

			pTimerInstance->Init(Timer::Id::SCENE);
			return true;
		}
	}
	return false;
}

void Player::Update()
{
	Object* pMaskUI = ObjManager()->GetObj(ObjID::MO_MASK_UI);

	//if (m_HasMonitor == false) {
	//	GameView()->SaveViewID();
	//	GameView()->LoadViewID();
	//	GameView()->SetMonitorID(MonitorView::NONE);
	//}
	//else {
	//	GameView()->SaveMonitorID();
	//	GameView()->LoadMonitorID();
	//	GameView()->SetViewID(GameData::SubGameScene::NONE);
	//}

	//m_MonitorViewID = GameView()->CurrentMonitorID();

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
		else {
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