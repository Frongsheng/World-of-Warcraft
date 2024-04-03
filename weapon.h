#pragma once
#include<iostream>
#include<string>
using namespace std;

enum{sword,bomb,arrow};
enum{weaponNum=3};

class Weapon
{
private:
	int kind;
	string name;
protected:
	int useCount = 0;
	double coe=0;
	Weapon(int _kind, double _coe);
public:
	//Weapon(){}
	static const string Name[weaponNum];
	string getName() { return name; }
	int getKind() { return kind; }
	double getCoe() { return coe; }
	virtual bool afterOneUse() = 0;//ֻ�������������ĥ�����������ֵ����������Ƿ���Լ���ʹ��
	bool operator<(const Weapon& w)const;
	static shared_ptr<Weapon>create(int _id);
	virtual ~Weapon(){}
};
