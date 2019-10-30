#include "Player.h"
#include "../../Src/Engine/Input.h"
#include "../../Texture/Texture.h"
#include "../CharacterManager.h"

void Player::Init()
{
	m_IsDeath = false;
	m_IsLight = false;
	m_IsMask = false;
	m_IsMonitor = false;
	m_MaskAnimation = -540.f;

	LoadTexture("Res/Game/Player/Mask.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMaskTex);

}

void Player::Update()
{
	//センターライト
	if (GetKey(CONTROL_KEY) == true) {
		m_IsLight = true;
	}
	else if (GetKeyUp(CONTROL_KEY) == true) {
		m_IsLight = false;
	}

	//マスク被る
	if (GetCurrentSceneId() != MonitorScene) {

		if (GetKey(UP_KEY) == true) {
			m_IsMask = true;

		}
		else if (GetKeyUp(UP_KEY) == true)
		{
			m_IsMask = false;
		}
	}

	if (g_Manager.RefKill() == true) {
		m_IsDeath = true;
	}

}

void Player::Draw() {
	OnMask();
}

void Player::OnMask() {
	if (m_IsMask == true) {
		if (m_MaskAnimation <= 540.f) {
			m_MaskAnimation += 50.f;
			if (m_MaskAnimation >= 540.f) {
				m_MaskAnimation = 540.f;
			}
		}
		DrawTexture(0.0f, (-540.f + m_MaskAnimation), GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMaskTex));
	}
	else {
		if (m_MaskAnimation >= -1080.f) {
			m_MaskAnimation -= 100.f;
			if (m_MaskAnimation <= -540.f) {
				m_MaskAnimation = -540.f;
			}
		}
		DrawTexture(0.0f, (-540.f + m_MaskAnimation), GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMaskTex));
	}
}