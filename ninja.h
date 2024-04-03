#pragma once
#include"warrior.h"

class Ninja:public Warrior
{
private:
	void doLogBirth()override;
public:
	Ninja(int _kind, Headquarter* phq, int _id, int _life, int av);
};
