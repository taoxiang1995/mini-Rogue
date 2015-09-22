#pragma once
#include "Weapon.h"
class Magic_fangs :public Weapon
{
public:
	Magic_fangs(int r, int c, char name, string full_name, Pit* pp, Player* plr) :Weapon(r, c, name, full_name, pp, plr)
	{
		set_dexterity_enhence(3);
		set_damage_amount(2);
	}
};

