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

#if 1
	if (GetKeyDown(TWO_KEY)) {

		m_iFrameCount = 0;
		m_IsActive = true;
		m_RoomId = RoomID::ROOM_WORK;
	}
#endif

#if 1
	if (m_IsActive == false && m_iFrameCount >= 100) {
		if (Prob.GetRandomValue(0, m_EnemyData.m_SpownJudge, 2) == false) { 
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
	{
		static bool once = false;
		if (!once)
		{
			pAudio->Play("YukaKisimiSE",0);
			once = true;
		}
		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			if (g_Manager.IsSameRoom(ROOM_RIGHT_PRAYER) == true
				|| g_Manager.IsSameRoom(ROOM_PRAYER) == true) {
				m_iFrameCount = 0;
				break;
			}

			once = false;
			m_iFrameCount = 0;
			m_RoomId = RoomID::ROOM_LEFT_PRAYER;
		}
	}
		break;
	}
#pragma endregion

	switch (m_RoomId)
	{
	case RoomID::ROOM_LEFT_PRAYER:
	{
		if (m_pPlayer->HasMask() == true
			&& m_pPlayer->CurrentViewID() == SubGameScene::LEFT_VIEW) {

			m_iFrameCount = 0;
			m_IsActive = false;
			m_RoomId = ROOM_WORK;
		}
		static bool once = false;

		// キルアニメーションが終わったら殺す処理
		if (m_CanKill && m_Color.a >= 1.5f) {
			m_iFrameCount = 0;
			m_HasKill = true;
			once = false;
			//m_CanKill = false;
		}

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			// ゲームオーバー処理
			m_CanKill = true;
			
			if (!once)
			{
				pAudio->Play("SakuraKillVoice",0);
				once = true;
			}
		}

		if (m_CanKill) { m_Color.a += 0.01f; }
	}
		break;
	default:
		break;
	}
}

void Sakura::Draw()
{
	Object* pLeftCandle = ObjManager()->GetObj(ObjID::CANDLE_LEFT);
	Character* pPlayer  = g_Manager.GetCharacter(PLAYER);

	if (m_IsActive == false)
	{
		if (pPlayer->CurrentViewID(SubGameScene::WORKSHOP_VIEW)) {

			DrawTexture(600.0f, 610.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_SPAWN_TEX));
		}

		return;
	}

	switch (m_RoomId)
	{
	case RoomID::ROOM_WORK:

		if (pPlayer->CurrentViewID(SubGameScene::WORKSHOP_VIEW)) {

			DrawTexture(600.0f, 610.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_SPAWN_TEX));
		}
		break;

	case RoomID::ROOM_RECEPTION:

		if (pPlayer->CurrentViewID(SubGameScene::RECEPTION_ROOM_VIEW)) {

			DrawTexture(1000.0f, 800.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_SPAWN_TEX));
		}
		break;

	case RoomID::LEFT_CORRIDOR:

		if (pPlayer->CurrentViewID(SubGameScene::LEFT_CORRIDOR_VIEW)) {

			DrawTexture(790.0f, 400.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_WALK_TEX));
		}
		break;

	case RoomID::LEFT_SHOJI:

		if (pPlayer->CurrentViewID(SubGameScene::LEFT_VIEW)
			&& pLeftCandle->HasCaLight() == true) {

			DrawTexture(1045.0f, 690.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_LOOK_TEX));
		}
		break;

	case RoomID::ROOM_LEFT_PRAYER:

		if (pPlayer->CurrentViewID(SubGameScene::LEFT_VIEW)) {

			DrawTexture(1380.0f, 600.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_PLAYER_TEX));
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
		DrawFade(false, m_Color);
	}
}
