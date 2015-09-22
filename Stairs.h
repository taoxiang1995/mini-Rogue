#pragma once
#include "Gameobject.h"
class Stairs :public Gameobject
{
public:
	Stairs(int r, int c, char name, string full_name, Pit* pp, Player* plr) :Gameobject(r, c, name, full_name, pp, plr){}
	
};

