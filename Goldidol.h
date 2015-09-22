#pragma once
#include "Gameobject.h"
class Goldidol: public Gameobject
{
public:
	Goldidol(int r, int c, char name, string full_name, Pit* pp, Player* plr) :Gameobject(r, c, name, full_name, pp, plr){}
	
};

