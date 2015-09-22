//
//  Goblins.cpp
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/20/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#include "Goblins.h"
#include "utilities.h"
#include <iostream>
using namespace std;

Goblins:: Goblins (int r, int c, char name, string full_name, Pit* p) : Monster(r,c,name, full_name, p)
{
    set_Hit_points(randInt(6)+15);//Hp is between 15-20
    set_stregth_points(3); //strength is between 3
    set_desterity(1);// set desterity between 1;
    set_armor_points(1);//set armor to 1;
	set_damage_point(randInt(return_strength_points() + 2));
    set_weapon_wielding("shortsword");
}

void Goblins:: monster_move (int s_r, int s_c, int e_r, int e_c)
{
    char duplicate_dungeon [18][70];
    generate_an_array_with_monster_indicated(duplicate_dungeon);
    
    smart_move(s_r, s_c, e_r, e_c, duplicate_dungeon);
}