//
//  Dragons.h
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/22/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#ifndef project_3_newestedition_Dragons_h
#define project_3_newestedition_Dragons_h
#include <stdio.h>
#include "Monster.h"
class Dragons : public Monster
{
public:
    Dragons (int r, int c, char name, string full_name, Pit* p);
    virtual void monster_move (int s_r, int s_c, int e_r, int e_c);
private:

};



#endif
