#pragma once
#include "warrior.h"
class Warrior;

class City
{
private:
	Warrior* redWarrior, * blueWarrior;
	int id;
public:
	City(int _id, Warrior* red, Warrior* blue);
	void War(int time);
	void doWolfSteal(int time);
	void doWar(int time, Headquarter& red, Headquarter& blue);
	void doReportWarrior(int time);
	Warrior* getBlue()const { return blueWarrior; }
	int getId() { return id; }
};