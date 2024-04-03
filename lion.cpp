#include"lion.h"
#include"headquarter.h"
extern int N;
Lion::Lion(int _kind, Headquarter* phq, int _id, int _life, int av, int _k) :Warrior(_kind, phq, _id, _life, av)
{
	k = _k;
	weapons.push_back(Weapon::create(id % 3));
	loyalty = phq->getLeftValue();
}

int Lion::lionEscape(int time)
{
	if (loyalty <= 0)
	{
		if (pHeadquarter->getName() == "red" && cityID == N + 1 || pHeadquarter->getName() == "blue" && cityID == 0)
		{
			return 0;
		}
		else
		{
			printf("%03d:05 %s lion %d ran away", time, pHeadquarter->getName().c_str(), id);
			return 1;
		}
	}
	return 0;
}

void Lion::doLogBirth()
{
	printf("Its loyalty is %d\n", loyalty);
}

void Lion::moveForward(int time, int& is_over)
{
	loyalty -= k;
	Warrior::moveForward(time, is_over);
}

