/**
* @file Scene.h
* @brief シーン全体を実行、描画する関数の宣言
*/
#ifndef SCENE_H_
#define SCENE_H_


const int SCENE_WAIT = 10;
const int CLEAR_TIME = 6000;

/** @brief シーンID */
enum SceneId
{
	TitleScene,			//!< タイトルシーン
	GameScene,
	CenterScene,
	LeftScene,
	RightScene,
	MonitorScene,
	ClearScene,		//!< ゲームオーバーシーン
	SceneIdMax			//!< シーンID最大
};


//ゲームメイン間のシーン遷移で使用するスイッチ
class SceneTransition {
public:
	enum Id {
		Left,
		Right,
		Center,
		Monitor,
		Clear,
		Finish
	};

	SceneTransition() :
		m_GoLeft(false),
		m_GoRight(false),
		m_GoCenter(false),
		m_GoMonitor(false),
		m_GoClear(false),
		m_GoFinish(false)
	{}
	void Change(Id id, bool go);
	bool Research(Id id);
	void GameEnd();
	void ChangeStep(Id id, unsigned long key);

private:
	bool m_GoLeft;
	bool m_GoRight;
	bool m_GoCenter;
	bool m_GoMonitor;
	bool m_GoClear;
	bool m_GoFinish;
};

// クラスに格納された変数や関数を操作する関数

//モニターの遷移を管理するクラス

class MonitorTransition {
public:

	MonitorTransition():
	m_MonitorId(0)
	{}

	enum Id {
		Spown,
		Left_Duct,
		Right_Duct
	};

	int Get();
	void Set(Id id);

private:
	int m_MonitorId;
};
//モニターの遷移を管理するクラスここまで
SceneTransition* TransButton();
MonitorTransition* MonitorFunc();

/** @brief シーンステップ */
enum SceneStep
{
	InitStep,			//!< 初期化
	MainStep,			//!< メイン
	EndStep,			//!< 終了
};

/** @brief 現在実行中のシーンIDの取得関数 */
SceneId GetCurrentSceneId();

/** @brief 現在実行中のシーンステップの取得関数 */
SceneStep GetCurrentSceneStep();

/**
* @brief シーンステップ変更関数@n
* 引数で指定したステップに切り替える
* @param[in] next_step 次のステップ
*/
void ChangeSceneStep(SceneStep next_step);

/**
* @brief シーン実行関数@n
* シーン処理を実行する@n
* 内部で各シーンを動かすので使用者がUpdateTitleScene等を実行する必要はない
*/
void UpdateScene();

/**
* @brief シーン描画関数@n
* シーンのオブジェクトを描画する@n
* 内部で各シーン毎の描画を行うので使用者がDrawTitleScene等を実行する必要はない
*/
void DrawScene();

#endif
