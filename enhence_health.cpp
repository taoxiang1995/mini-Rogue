
//
//  enhence_health.cpp
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/23/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#include "enhence_health.h"

enhence_health:: enhence_health(int r, int c, char name, string full_name, Pit* pp, Player* plr):Scrolls(r,c,name,full_name,pp,plr)
{
    set_MAX_hitpoint_enhence(randInt(6)+3);
	set_functionality("You feel your heart beating stronger.");
}