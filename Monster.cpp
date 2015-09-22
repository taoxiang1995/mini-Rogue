//
//  Monster.cpp
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/20/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#include "utilities.h"
#include "Monster.h"
#include "Pit.h"

bool Monster:: check_if_can_move_in_certain_steps(int n,int start_r, int start_c, int end_r, int end_c, int a[][70])
{
    if(start_r==end_r&&start_c==end_c)
        return true;
    else
    {
        if (return_pit()->is_available(start_r+1, start_c)//check downward
            &&check_if_can_move_in_certain_steps(n-1, start_r+1, start_c,end_r, end_c, a))
            return true;
        if (return_pit()->is_available(start_r-1, start_c)//check upward
            &&check_if_can_move_in_certain_steps(n-1, start_r-1, start_c,end_r, end_c, a))
            return true;
        if (return_pit()->is_available(start_r, start_c-1)//check left
            &&check_if_can_move_in_certain_steps(n-1, start_r, start_c-1,end_r, end_c, a))
            return true;
        if (return_pit()->is_available(start_r, start_c+1)//check right
            &&check_if_can_move_in_certain_steps(n-1, start_r, start_c+1,end_r, end_c, a))
            return true;
    }
    return false;
}