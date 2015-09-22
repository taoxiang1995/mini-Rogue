#pragma once
#include "Weapon.h"
class Longswort :public Weapon
{
public:
	Longswort(int r, int c, char name, string full_name, Pit* pp, Player* plr) :Weapon(r, c, name, full_name, pp, plr)
	{
		set_dexterity_enhence(2);
		set_damage_amount(4);
	}
};

