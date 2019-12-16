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
void ButtonPush(T1 button_, T2 view_) {
	Timer* pTimerInstance = Timer::GetInstance();

	if (ObjManager()->HasOnMouse(button_) == true) {
		if (OnMouseDown(Left) == true) {
			GameView()->SetMonitorID(view_);
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

			GameView()->SaveMonitorID();
			GameView()->SetMonitorID(MonitorView::NONE);
			GameView()->LoadViewID();

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
void KeyPush(T1 button_, T2 view_) {
	Timer* pTimerInstance = Timer::GetInstance();

	if (GetKey(button_) == true) {
		pTimerInstance->Init(Timer::Id::SCENE);
		GameView()->SetViewID(view_);
	}
}

bool Player::ControlGameScene() {
	Timer* pTimerInstance = Timer::GetInstance();
	if (pTimerInstance->GetTime(Timer::Id::SCENE) >= SCENE_WAIT) {

			switch (GameView()->CurrentViewID()) {
			case GameData::SubGameScene::CENTER:

				KeyPush(A_KEY, GameData::LEFT);
				KeyPush(D_KEY, GameData::RIGHT);

				break;
			case GameData::RIGHT:

				KeyPush(A_KEY, GameData::CENTER);

				break;
			case GameData::LEFT:

				KeyPush(D_KEY, GameData::CENTER);

				break;
			}
		

		if (GetKey(SPACE_KEY) == true) {

			GameView()->SaveViewID();
			GameView()->SetViewID(GameData::SubGameScene::NONE);
			GameView()->LoadMonitorID();

			pTimerInstance->Init(Timer::Id::SCENE);
			return true;
		}
	}
	return false;
}

void Player::Update()
{
	Object* pMaskUI = ObjManager()->GetObj(ObjID::MO_MASK_UI);

	m_MonitorViewID = GameView()->CurrentMonitorID();

	//マスク被る・被らない
	if (pMaskUI->HasMask() == true) {
		m_IsMask = true;
	}
	else {
		m_IsMask = false;
	}

	if (GetCurrentSceneId() == SceneId::GameScene) {
		if (m_HasMonitor == false) {
			if (GameView()->CurrentViewID() != GameData::SubGameScene::NONE) {
				if (ControlGameScene() == true) {
					m_HasMonitor = true;
				}
			}
		}
		else {
			if (GameView()->CurrentMonitorID() != MonitorView::NONE) {
				if (ControlMonitor() == true) {
					m_HasMonitor = false;
				}
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