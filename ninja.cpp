#include "ninja.h"
#include"headquarter.h"
void Ninja::doReportBirth()
{
	printf("It has a sword and a bomb\n");
}

Ninja::Ninja(int _kind, Headquarter* phq, int _id, int _life) :Warrior(_kind, phq, _id, _life)
{
	
}
