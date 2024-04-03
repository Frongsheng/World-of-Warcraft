#pragma once
#include"warrior.h"

class Ninja:public Warrior
{
private:
	void doReportBirth();
public:
	Ninja(int _kind, Headquarter* phq, int _id, int _life);
};