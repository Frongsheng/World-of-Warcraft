#pragma once
#include"warrior.h"
#include"city.h"
class Dragon:public Warrior
{
private:
	void doLogBirth()override;
public:
	Dragon(int _kind, Headquarter* phq, int _id, int _life, int av);
};
