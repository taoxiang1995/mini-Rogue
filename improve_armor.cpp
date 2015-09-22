//
//  improve_armor.cpp
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/23/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#include "improve_armor.h"

Improve_armor:: Improve_armor(int r, int c, char name, string full_name, Pit* pp, Player* plr):Scrolls(r,c,name,full_name,pp,plr)
{
    set_armor_enhence(randInt(3)+1);
	set_functionality("Your armor glows blue.");
}