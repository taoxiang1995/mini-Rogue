//
//  Monster.h
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/20/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#ifndef __project_3_newestedition__Monster__
#define __project_3_newestedition__Monster__

#include <stdio.h>
#include "Actor.h"

class Monster : public Actor
{
public:
    Monster (int r, int c, char name,string full_name, Pit* p):Actor(r,c,name, full_name, p){}
   
    bool check_if_can_move_in_certain_steps (int n,int start_r, int start_c, int end_r, int end_c, int a[][70]);
    
    
private:
    
};

#endif /* defined(__project_3_newestedition__Monster__) */
