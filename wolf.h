#pragma once
#include"warrior.h"
class Wolf:public Warrior
{
private:
	void doReportBirth()override;
public:
	Wolf(int _kind, Headquarter* phq, int _id, int _life);
};