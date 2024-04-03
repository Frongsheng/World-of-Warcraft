#include "warrior.h"
#include"headquarter.h"
#include"lion.h"
#include"ninja.h"
#include"dragon.h"
#include"wolf.h"
#include"iceman.h"
#include<cstdio>
#include<algorithm>

const string Warrior::Name[] = {"dragon", "ninja", "iceman","lion", "wolf"};

Warrior::Warrior(int _kind, Headquarter* hq, int _id, int _life)
{
	kind = _kind;
	pHeadquarter = hq;
	id = _id;
	life = _life;
	name = Name[_kind];
}

shared_ptr<Warrior> Warrior::createWarrior(int _kind, Headquarter* phq, int _id, int _life)
{
	switch (_kind)
	{
		case dragon:
			return make_shared<Dragon>(_kind, phq, _id, _life);
			break;
		case lion:
			return make_shared<Lion>(_kind, phq, _id, _life);
			break;
		case ninja:
			return make_shared<Ninja>(_kind, phq, _id, _life);
			break;
		case wolf:
			return make_shared<Wolf>(_kind, phq, _id, _life);
			break;
		case iceman:
			return make_shared<Iceman>(_kind, phq, _id, _life);
			break;
		default:
			break;
	}
}

void Warrior::reportBirth(int time)
{
	if (pHeadquarter->getKind() == r)
		printf("%03d red %s %d born with strength %d,%d %s in red headquarter\n", time, name.c_str(),id, life, pHeadquarter->getKindNum(kind), name.c_str());
	else if(pHeadquarter->getKind() == b)
		printf("%03d blue %s %d born with strength %d,%d %s in blue headquarter\n", time, name.c_str(),id, life, pHeadquarter->getKindNum(kind), name.c_str());
	doReportBirth();
}

