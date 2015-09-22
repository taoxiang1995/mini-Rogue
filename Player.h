//
//  Player.h
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/19/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#ifndef __project_3_newestedition__Player__
#define __project_3_newestedition__Player__

#include <stdio.h>
#include "Actor.h"

class Player : public Actor
{
public:
    Player();
    Player(int r, int c, char name, string full_name, Pit* p);
    
private:
       
};

#endif /* defined(__project_3_newestedition__Player__) */
