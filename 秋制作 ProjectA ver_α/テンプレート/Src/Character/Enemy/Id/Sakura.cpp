#include "Sakura.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../..//..//Data/GameData.h"
#include "../../../Engine/Input.h"
#include "../../../Object/Object.h"
#include "../../../Object/ObjectManager.h"
#include "../../../Engine/Audio/Audio.h"
#include "../../../Utility/Probability.h"


void Sakura::Init()
{

	CreateTexture("Res/Game/Enemy/Sakura/KillAnimation/1_.png", m_AnimationTex.m_TextureData[0]);
	CreateTexture("Res/Game/Enemy/Sakura/KillAnimation/2_.png", m_AnimationTex.m_TextureData[1]);
	CreateTexture("Res/Game/Enemy/Sakura/KillAnimation/3_.png", m_AnimationTex.m_TextureData[2]);
}

void Sakura::Update()
{
	Probability Prob;
	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());
	m_iFrameCount++;

#if 0
	if (GetKeyDown(TWO_KEY)) {

		m_iFrameCount = 0;
		m_IsActive = true;
		m_RoomId = RoomID::ROOM_WORK;
	}
#endif

#if 1
	if (m_IsActive == false && m_iFrameCount >= 100) {
		if (Prob.GetRandomValue(0, m_EnemyData.m_SpownJudge, 2) == true) { 
			m_iFrameCount = 0;
			return; 
		}

		m_iFrameCount = 0;
		m_IsActive	  = true;
		m_RoomId      = RoomID::ROOM_WORK;
	}
#endif

	if (m_IsActive == false) { return; }
	// アクティブじゃなかったらここより下の処理にはいかない

#pragma region ウメの移動
	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			if (g_Manager.IsSameRoom(ROOM_RECEPTION) == true) {
				m_iFrameCount = 0;
				break;
			}

			m_iFrameCount = 0;
			m_RoomId = RoomID::ROOM_RECEPTION;
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			if (g_Manager.IsSameRoom(LEFT_CORRIDOR) == true) {
				m_iFrameCount = 0;
				break;
			}

			m_iFrameCount = 0;
			m_RoomId = RoomID::LEFT_CORRIDOR;
		}
		break;

	case RoomID::LEFT_CORRIDOR:

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			if (g_Manager.IsSameRoom(LEFT_SHOJI) == true) {
				m_iFrameCount = 0;
				break;
			}

			m_iFrameCount = 0;
			m_RoomId = RoomID::LEFT_SHOJI;
		}
		break;

	case RoomID::LEFT_SHOJI:

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			if (g_Manager.IsSameRoom(ROOM_RIGHT_PRAYER) == true
				|| g_Manager.IsSameRoom(ROOM_PRAYER) == true) {
				m_iFrameCount = 0;
				break;
			}

			m_iFrameCount = 0;
			m_RoomId = RoomID::ROOM_LEFT_PRAYER;
		}
		break;
	}
#pragma endregion

	switch (m_RoomId)
	{
	case RoomID::LEFT_SHOJI:
	{
		static bool once = false;
		if (!once)
		{
			pAudio->Play("YukaKisimiSE");
			once = true;
		}
	}
	break;

	case RoomID::ROOM_LEFT_PRAYER:


		if (m_pPlayer->HasMask() == true) {

			m_iFrameCount = 0;
			m_IsActive	  = false;
			m_RoomId	  = ROOM_WORK;
		}

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			// ゲームオーバー処理
			m_CanKill = true;

			static bool once = false;
			if (!once)
			{
				pAudio->Play("SakuraKillVoice");
				once = true;
			}
		}

		// キルアニメーションが終わったら殺す処理
		if (m_AnimationTex.m_Counter >= 2) {
			m_iFrameCount = 0;
			m_HasKill = true;
			m_CanKill = false;
		}

		break;
	default:
		break;
	}
}

void Sakura::LoadTex()
{

}

void Sakura::Draw()
{
	Object* pLeftCandle = ObjManager()->GetObj(ObjID::CANDLE_LEFT);
	Character* pPlayer  = g_Manager.GetCharacter(PLAYER);

	if (m_IsActive == false)
	{
		if (pPlayer->CurrentViewID(SubGameScene::WORKSHOP_VIEW)) {

			DrawTexture(540.0f, 300.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_SPAWN_TEX));
		}

		return;
	}

	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (pPlayer->CurrentViewID(SubGameScene::WORKSHOP_VIEW)) {

			DrawTexture(540.0f, 300.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_SPAWN_TEX));
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (pPlayer->CurrentViewID(SubGameScene::RECEPTION_ROOM_VIEW)) {

			DrawTexture(50.0f, 400.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_SPAWN_TEX));
		}
		break;

	case RoomID::LEFT_CORRIDOR:

		if (pPlayer->CurrentViewID(SubGameScene::LEFT_CORRIDOR_VIEW)) {

			DrawTexture(670.0f, 300.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_WALK_TEX));
		}
		break;

	case RoomID::LEFT_SHOJI:

		if (pPlayer->CurrentViewID(SubGameScene::LEFT_VIEW)
			&& pLeftCandle->HasCaLight() == true) {

			DrawTexture(820.0f, 490.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_LOOK_TEX));
		}
		break;

	case RoomID::ROOM_LEFT_PRAYER:

		if (pPlayer->CurrentViewID(SubGameScene::LEFT_VIEW)) {

			DrawTexture(1360.0f, 440.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_PLAYER_TEX));
		}
		break;
	default:
		break;
	}
}

void Sakura::KillAnimation()
{
	if (m_CanKill == true)
	{
		DrawAnimation(0.0f, 0.0f, &m_AnimationTex);
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_KILLANIME_TEX));
	}
}
