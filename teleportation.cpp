//
//  teleportation.cpp
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/23/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#include "teleportation.h"

teleportation:: teleportation(int r, int c, char name, string full_name, Pit* pp, Player* plr):Scrolls(r,c,name,full_name,pp,plr)
{
	set_functionality("You feel your body wrenched in space and time.");
}