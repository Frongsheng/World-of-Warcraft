#pragma once
#include"warrior.h"

class Iceman:public Warrior
{
private:
	void doReportBirth()override;
public:
	Iceman(int _kind, Headquarter* phq, int _id, int _life);

};