#pragma once
#include<string>
#include <memory>
#include"warrior.h"

enum { r, b };

class Headquarter
{
private:
	int kind;//�����ж�˾����ͣ���ö������
	int initValue, leftValue;//��ʼ����Ԫ��ʣ������Ԫ
	int allNum=0;//ʿ������
	int listIndex=-1;//�����ж��Ƿ�����ʿ��
	const int* list;//����ʿ��˳��
	string colorName;//����˫��
	static const string Name[2];//˾�����
	static const int makingList[2][warriorNum];//����ʿ��˳������
	static int warriorKindNum[warriorNum];//��¼ÿ��ʿ������
public:
	Headquarter(int _kind, int initV);
	string getName()const { return colorName; }
	void makeWarriors(int time);
	int getKind()const { return kind; }
	int getleftValue()const { return leftValue; }
	void reportStop(int time);
	int getKindNum(int _kind)const;
};


