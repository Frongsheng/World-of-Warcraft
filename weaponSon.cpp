#include"weaponSon.h"

bool Sword::afterOneUse()
{
	return 1;
}

bool Bomb::afterOneUse()
{
	return 0;
}

bool Arrow::afterOneUse()
{
	useCount++;
	if (useCount == 2)
	{
		return 0;
	}
	return 1;
}