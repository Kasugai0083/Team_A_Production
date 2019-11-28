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
	OpeningScene,
	GameScene,
	EnemyScene,
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
		Game,
		Left,
		Right,
		Center,
		Monitor,
		Clear,
		Finish
	};

	SceneTransition() :
		m_CanGame(false),
		m_CanLeft(false),
		m_CanRight(false),
		m_CanCenter(false),
		m_CanMonitor(false),
		m_CanClear(false),
		m_CanFinish(false)
	{}
	void SetID(Id id_, bool go_);
	bool IsGetID(Id id_);
	void GameEnd();
	void ChangeStep(Id id_, unsigned long key_);

private:
	bool m_CanGame;
	bool m_CanLeft;
	bool m_CanRight;
	bool m_CanCenter;
	bool m_CanMonitor;
	bool m_CanClear;
	bool m_CanFinish;
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
		Right_Duct,
		ROOM_STORE,
		ROOM_RECEPTION,
		ROOM_CHILD
	};

	int Get();
	void Set(Id id);

private:
	int m_MonitorId;
};
//モニターの遷移を管理するクラスここまで
SceneTransition* SceneController();
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
