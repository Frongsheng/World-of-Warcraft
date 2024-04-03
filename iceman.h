#pragma once 
#include"warrior.h"

class Iceman: public Warrior
{
private:
	void doLogBirth()override;
	void moveForward(int time, int& is_over)override;
public:
	Iceman(int _kind, Headquarter* phq, int _id, int _life, int av);
};