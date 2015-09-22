//
//  Goblins.h
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/20/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#ifndef __project_3_newestedition__Goblins__
#define __project_3_newestedition__Goblins__

#include <stdio.h>
#include "Monster.h"
class Goblins : public Monster
{
public:
    Goblins (int r, int c, char name, string full_name, Pit* p);
    virtual void monster_move (int s_r, int s_c, int e_r, int e_c);
private:
    

};


#endif /* defined(__project_3_newestedition__Goblins__) */
