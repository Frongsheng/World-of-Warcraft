#include"iceman.h"
#include"headquarter.h"
void Iceman::doLogBirth()
{

}

void Iceman:: moveForward(int time, int& is_over)
{
	life -= static_cast<int>(life * 0.1);
	Warrior::moveForward(time, is_over);
}

Iceman::Iceman(int _kind, Headquarter* phq, int _id, int _life, int av) :Warrior(_kind, phq, _id, _life, av)
{
	weapons.push_back(Weapon::create(id % 3));
}