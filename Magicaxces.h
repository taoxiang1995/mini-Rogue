#pragma once
#include "Weapon.h"
class Magicaxces :public Weapon
{
public:
	Magicaxces(int r, int c, char name, string full_name, Pit* pp, Player* plr) :Weapon(r, c, name, full_name, pp, plr)
	{
		set_dexterity_enhence(5);
		set_damage_amount(5);
	}
};

