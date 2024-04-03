#pragma once
#include"warrior.h"

class Wolf:public Warrior
{
private:
	void doLogBirth()override;
public:
	Wolf(int _kind, Headquarter* phq, int _id, int _life, int av);
};
