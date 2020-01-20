#include "Player.h"
#include "../../Src/Engine/Input.h"
#include "../../Texture/Texture.h"
#include "../CharacterManager.h"
#include "..//..//Object/ObjectManager.h"
#include "..//..//Timer/Timer.h"
#include "../../Engine/Audio/Audio.h"

void Player::Init()
{
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
	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());

	Timer* pTimerInstance = Timer::GetInstance();
	if (pTimerInstance->GetTime(Timer::Id::SCENE) >= SCENE_WAIT) {

		if (!m_IsMask)
		{
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
		}

		static bool once = false;
		if (GetKeyDown(SPACE_KEY) == true) {

			if (!once) {
				pAudio->Play("ToMonitor");
				once = true;
			}

			TmpRoom = m_ViewID;
			m_ViewID = TmpMonitor;
			
			/*m_HasMonitor = true;*/

			pTimerInstance->Init(Timer::Id::SCENE);
			return true;
		}
		once = false;
	}
	return false;
}

void Player::Update()
{
	//エネミーが参照する値を変更
	if (g_Manager.RefKill() == true) {
		m_IsActive = false;
	}

	if (g_Manager.CanKill() == true) { return; }

	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());

	Object* pMaskUI = ObjManager()->GetObj(ObjID::MO_MASK_UI);

	static bool once = false;
	//マスク被る・被らない

	if (pMaskUI == nullptr) {
		return;
	}

	if (pMaskUI->HasMask() == true) {

		if (!once)
		{
			pAudio->Play("MaskSE");
			once = true;
		}

		//m_IsMask = true;
	
	}
	else {
		//m_IsMask = false;

		once = false;
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
	

	// 試しに追加
	Character* pBotan = g_Manager.GetCharacter(CharacterID::BOTAN);
	if (pBotan->SpawnJudgement() == true) {
		m_HasGFreddySpown = false;
	}


	m_IsMask = m_MaskAnimation >= 1080.f ? true : false;

}

void Player::Draw() {
	OnMask();
}

void Player::LoadTex()
{
}

const bool Player::CurrentViewID(const SubGameScene sceneId_) const
{
	if (m_ViewID == sceneId_) {
		return true;
	}
	return false;
}

void Player::OnMask() {
	if (GetCurrentSceneId() == SceneId::MonitorScene) {
		return;
	}

	Object* pMaskUI = ObjManager()->GetObj(ObjID::MO_MASK_UI);

	if (pMaskUI->HasMask() == true) {
		if (m_MaskAnimation <= 1100.0f) {
			m_MaskAnimation += 50.f;
			if (m_MaskAnimation >= 1080.0f) {
				m_MaskAnimation = 1080.0f;
			}
		}

		//DrawTexture(0.0f, (-1080.f + m_MaskAnimation), GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_MASK_TEX));

	}
	else {
		if (m_MaskAnimation >= -1080.f) {
			m_MaskAnimation -= 100.f;
			if (m_MaskAnimation <= -540.f) {
				m_MaskAnimation = -540.f;
			}
		}
		//DrawTexture(0.0f, (-1080.0f + m_MaskAnimation), GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_MASK_TEX));
	}
	DrawTexture(0.0f, (-1080.0f + m_MaskAnimation), GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_MASK_TEX), 0.f, 1.f, 0.9f);
}


