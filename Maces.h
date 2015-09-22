#pragma once
#include "Weapon.h"
class Maces :public Weapon
{
public:
	Maces(int r, int c, char name, string full_name, Pit* pp, Player* plr) : Weapon(r, c, name, full_name, pp, plr)
	{
		set_damage_amount(2);
	}
};

