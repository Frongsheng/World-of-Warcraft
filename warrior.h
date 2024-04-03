#pragma once
#include "weapon.h"
#include <memory>
#include <vector>
#include <string>
using namespace std;
class Headquarter;
class Dragon;
class Ninja;
class Iceman;
class Lion;
class Wolf;
class City;
enum{dragon,ninja,iceman,lion,wolf};
const int warriorNum = 5;
const int weaponMaxNum = 10;
class Warrior
{
private:
	virtual void doLogBirth() = 0;
protected:
	int id;
	int life;
	int kind;
	int AttackPower;
	int cityID;
	int NowWeaponID = 0;
	string name;//士兵名字
	Headquarter* pHeadquarter;
	vector<shared_ptr<Weapon>> weapons;//用智能指针定义一个vector的数组，避免内存得不到释放
	Warrior(int _kind, Headquarter* phq, int _id, int _life, int av);
public:
	//Warrior(){}
	static const string Name[warriorNum];
	static shared_ptr<Warrior>create(int _kind, Headquarter* phq, int _id, int _life, int av, int _k);
	virtual ~Warrior() {}
	virtual void moveForward(int time, int& is_over);
	void logBirth(int time);
	int getLife()const { return life; }
	int getWeaponNum()const { return weapons.size(); }
	int getID()const { return id; }
	int getKind()const { return kind; }
	int getCityID()const { return cityID; }
	int getMaxHurt();
	string getName()const { return name; }
	virtual int lionEscape(int time) { return 0; }
	void wolfSteal(int time, Warrior* pEnemy);
	void oneAttack(Warrior* enemy);
	void sortWeapons();
	void resportSituation(int time);
	void captureWeapon(Warrior* pEnemy);
};