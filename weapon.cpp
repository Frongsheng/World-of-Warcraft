#include"weapon.h"
#include"weaponSon.h"
Weapon::Weapon(int _kind, double _coe):kind(_kind),name(Name[_kind]),coe(_coe)
{

}
const string Weapon::Name[] = { "sword","bomb","arrow" };
bool Weapon::operator<(const Weapon& w)const
{
	if (kind == arrow && w.kind == arrow)
	{
		return useCount > w.useCount;
	}
	else
	{
		return kind < w.kind;
	}
}
shared_ptr<Weapon>Weapon::create(int _kind)
{
	if (_kind == sword)
	{
		return make_shared<Sword>(_kind, 0.2);
	}
	else if (_kind == bomb)
	{
		return make_shared<Bomb>(_kind, 0.4);
	}
	else if (_kind == arrow)
	{
		return make_shared<Arrow>(_kind, 0.3);
	}
	else
		abort();
}