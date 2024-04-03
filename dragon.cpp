#include "dragon.h"
#include"headquarter.h"
void Dragon::doReportBirth()
{
	printf("It has a arrow, and its morale is %0.2f\n", morale);
}

Dragon::Dragon(int _kind, Headquarter* phq, int _id, int _life) :Warrior(_kind, phq, _id, _life)
{
	morale = static_cast<double>(phq->getleftValue()) / _life;
}
