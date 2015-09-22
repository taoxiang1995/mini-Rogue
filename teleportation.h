//
//  teleportation.h
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/23/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#ifndef __project_3_newestedition__teleportation__
#define __project_3_newestedition__teleportation__

#include <stdio.h>

#include "Scrolls.h"
class teleportation :public Scrolls
{
public:
    teleportation(int r, int c, char name, string full_name, Pit* pp, Player* plr);
};

#endif /* defined(__project_3_newestedition__teleportation__) */
