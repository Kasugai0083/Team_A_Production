#include "Scene.h"
#include "../Engine/Graphics.h"
#include "../Engine/Input.h"
#include "TitleScene.h"
#include "CenterScene.h"
#include "LeftScene.h"
#include "RightScene.h"
#include "MonitorScene.h"
#include "ClearScene.h"

static SceneId g_CurrentSceneId = SceneId::TitleScene;		// 動作中シーンID
static SceneStep g_CurrentSceneStep = SceneStep::InitStep;	// 動作中シーンのステップ

//シーン管理の関数群
SceneTransition g_ppp;
SceneTransition* SceneController() { return &g_ppp; };

void SceneTransition::SetID(Id id_, bool go_) {
	switch (id_) {
	case Left:
		m_CanLeft = go_;
		break;
	case Right:
		m_CanRight = go_;
		break;
	case Center:
		m_CanCenter = go_;
		break;
	case Monitor:
		m_CanMonitor = go_;
		break;
	case Clear:
		m_CanClear = go_;
		break;
	case Finish:
		m_CanFinish = go_;
		break;
	default:
		break;
	}
}

bool SceneTransition::IsGetID(Id id_) {
	switch (id_) {
	case Left:
		return m_CanLeft;
		break;
	case Right:
		return m_CanRight;
		break;
	case Center:
		return m_CanCenter;
		break;
	case Monitor:
		return m_CanMonitor;
		break;
	case Clear:
		return m_CanClear;
		break;
	case Finish:
		return m_CanFinish;
		break;
	default:
		break;
	}
}

void SceneTransition::GameEnd() {
	if (GetKey(ESCAPE_KEY) == true) {
		SceneController()->SetID(SceneTransition::Id::Finish, true);
	}
}

void SceneTransition::ChangeStep(Id id_, unsigned long key_) {
	if (GetKey(key_) == true) {
		SceneController()->SetID(id_, true);
		ChangeSceneStep(SceneStep::EndStep);
	}
}

//シーン管理用の関数群ここまで

//モニター管理用クラス関数
MonitorTransition g_qqq;
MonitorTransition* MonitorFunc() { return &g_qqq; };

int MonitorTransition::Get() {
	return m_MonitorId;
}

void MonitorTransition::Set(Id id_) {
	m_MonitorId = id_;
}

//ここまで


SceneId GetCurrentSceneId()
{
	return g_CurrentSceneId;
}

SceneStep GetCurrentSceneStep()
{
	return g_CurrentSceneStep;
}

void ChangeSceneStep(SceneStep next_step)
{
	g_CurrentSceneStep = next_step;
}

void UpdateScene()
{
	UpdateInput();

	SceneId scene_id = g_CurrentSceneId;
	switch (g_CurrentSceneId)
	{
	case SceneId::TitleScene:
		scene_id = UpdateTitleScene();
		break;
	case SceneId::CenterScene:
		scene_id = UpdateCenterScene();
		break;
	case SceneId::MonitorScene:
		scene_id = UpdateMonitorScene();
		break;
	case SceneId::ClearScene:
		scene_id = UpdateClearScene();
		break;
	}

	DrawScene();

	if (scene_id != g_CurrentSceneId)
	{
		g_CurrentSceneId = scene_id;
		ChangeSceneStep(SceneStep::InitStep);
	}
}

void DrawScene()
{
	if (DrawStart() == false)
	{
		return;
	}
	if (g_CurrentSceneStep == SceneStep::MainStep)
	{
		switch (g_CurrentSceneId)
		{
		case SceneId::TitleScene:
			DrawTitleScene();
			break;
		case SceneId::CenterScene:
			DrawCenterScene();
			break;
		case SceneId::MonitorScene:
			DrawMonitorScene();
			break;
		case SceneId::ClearScene:
			DrawClearScene();
			break;
		}
	}

	DrawEnd();
}
