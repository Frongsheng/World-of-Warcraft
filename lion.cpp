#include "lion.h"
#include"headquarter.h"
void Lion::doReportBirth()
{
	printf("It`s loyalty is %d\n",loyalty);
}

Lion::Lion(int _kind, Headquarter* phq, int _id, int _life) : Warrior(_kind, phq, _id, _life)
{
	loyalty = phq->getleftValue();
}
