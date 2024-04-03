#pragma once
#include<string>
#include <memory>
#include"warrior.h"

enum { r, b };

class Headquarter
{
private:
	int kind;//用以判断司令部类型，和枚举联动
	int initValue, leftValue;//初始生命元，剩余生命元
	int allNum=0;//士兵总数
	int listIndex=-1;//用以判断是否制造士兵
	const int* list;//制造士兵顺序
	string colorName;//红蓝双方
	static const string Name[2];//司令部数组
	static const int makingList[2][warriorNum];//制造士兵顺序数组
	static int warriorKindNum[warriorNum];//记录每种士兵个数
public:
	Headquarter(int _kind, int initV);
	string getName()const { return colorName; }
	void makeWarriors(int time);
	int getKind()const { return kind; }
	int getleftValue()const { return leftValue; }
	void reportStop(int time);
	int getKindNum(int _kind)const;
};


