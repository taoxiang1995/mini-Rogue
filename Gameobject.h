//
//  Gameobject.h
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/21/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#ifndef __project_3_newestedition__Gameobject__
#define __project_3_newestedition__Gameobject__

#include <stdio.h>

#include <string>
#include "utilities.h"
#include <iostream>
using namespace std;
class Pit;
class Player;

class Gameobject
{
public:
    Gameobject () {}
    Gameobject (int r, int c, char name, string full_name, Pit* pp, Player* plr);
    
    //accessor
    Pit* return_pit () {return m_pit;}
    Player* return_player() {return m_player;}
    int return_r () {return m_r;}
    int return_c () {return m_c;}
    char return_name () {return m_name;}
    string return_full_name () {return m_full_name;}
   // int return_dextrity_bonus () {return dexterity_bonus;}
    int return_damage_amount() {return damage_amount;}
    int return_armor_enhence () {return armor_enhence;}
    int return_strength_enhence() {return strength_enhence;}
    int return_MAX_hitpoint_enhence() {return MAX_hit_point_enhence;}
    int return_dexterity_enhence() {return dexterity_enhence;}
	string return_functionality() { return functionality; }
    //mutator
    void set_pit (Pit* pp) { m_pit=pp;}
    void set_Player(Player* plr) {m_player=plr;}
    void set_r (int r) {m_r = r;}
    void set_c (int c) {m_c = c;}
    void set_name (char name) {m_name = name;}
    void set_full_name (string fullname) {m_full_name = fullname;}
   // void set_dextrity_bonus (int n) {dexterity_bonus = n;}
    void set_damage_amount(int n) { damage_amount = n;}
    void set_armor_enhence (int n) { armor_enhence = n;}
    void set_strength_enhence(int n) {strength_enhence = n;}
    void set_MAX_hitpoint_enhence(int n) {MAX_hit_point_enhence = n;}
    void set_dexterity_enhence(int n) { dexterity_enhence = n;}
	void set_functionality(string n) { functionality = n; }
private:
    int m_r=0;
    int m_c=0;
    Pit* m_pit;
    Player* m_player;
    char m_name;
    string m_full_name;
	string functionality;
    //========for weapons
    //int dexterity_bonus=0;
    int damage_amount=0;
    //========scrolls
    int armor_enhence=0;
    int strength_enhence=0;
    int MAX_hit_point_enhence=0;
    int dexterity_enhence=0;
};


#endif /* defined(__project_3_newestedition__Gameobject__) */
