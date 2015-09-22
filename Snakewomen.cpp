//
//  Snakewomen.cpp
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/20/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#include "Snakewomen.h"
#include "utilities.h"

Snakewomen:: Snakewomen (int r, int c, char name, string full_name, Pit* p) : Monster(r,c,name, full_name,p)
{
    set_Hit_points(randInt(4)+3);//Hp is between 3-6
    set_stregth_points(2); //strength is between 2
    set_desterity(6);// set desterity between 3;
    set_armor_points(2);//set armor to 2;
	set_damage_point(randInt(return_strength_points() + 2));
    set_weapon_wielding("magicfangsofsleep");
 
}

void Snakewomen:: monster_move (int s_r, int s_c, int e_r, int e_c)
{
    stupid_move(s_r, s_c, e_r, e_c, 3);
}