#include"dragon.h"
#include"headquarter.h"
extern int initLife[warriorNum];
void Dragon::doLogBirth()
{

}
Dragon::Dragon(int _kind, Headquarter* phq, int _id, int _life, int av):Warrior(_kind, phq, _id, _life, av)
{
	weapons.push_back(Weapon::create(id % 3));
}