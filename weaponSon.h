#pragma once
#include"weapon.h"

class Sword :public Weapon
{
public:
	Sword(int _kind, double _coe) {}
	virtual bool afterOneUse()override;

};

class Bomb :public Weapon
{
public:
	Bomb(int _kind, double _coe) {}
	virtual bool afterOneUse()override;
};

class Arrow :public Weapon
{
public:
	Arrow(int _kind,double _coe){}
	virtual bool afterOneUse()override;
};
