#ifndef CHARACTER_H_
#define CHARACTER_H_

// キャラクターの基礎となるクラス

#include "..//Scene/Scene.h"

class Character {
public:

	//Character()
	//{
	//}

	virtual ~Character()
	{
	}

	virtual void Init() = 0;

	virtual void Update() = 0;

	virtual bool GetIsLight()
	{
		return IsLight;
	}

	virtual bool GetIsMask() {
		return IsMask;
	}

	virtual bool GetIsMonitor() {
		return IsMonitor;
	}

	virtual bool GetIsKill() {
		return IsPlayerKill;
	}
	virtual bool GetIsDeath() { return IsDeath; }
	virtual void Draw() = 0;

	virtual void LoadTex(SceneId id) {};

private:

	bool IsMask;
	bool IsLight;
	bool IsMonitor;
	bool IsPlayerKill;
	bool IsDeath;
};

#endif