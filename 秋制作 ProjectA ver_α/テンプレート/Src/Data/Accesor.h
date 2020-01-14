#ifndef ACCESOR_H_
#define ACCESOR_H_

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