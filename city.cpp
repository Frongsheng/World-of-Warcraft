#include"city.h"
#include"headquarter.h"
extern int N;

City::City(int _id, Warrior* red, Warrior* blue)
{
	id = _id;
	redWarrior = red;
	blueWarrior = blue;
}
//两军对决，你死我活
void City::War(int time)
{
	if (redWarrior == nullptr || blueWarrior == nullptr)
	{
		return;
	}
	int isTie = 0;
	while (redWarrior->getLife() > 0 && blueWarrior->getLife() > 0)
	{
		if (id % 2 == 0)
		{
			blueWarrior->oneAttack(redWarrior);
			redWarrior->oneAttack(blueWarrior);
		}
		else
		{
			redWarrior->oneAttack(blueWarrior);
			blueWarrior->oneAttack(redWarrior);
		}
		if ((redWarrior->getMaxHurt() == 0 && blueWarrior->getMaxHurt() == 0) || (redWarrior->getWeaponNum() == 0 && blueWarrior->getWeaponNum() == 0))
		{
			isTie=1;
				break;
		}
	}
	if (redWarrior->getLife() <= 0 && blueWarrior->getLife() <= 0)
	{
		printf("%03d:40 both red %s %d and blue %s %d died in city %d\n", time, redWarrior->getName().c_str(), redWarrior->getID(), blueWarrior->getName().c_str(), blueWarrior->getID(), id);
	}
	else if (redWarrior->getLife() <= 0)
	{
		printf("%03d:40 blue %s %d killed red %s %d in city %d remaining %d elements\n", time, blueWarrior->getName().c_str(), blueWarrior->getID(), redWarrior->getName().c_str(), redWarrior->getID(), id, blueWarrior->getLife());
		blueWarrior->captureWeapon(redWarrior);
		if (blueWarrior->getKind() == dragon)
		{
			printf("%03d:40 blue dragon %d yelled in city %d \n", time, blueWarrior->getID(), id);
		}
	}
	else if (blueWarrior->getLife() <= 0)
	{
		printf("%03d:40 red %s %d killed blue %s %d in city %d remaining %d elements\n", time, redWarrior->getName().c_str(), redWarrior->getID(), blueWarrior->getName().c_str(), blueWarrior->getID(), id, redWarrior->getLife());
		redWarrior->captureWeapon(blueWarrior);
		if (redWarrior->getKind() == dragon)
		{
			printf("%03d:40 red dragon %d yelled in city %d \n", time, redWarrior->getID(), id);
		}
	}
	else
	{
		if (!isTie)
		{
			puts("error isTie");
			abort();
		}
		printf("%03d:40 both red %s %d and blue %s %d were alive in city %d\n", time, redWarrior->getName().c_str(), redWarrior->getID(), blueWarrior->getName().c_str(), blueWarrior->getID(), id);
	}if (redWarrior->getKind() == dragon)
	{
		printf("%03d:40 red dragon %d yelled in city %d \n", time, redWarrior->getID(), id);
	}
	if (blueWarrior->getKind() == dragon)
	{
		printf("%03d:40 blue dragon %d yelled in city %d \n", time, blueWarrior->getID(), id);
	}
}
//先让武器排好序，方便开打，然后判断是否为wolf，是就开抢
void City::doWolfSteal(int time)
{
	if (redWarrior != nullptr && blueWarrior != nullptr)
	{
		redWarrior->sortWeapons();
		blueWarrior->sortWeapons();
		if (redWarrior->getKind() == wolf && blueWarrior->getKind() != wolf)
		{
			redWarrior->wolfSteal(time, blueWarrior);
		}
		if (blueWarrior->getKind() == wolf && redWarrior->getKind() != wolf)
		{
			blueWarrior->wolfSteal(time, redWarrior);
		}
	}
}
//判断要不要开干
void City::doWar(int time, Headquarter& red, Headquarter& blue)
{
	if(!redWarrior || !blueWarrior)
	{
		return;
	}
	War(time);
	if (redWarrior->getLife() <= 0)
	{
		redWarrior = nullptr;
	}
	if (blueWarrior->getLife() <= 0)
	{
		blueWarrior = nullptr;
	}
}

void City::doReportWarrior(int time)
{
	if (redWarrior)
	{
		redWarrior->resportSituation(time);
	}
	if (blueWarrior)
	{
		blueWarrior->resportSituation(time);
	}
}