//
//  Bogeymen.cpp
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/20/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#include "Bogeymen.h"
#include "utilities.h"
#include "Shortsword.h"

Bogeymen:: Bogeymen (int r, int c, char name, string full_name, Pit* p) : Monster(r,c,name, full_name,p)
{
	
	
    set_Hit_points(randInt(6)+5);//Hp is between 5-10
    set_stregth_points(randInt(2)+2); //strength is between 2-3
	set_desterity(randInt(2) + 2);// set desterity between 2-3;
    set_armor_points(2);//set armor to 2;
    set_weapon_wielding("shortsword");
	set_damage_point(randInt(return_strength_points() +2));
}



void Bogeymen:: auto_move ()
{
    
}

void Bogeymen:: monster_move (int s_r, int s_c, int e_r, int e_c)
{
    stupid_move(s_r, s_c, e_r, e_c, 5);
}