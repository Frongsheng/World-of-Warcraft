#include"headquarter.h"
#include"warrior.h"
#include<cstdio>

extern int initlife[warriorNum];
const string Headquarter::Name[2] = { "red","blue" };
const int Headquarter::makingList[2][warriorNum] = { {2,3,4,1,0},{3,0,1,2,4} };//��warrior�����ö��˳���й�
int Headquarter::warriorKindNum[] = { 1,1,1,1,1};

Headquarter::Headquarter(int _kind, int initV)
{
	kind = _kind;
	initValue = initV;
	leftValue = initV;
	colorName = Name[_kind];
	list = makingList[_kind];//��������˾���ʿ������˳��
}

void Headquarter::makeWarriors(int time)
{
	if (listIndex == -2)
	{
		return;
	}

	int index = (listIndex + 1) % warriorNum;
	int theKind = list[index];//�����ֵ������ʿ������

	if (leftValue < initlife[theKind])//�ж�����Ԫ������
	{
		listIndex = -2;
		return;
	}

	listIndex = index;
	int id = ++allNum;
	leftValue -= initlife[theKind];
	shared_ptr<Warrior>pWarrior = Warrior::createWarrior(theKind, this, id, initlife[theKind]);
	pWarrior->reportBirth(time);
	warriorKindNum[theKind] += 1;
}

void Headquarter::reportStop(int time)
{
	printf("%03d %s stop making warriors\n",time, colorName.c_str());
}

int Headquarter::getKindNum(int _kind) const
{
	return warriorKindNum[_kind];
}
