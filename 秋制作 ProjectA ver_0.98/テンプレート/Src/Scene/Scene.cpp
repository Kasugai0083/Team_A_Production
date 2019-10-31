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
SceneTransition ppp;
SceneTransition* TransButton() { return &ppp; };

void SceneTransition::Change(Id id, bool go) {
	switch (id) {
	case Left:
		m_GoLeft = go;
		break;
	case Right:
		m_GoRight = go;
		break;
	case Center:
		m_GoCenter = go;
		break;
	case Monitor:
		m_GoMonitor = go;
		break;
	case Clear:
		m_GoClear = go;
		break;
	case Finish:
		m_GoFinish = go;
		break;
	default:
		break;
	}
}

bool SceneTransition::Research(Id id) {
	switch (id) {
	case Left:
		return m_GoLeft;
		break;
	case Right:
		return m_GoRight;
		break;
	case Center:
		return m_GoCenter;
		break;
	case Monitor:
		return m_GoMonitor;
		break;
	case Clear:
		return m_GoClear;
		break;
	case Finish:
		return m_GoFinish;
		break;
	default:
		break;
	}
}

void SceneTransition::GameEnd() {
	if (GetKey(ESCAPE_KEY) == true) {
		TransButton()->Change(SceneTransition::Id::Finish, true);
	}
}

void SceneTransition::ChangeStep(Id id, unsigned long key) {
	if (GetKey(key) == true) {
		TransButton()->Change(id, true);
		ChangeSceneStep(SceneStep::EndStep);
	}
}

//シーン管理用の関数群ここまで

//モニター管理用クラス関数
MonitorTransition qqq;
MonitorTransition* MonitorFunc() { return &qqq; };

int MonitorTransition::Get() {
	return m_MonitorId;
}

void MonitorTransition::Set(Id id) {
	m_MonitorId = id;
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
	case SceneId::LeftScene:
		scene_id = UpdateLeftScene();
		break;
	case SceneId::RightScene:
		scene_id = UpdateRightScene();
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
		case SceneId::LeftScene:
			DrawLeftScene();
			break;
		case SceneId::RightScene:
			DrawRightScene();
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
