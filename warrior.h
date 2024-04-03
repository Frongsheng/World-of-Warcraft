#pragma once
#include<string>
#include<vector>
#include <memory>
using namespace std;

enum{dragon,ninja,iceman,lion,wolf};
static const int warriorNum = 5;

class wolf;
class dragon;
class lion;
class iceman;
class ninja;
class Headquarter;

class Warrior
{
private:
	virtual void doReportBirth() = 0;

protected:
	int kind;//ʿ�����࣬��Ӧö��
	int id;//ʿ�����
	int life;//����ֵ
	string name;//ʿ������
	Headquarter* pHeadquarter;//����˾�

public:
	virtual ~Warrior() {}//ʹ֮���һ��������
	Warrior(int _kind, Headquarter* hq, int _id, int _life);
	static shared_ptr<Warrior>createWarrior(int _kind, Headquarter* phq, int _id, int _life);
	static const string Name[warriorNum];
	string getName()const { return name; }
	int getLife()const { return life; }
	int getID()const { return id; }
	int getKind()const { return kind; }
	void reportBirth(int time);
};