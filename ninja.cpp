#include"ninja.h"
void Ninja::doLogBirth()
{

}
Ninja::Ninja(int _kind, Headquarter* phq, int _id, int _life, int av) :Warrior(_kind, phq, _id, _life, av)
{
	weapons.push_back(Weapon::create(id % 3));
	weapons.push_back(Weapon::create((id + 1)% 3));
}