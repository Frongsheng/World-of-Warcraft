#pragma once
#include"warrior.h"
#include"headquarter.h"
extern 
class Dragon:public Warrior
{
private:
	void doReportBirth()override;
	double morale;
public:
	Dragon(int _kind, Headquarter* phq, int _id, int _life);
};