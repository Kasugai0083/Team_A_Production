#ifndef CHARACTER_H_
#define CHARACTER_H_

// キャラクターの基礎となるクラス

#include "..//Scene/Scene.h"
#include "../Scene/GameScene/GameData.h"

class Character {
public:
	Character(bool is_active_)
	{
		m_IsActive = is_active_;
	}

	virtual ~Character(){}

	virtual void Init() = 0;

	virtual void Update() = 0;

	virtual bool HasLight() const
	{
		return m_HasLight;
	}

	virtual bool HasMask() const {
		return m_HasMask;
	}

	virtual bool HasMonitor() const {
		return m_HasMonitor;
	}

	virtual bool HasKill() const{
		return m_HasKill;
	}
	virtual bool IsActive() { return m_IsActive; }

	virtual MonitorView CurrentViewMonitorID() const{
		return m_MonitorViewID;
	}

	virtual void Draw() = 0;

	virtual void LoadTex(SceneId id) {};


	// 2019/12/05追加
	virtual bool ControlMonitor() { return 0; };
	virtual bool ControlGameScene() { return 0; };
	virtual bool HasGFreddySpown() { return 0; };

	// 試しに追加します。
	virtual bool SpawnJudgement() const { return 0; }

protected:
	bool m_IsActive;

private:
	//プレイヤーの情報
	bool m_HasMask;
	bool m_HasLight;
	bool m_HasMonitor;
	MonitorView m_MonitorViewID;

	//エネミーの情報
	bool m_HasKill;
};

#endif