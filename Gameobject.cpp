//
//  Gameobject.cpp
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/21/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#include "Gameobject.h"

Gameobject:: Gameobject (int r, int c, char name, string full_name, Pit* pp, Player* plr)
{
    m_r = r;
    m_c = c;
    m_full_name = full_name;
    m_name = name;
    m_pit = pp;
    m_player = plr;
}
