//
//  Player.cpp
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/19/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#include "Player.h"
#include "Pit.h"
#include "Shortsword.h"
Player::Player():Actor()
{
    
}

Player::Player(int r, int c, char name, string full_name, Pit* p)
:Actor(r, c, name, full_name,  p)
{
	m_object[0] = new Shortsword(-1, -1, ')', "Short swords", return_pit(), this);
	set_weapon_current_wwielding(m_object[0]);
    set_Hit_points(20);
    set_armor_points(2);
    set_stregth_points(2);
    set_desterity(2+return_weapon_current_wwielding()->return_dexterity_enhence());
    set_weapon_wielding("shortSword");
	set_damage_point(randInt(return_strength_points() + return_weapon_current_wwielding()->return_damage_amount()));
}

//(int r, int c, char name, string full_name, Pit* pp, Player* plr)
