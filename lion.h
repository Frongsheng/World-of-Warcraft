#pragma once
#include"warrior.h"

class Lion:public Warrior
{
private:
	void doReportBirth();
	int loyalty;
public:
	Lion(int _kind, Headquarter* phq, int _id, int _life);
};