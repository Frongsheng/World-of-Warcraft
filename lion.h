#pragma once 
#include"warrior.h"
#include"city.h"
class Lion:public Warrior
{
private:
	void doLogBirth()override;
	int lionEscape(int time)override;
	void moveForward(int time, int& isOver)override;
	int loyalty;
	int k;
public:
	
	Lion(int _kind, Headquarter* phq, int _id, int _life, int av, int _k);
};