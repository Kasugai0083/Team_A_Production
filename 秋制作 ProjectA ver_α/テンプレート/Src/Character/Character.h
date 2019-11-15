#ifndef CHARACTER_H_
#define CHARACTER_H_

// キャラクターの基礎となるクラス

#include "..//Scene/Scene.h"

class Character {
public:

	virtual ~Character(){}

	virtual void Init() = 0;

	virtual void Update() = 0;

	virtual bool HasLight()
	{
		return m_HasLight;
	}

	virtual bool HasMask() {
		return m_HasMask;
	}

	virtual bool HasMonitor() {
		return m_HasMonitor;
	}

	virtual bool HasKill() const{
		return m_HasKill;
	}
	virtual bool IsDeath() { return m_IsDeath; }
	virtual void Draw() = 0;

	virtual void LoadTex(SceneId id) {};

private:
	//プレイヤーの情報
	bool m_HasMask;
	bool m_HasLight;
	bool m_HasMonitor;
	bool m_IsDeath;

	//エネミーの情報
	bool m_HasKill;
};

#endif