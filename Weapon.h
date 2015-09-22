
#pragma once

#include "Gameobject.h"
class Weapon :public Gameobject
{
public:
	Weapon(int r, int c, char name, string full_name, Pit* pp, Player* plr) :Gameobject(r, c, name, full_name, pp, plr){}
	
};

