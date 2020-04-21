#ifndef ACCESOR_H_
#define ACCESOR_H_

/**
*	@file Botan.h
*	@author 春日井
*	@brief キャラクター「牡丹」を管理するクラスを処理
*/

#include "../Utility/SingletonTemplate.h"

class Accesor : public Singleton<Accesor>
{
public:

protected:

private:

	friend Singleton<Accesor>;

	Accesor() {};
	virtual ~Accesor() {};

	//コピーコンストラクタの禁止
	Accesor(const Accesor&) = delete;
	Accesor& operator=(const Accesor&) = delete;
	//ムーブコンストラクタの禁止
	Accesor(const Accesor&&) = delete;
	Accesor& operator=(const Accesor&&) = delete;

};

#endif