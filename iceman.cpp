#include "iceman.h"
#include"headquarter.h"
void Iceman::doReportBirth()
{
	printf("It has a bomb\n");
}

Iceman::Iceman(int _kind, Headquarter* phq, int _id, int _life) :Warrior(_kind, phq, _id, _life)
{

}
