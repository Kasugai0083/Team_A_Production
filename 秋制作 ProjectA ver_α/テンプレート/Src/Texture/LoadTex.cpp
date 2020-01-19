#include "LoadTex.h"
#include "Texture.h"
#include "../Data/Days/DayController.h"

void LoadTitleTex();
void LoadOpTex();
void LoadGameTex();
void LoadClearTex();

void LoadSceneTex(SceneId id_) {
	switch (id_)
	{
	case TitleScene:
		LoadTitleTex();
		break;
	case OpeningScene:
		LoadOpTex();
		break;
	case GameScene:
		LoadGameTex();
		break;
	case EnemyScene:
		break;
	case TitleObjectScene:
		break;
	case GameObjectScene:
		break;
	case CenterScene:
		break;
	case LeftScene:
		break;
	case RightScene:
		break;
	case MonitorScene:
		break;
	case ClearScene:
		LoadClearTex();
		break;
	default:
		break;
	}
}

void LoadTitleTex() {
	LoadTexture("Res/Title/TitleBg.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleBgTex);
	LoadTexture("Res/Title/TitleLogo.png", TEXTURE_CATEGORY_TITLE_OBJECT, TitleObjectCategoryTextureList::OBJECT_TITLELOGO_TEX);
	LoadTexture("Res/Title/TitleMenuStart.png", TEXTURE_CATEGORY_TITLE_OBJECT, TitleObjectCategoryTextureList::OBJECT_NEWGAME_TEX);
	LoadTexture("Res/Title/titlemenu_start_effect.png", TEXTURE_CATEGORY_TITLE_OBJECT, TitleObjectCategoryTextureList::OBJECT_NEWGAME_ONHIT_TEX);
	LoadTexture("Res/Title/TitleMenuHelp.png", TEXTURE_CATEGORY_TITLE_OBJECT, TitleObjectCategoryTextureList::OBJECT_CONTINUE_TEX);
	LoadTexture("Res/Title/titlemenu_help_effect.png", TEXTURE_CATEGORY_TITLE_OBJECT, TitleObjectCategoryTextureList::OBJECT_CONTINUE_ONHIT_TEX);
	if (DayManager()->GetCurrentDays() == Days::DAY_1) {
		// 一日目の画像
		LoadTexture("Res/Title/itiyame_UI.png", TEXTURE_CATEGORY_TITLE_OBJECT, TitleObjectCategoryTextureList::OBJECT_DAYS_TEX);
		LoadTexture("Res/Title/itiyame_effect.png", TEXTURE_CATEGORY_TITLE_OBJECT, TitleObjectCategoryTextureList::OBJECT_DAYS_ONHIT_TEX);
	}
	else if (DayManager()->GetCurrentDays() == Days::DAY_2) {
		// 二日目の画像
		LoadTexture("Res/Title/niyame_UI.png", TEXTURE_CATEGORY_TITLE_OBJECT, TitleObjectCategoryTextureList::OBJECT_DAYS_TEX);
		LoadTexture("Res/Title/niyame_effect.png", TEXTURE_CATEGORY_TITLE_OBJECT, TitleObjectCategoryTextureList::OBJECT_DAYS_ONHIT_TEX);
	}
	else if (DayManager()->GetCurrentDays() == Days::DAY_3) {
		// 三日目の画像
		LoadTexture("Res/Title/sannyame_UI.png", TEXTURE_CATEGORY_TITLE_OBJECT, TitleObjectCategoryTextureList::OBJECT_DAYS_TEX);
		LoadTexture("Res/Title/sannyame_effect.png", TEXTURE_CATEGORY_TITLE_OBJECT, TitleObjectCategoryTextureList::OBJECT_DAYS_ONHIT_TEX);
	}
}

void LoadGameTex() {
	//ゲームシーン背景
	LoadTexture("Res/Game/Center/GameCenterBg.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex);
	LoadTexture("Res/Game/Left/GameLeftBg.png", TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex);
	LoadTexture("Res/Game/Right/GameRightBg.png", TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightBgTex);

	//センターシーン
	LoadTexture("Res/Game/Center/fence_black_texture.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFanceTex);
	LoadTexture("Res/Game/Center/all_black_texture.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFilterTex);
	LoadTexture("Res/Game/Center/desk.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterDeskTex);
	LoadTexture("Res/Game/Center/black_texture_center.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBlackTex);

	//右シーン
	LoadTexture("Res/Game/Right/right_shoji_front.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiFrontTex);
	LoadTexture("Res/Game/Right/right_shoji_back.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiBackTex);
	LoadTexture("Res/Game/Right/black_texture_right.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightBlackTex);
	//左シーン
	LoadTexture("Res/Game/Left/left_shoji_front.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiFrontTex);
	LoadTexture("Res/Game/Left/left_shoji_back.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiBackTex);
	LoadTexture("Res/Game/Left/black_texture_left.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftBlackTex);

	//モニターシーン
	LoadTexture("Res/Game/Monitor/GameMonitorBg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownBgTex);
	LoadTexture("Res/Game/Monitor/store_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex);
	LoadTexture("Res/Game/Monitor/Duct/LeftDuct.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctBgTex);
	LoadTexture("Res/Game/Monitor/Duct/RightDuct.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctBgTex);
	LoadTexture("Res/Game/Monitor/child_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChildRoomBgTex);
	LoadTexture("Res/Game/Monitor/resption_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorResptionRoomBgTex);
	LoadTexture("Res/Game/Monitor/dust.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex);

	//UI
	LoadTexture("Res/Game/Monitor/MonitorUI/map_UI_crystal.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_MONITOR_BUTTOM_TEX);
	LoadTexture("Res/Game/Monitor/MonitorUI/on_map_UI_crystal.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_MONITOR_ONBUTTOM_TEX);
	LoadTexture("Res/Game/UI/base_ui_bar.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_MAIN_UI_TEX);
	LoadTexture("Res/Game/UI/control_ui_bar.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CONTROL_UI_TEX);
	LoadTexture("Res/Game/UI/onhit_control_ui_bar.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_ONHIT_CONTROL_UI_TEX);
	LoadTexture("Res/Game/UI/mask_ui_bar.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_MASK_UI_TEX);
	LoadTexture("Res/Game/UI/control_ui_main.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_DESCRIPTION_UI_TEX);
	LoadTexture("Res/Game/Monitor/MonitorUI/map.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_MONITOR_MAP_TEX);
	LoadTexture("Res/Game/Monitor/MonitorUI/map_UI_pin.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_MONITOR_PLAYER_TEX);

	//Item
	LoadTexture("Res/Game/Item/candle_big.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_BIG_TEX);
	LoadTexture("Res/Game/Item/Candle_Center.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_SMALL_TEX);
	LoadTexture("Res/Game/Item/candle_stand_center.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_STAND_CENTER_TEX);
	LoadTexture("Res/Game/Item/candle_stand_side.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_STAND_SIDE_TEX);
	LoadTexture("Res/Game/Item/candle_effect_center.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_CENTER_EFFECT_TEX);
	LoadTexture("Res/Game/Item/candle_effect_right.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_RIGHT_EFFECT_TEX);
	LoadTexture("Res/Game/Item/candle_effect_left.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CANDLE_LEFT_EFFECT_TEX);

	LoadTexture("Res/Game/Item/candle_fire.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_FIRE_TEX);
	LoadTexture("Res/Game/Item/candle_fire_side.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_FIRE_SMALL_TEX);
	LoadTexture("Res/Game/Item/Crystal.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CRYSTAL_TEX);
	LoadTexture("Res/Game/Item/pocket_watch.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_WATCH_TEX);
	LoadTexture("Res/Game/Item/pocket_watch_effect.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_ONHITWATCH_TEX);

	//Character
	LoadTexture("Res/Game/Player/Mask.png", TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_MASK_TEX);
	LoadTexture("Res/Game/Enemy/Botan/Botan.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::BOTAN_PLAYER_TEX);
	LoadTexture("Res/Game/Enemy/Botan/KillAnimation/bot_kill.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::BOTAN_KILLANIME_TEX);
	LoadTexture("Res/Game/Enemy/Margaret/mag_camera_body_gray.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_SPAWN_BASE_TEX);
	LoadTexture("Res/Game/Enemy/Margaret/mag_camera_eye_gray.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_SPAWN_EYE_TEX);

	// 目のUI
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/UI_me_64.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_EYE_TEX);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_1.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_PIZA_1);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_2.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_PIZA_2);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_3.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_PIZA_3);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_4.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_PIZA_4);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_5.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_PIZA_5);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_6.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_PIZA_6);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_7.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_PIZA_7);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_8.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_PIZA_8);
	LoadTexture("Res/Game/Enemy/Margaret/Margaret_Eye/piza_9.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::MARGARET_PIZA_9);

	LoadTexture("Res/Game/Enemy/Ohagi/Freddy.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_SPAWN_TEX);
	LoadTexture("Res/Game/Enemy/Ohagi/oha_distant.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_FAR_TEX);
	LoadTexture("Res/Game/Enemy/Ohagi/oha_near.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_NEAR_TEX);
	LoadTexture("Res/Game/Enemy/Ohagi/FreddyAAA.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_PLAYER_TEX);
	LoadTexture("Res/Game/Enemy/Ohagi/KillAnimation/oha_kill.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::OHAGI_KILLANIME_TEX);

	LoadTexture("Res/Game/Enemy/Ran/ran_come_gray.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_SPAWN_TEX);
	LoadTexture("Res/Game/Enemy/Ran/ran_come.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_NEAR_TEX);
	LoadTexture("Res/Game/Enemy/Ran/Ran_Far.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_FAR_TEX);
	LoadTexture("Res/Game/Enemy/Ran/KillAnimation/ran_kill.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_KILLANIME_TEX);

	LoadTexture("Res/Game/Enemy/Sakura/sak_design_gray.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_SPAWN_TEX);
	LoadTexture("Res/Game/Enemy/Sakura/sak_walk_gray.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_WALK_TEX);
	LoadTexture("Res/Game/Enemy/Sakura/sak_look.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_LOOK_TEX);
	LoadTexture("Res/Game/Enemy/Sakura/sak_design.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_PLAYER_TEX);
	LoadTexture("Res/Game/Enemy/Sakura/KillAnimation/sak_kill.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::SAKURA_KILLANIME_TEX);

	LoadTexture("Res/Game/Enemy/Ume/ume_design_gray.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::UME_SPAWN_TEX);
	LoadTexture("Res/Game/Enemy/Ume/ume_walk_gray.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::UME_WALK_TEX);
	LoadTexture("Res/Game/Enemy/Ume/ume_look.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::UME_LOOK_TEX);
	LoadTexture("Res/Game/Enemy/Ume/ume_design.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::UME_PLAYER_TEX);
	LoadTexture("Res/Game/Enemy/Ume/KillAnimation/ume_kill.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::UME_KILLANIME_TEX);

}
void LoadOpTex() {
	LoadTexture("Res/Opening/operation_scene.png", TEXTURE_CATEGORY_OPENING, OpeningCategoryTextureList::OpeningDiary1Tex);
	LoadTexture("Res/Opening/operation_scene2.png", TEXTURE_CATEGORY_OPENING, OpeningCategoryTextureList::OpeningDiary2Tex);
	LoadTexture("Res/Opening/operation_scene_day2.png", TEXTURE_CATEGORY_OPENING, OpeningCategoryTextureList::OpeningDiary3Tex);
	LoadTexture("Res/Opening/operation_scene_day3.png", TEXTURE_CATEGORY_OPENING, OpeningCategoryTextureList::OpeningDiary4Tex);

	LoadTexture("Res/Opening/one_night.png", TEXTURE_CATEGORY_OPENING, OpeningCategoryTextureList::OpeningDay1Tex);
	LoadTexture("Res/Opening/two_night.png", TEXTURE_CATEGORY_OPENING, OpeningCategoryTextureList::OpeningDay2Tex);
	LoadTexture("Res/Opening/three_night.png", TEXTURE_CATEGORY_OPENING, OpeningCategoryTextureList::OpeningDay3Tex);


}

void LoadClearTex() {
	LoadTexture("Res/End/EndBg.png", TEXTURE_CATEGORY_CLEAR, ClearCategoryTextureList::ClearBgTex);
	LoadTexture("Res/End/GameOver.png", TEXTURE_CATEGORY_CLEAR, ClearCategoryTextureList::ClearGameOverTex);
}