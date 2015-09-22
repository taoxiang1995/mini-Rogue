//
//  raise_strength.cpp
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/23/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#include "raise_strength.h"

Raise_strength:: Raise_strength (int r, int c, char name, string full_name, Pit* pp, Player* plr)
:Scrolls(r,c,name,full_name,pp,plr)
{
	set_functionality("Your muscles bulge.");
    set_strength_enhence(randInt(3)+1);
}