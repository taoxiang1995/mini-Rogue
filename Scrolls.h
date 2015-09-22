//
//  Scrolls.h
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/23/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#ifndef __project_3_newestedition__Scrolls__
#define __project_3_newestedition__Scrolls__

#include <stdio.h>
#include "Gameobject.h"
class Scrolls :public Gameobject
{
public:
    Scrolls (int r, int c, char name, string full_name, Pit* pp, Player* plr):Gameobject(r,c,name,full_name,pp,plr){}
    
};

#endif /* defined(__project_3_newestedition__Scrolls__) */
