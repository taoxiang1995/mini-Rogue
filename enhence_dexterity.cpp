//
//  enhence_dexterity.cpp
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/23/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#include "enhence_dexterity.h"
enhence_dexterity:: enhence_dexterity (int r, int c, char name, string full_name, Pit* pp, Player* plr)
:Scrolls(r,c,name,full_name,pp,plr)
{
	set_functionality("You feel like less of a klutz.");
    set_dexterity_enhence(1);
}
