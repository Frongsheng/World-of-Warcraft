#include "warrior.h"
#include <iostream>
#include"headquarter.h"
#include"city.h"
#include"lion.h"
#include"ninja.h"
#include"dragon.h"
#include"wolf.h"
#include"iceman.h"
#include<cstdio>
#include<algorithm>
using namespace std;

extern int N;//城市个数

const string Warrior::Name[] = { "dragon","ninja","iceman","lion","wolf"};

Warrior::Warrior(int _kind, Headquarter* phq, int _id, int _life, int av)
{
	kind = _kind;
	pHeadquarter = phq;
	id = _id;
	life = _life;
	AttackPower = av;
	name = Name[kind];
	if (phq->getName() == "red")
	{
		cityID = 0;
	}
	else
	{
		cityID = N + 1;
	}
}
shared_ptr<Warrior>Warrior::create(int _kind, Headquarter* phq, int _id, int _life, int av, int _k=0)
{
	if (_kind == dragon)
		return make_shared<Dragon>(_kind, phq, _id, _life, av);
	else if(_kind==ninja)
		return make_shared<Ninja>(_kind, phq, _id, _life, av);
	else if (_kind == lion)
		return make_shared<Lion>(_kind, phq, _id, _life, av,_k);
	else if(_kind==iceman)
		return make_shared<Iceman>(_kind, phq, _id, _life, av);
	else if (_kind == wolf)
		return make_shared<Wolf>(_kind, phq, _id, _life, av);
	else
	{
		puts("error 0");
		abort();
	}
}

void Warrior::logBirth(int time)
{
	const string& hp = pHeadquarter->getName();
	printf("%03d:00 %s %s %d born\n", time, pHeadquarter->getName().c_str(), name.c_str(), id);
	doLogBirth();
}

void Warrior::moveForward(int time, int& is_over)
{
	if (pHeadquarter->getName() == "red")
	{
		cityID++;
		if (cityID == N+1)
		{
			printf("%03d:10 red %s %d reached to blue headquarter with %d elemwnts and force %d", time, name.c_str(), id, life, AttackPower);
			printf("%03d:10 blue headquarter was taken", time);
			is_over = 1;
		}
		else
		{
			printf("%03d:10 blue %s %d marched to city %d with %d elemwnts and force %d", time, name.c_str(), id, cityID,life, AttackPower);
			is_over = 0;
		}
	}
	else
	{
		cityID--;
		if (cityID == 0)
		{
			printf("%03d:10 blue %s %d reached to red headquarter with %d elemwnts and force %d", time, name.c_str(), id, life, AttackPower);
			printf("%03d:10 red headquarter was taken", time);
			is_over = 1;
		}
		else
		{
			printf("%03d:10 blue %s %d marched to city %d with %d elemwnts and force %d", time, name.c_str(), id, cityID, life, AttackPower);
			is_over = 0;
		}
	}
}

int Warrior::getMaxHurt()//计算最大攻击值
{
	double coe = 0;
	for (auto &it : weapons)
	{
		coe = max(coe, AttackPower * it->getCoe());
	}
	return coe * AttackPower;
}

void Warrior::oneAttack(Warrior* enemy)//开打，轮流进攻
{
	if (enemy->life <= 0 || life <= 0)//死了，不用打了
	{
		return;
	}
	if (weapons.size() == 0)//手里没家伙，打不了
	{
		return;
	}
	if (NowWeaponID >= weapons.size())
	{
		cout << "fuck you" << endl;
		abort();
	}
	shared_ptr<Weapon>pWeapon = weapons[NowWeaponID];
	int hurtValue = pWeapon->getCoe() * AttackPower;//计算有效攻击力
	enemy->life -= hurtValue;
	if (pWeapon->getKind() == bomb && kind != ninja)
	{
		life -= static_cast<int>(hurtValue * 0.5);
	}
	if (pWeapon->afterOneUse() == 0)
	{
		weapons.erase(weapons.begin() + NowWeaponID);
		NowWeaponID -= 1;
	}
	if (weapons.size() != 0)
	{
		NowWeaponID = (NowWeaponID + 1) % weapons.size();
	}
}

void Warrior::wolfSteal(int time, Warrior* pEnemy)
{
	if (pEnemy->weapons.size() == 0)
	{
		return;
	}
	if (pEnemy->getKind() == wolf)
	{
		return;
	}
	int weaponKind = pEnemy->weapons[0]->getKind();
	int cnt = 0;
	for (int i = 0; i < pEnemy->weapons.size(); i++)
	{
		if (pEnemy->weapons[i]->getKind() != weaponKind)
		{
			break;
		}
		else
		{
			cnt++;
		}
	}
	int stealNum = min(cnt, int(weaponMaxNum - weapons.size()));
	weapons.insert(weapons.begin(), pEnemy->weapons.begin(),pEnemy->weapons.begin()+stealNum);
	sortWeapons();
	pEnemy->weapons.erase(pEnemy->weapons.begin(), pEnemy->weapons.begin() + stealNum);
	printf("%03d:35 %s wolf %d took %d %s from %s %s %d in city %d", time, pHeadquarter->getName().c_str(), id, stealNum, Weapon::Name[weaponKind].c_str(), pEnemy->pHeadquarter->getName().c_str(), pEnemy->name.c_str(), pEnemy->id, cityID);
}

bool cmpWeapons(const shared_ptr<Weapon>& a, const shared_ptr<Weapon>& b)
{
	return *a < *b;
}

void Warrior::sortWeapons()
{
	NowWeaponID = 0;
	sort(weapons.begin(), weapons.end(), cmpWeapons);// 给武器排好序
	if (weapons.size() > weaponMaxNum)
	{
		weapons.erase(weapons.begin() + weaponMaxNum, weapons.end());
	}
}

void Warrior::captureWeapon(Warrior* pEnemy)
{
	if (life > 0 && pEnemy->life <= 0)
	{
		pEnemy->sortWeapons();//排好序，从小到大收缴武器
		int captureNum = min(weaponMaxNum - weapons.size(), pEnemy->weapons.size());//计算武器池剩余容量，能收缴就全收缴了
		weapons.insert(weapons.end(), pEnemy->weapons.begin(), pEnemy->weapons.begin() + captureNum);
	}
	else
	{
		cout << "it`s a sad thing that winner can`t capture weapons" << endl;
	}
}

void Warrior::resportSituation(int time)
{
	int swordNum = 0, arrowNum = 0, bombNum = 0;
	for (int i = 0; i < weapons.size(); i++)
	{
		if (weapons[i]->getKind() == sword)
		{
			swordNum++;
		}
		else if (weapons[i]->getKind() == bomb)
		{
			bombNum++;
		}
		else if (weapons[i]->getKind() == arrow)
		{
			arrowNum++;
		}
	}
	printf("%03d:55 %s %s %d has %d sword %d bomb %d arrow and %d elemwnts\n", time, pHeadquarter->getName().c_str(), name.c_str(), id, swordNum, bombNum, arrowNum, life);
}

