//
//  Dragons.cpp
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/20/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#include "Dragons.h"
#include "utilities.h"

Dragons:: Dragons (int r, int c, char name, string full_name, Pit* p) : Monster(r,c,name, full_name,p)
{
    set_Hit_points(randInt(6)+20);//Hp is between 20-25
    set_stregth_points(4); //strength is between 2
    set_desterity(6);// set desterity between 3;
    set_armor_points(4);//set armor to 2;
    set_weapon_wielding("longsword");
	set_damage_point(randInt(return_strength_points() + 4));
}


void Dragons:: monster_move (int s_r, int s_c, int e_r, int e_c)
{
    ;
}
