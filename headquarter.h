#pragma once
#include"warrior.h"

enum{r,b};

class Headquarter
{
private:
	int kind;
	int lastIndex = -1;
	int initValue, leftValue;
	const int* sequence;
	int totalNum = 0;
	string name;
	vector<shared_ptr<Warrior>>warriors;
	static const string Name[2];
	static const int makingSequence[2][warriorNum];
public:
	Headquarter(int _kind, int initV);
	string getName()const { return name; }
	void makeWarriors(int time, int _kind);
	int getKind()const { return kind; }
	void reportValue(int time)const;
	int getLeftValue()const { return leftValue; }
	vector<shared_ptr<Warrior>>::iterator getWarriors() { return warriors.begin(); }
	void tidyWarriors();
	bool eraseWarrior(Warrior* p);
	void logExistence(Warrior* log[]);
};