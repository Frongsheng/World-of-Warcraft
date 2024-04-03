#include"headquarter.h"
#include<cstdio>
extern int initLifeValue[warriorNum];
extern int attackValue[warriorNum];
const string Headquarter::Name[] = { "red","blue" };
const int Headquarter::makingSequence[2][warriorNum] = { {2,3,1,4,0},{3,0,1,2,4} };

Headquarter::Headquarter(int _kind, int initV)
{
	kind = _kind;
	initValue = initV;
	leftValue = initV;
	name = Name[kind];
	sequence = makingSequence[_kind];
}

void Headquarter::makeWarriors(int time, int _kind)
{
	if (lastIndex == -2)
	{
		return;
	}
	int index = (lastIndex + 1) % warriorNum;
	int wKind = sequence[index];
	int cnt = 0;
	if (leftValue < initLifeValue[wKind])
	{
		lastIndex = -2;
		return;
	}
	lastIndex = index;
	int id = ++totalNum;
	leftValue -= initLifeValue[wKind];
	shared_ptr<Warrior>pw = Warrior::create(wKind, this, id, initLifeValue[wKind], attackValue[wKind],_kind);
	warriors.push_back(pw);
	pw->logBirth(time);
}

void Headquarter::tidyWarriors()
{
	vector<decltype(warriors.begin()) > W;
	for (auto it = warriors.begin(); it < warriors.end(); it++)
	{
		if ((*it)->getLife() <= 0)
		{
			W.push_back(it);
		}
	}
	for (int i = W.size() - 1; i >= 0; i--)
	{
		warriors.erase(W[i]);
	}
}

bool Headquarter::eraseWarrior(Warrior* p)
{
	for (auto it = warriors.begin(); it != warriors.end(); it++)
	{
		if (it->get() == p)
		{
			warriors.erase(it);
			return 1;
		}
	}
	return 0;
}

void Headquarter::logExistence(Warrior* log[])
{
	for (auto it = warriors.begin(); it != warriors.end(); it++)
	{
		log[(*it)->getCityID()] = (*it).get();
	}
}

void Headquarter::reportValue(int time)const
{
	printf("%03d:50 %d elements in %s headquarter\n", time, leftValue, name.c_str());
}

