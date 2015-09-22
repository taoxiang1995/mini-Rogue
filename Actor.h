//
//  Actor.h
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/19/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#ifndef __project_3_newestedition__Actor__
#define __project_3_newestedition__Actor__

#include <stdio.h>
//#include "Pit.h"
#include <string>
#include "Gameobject.h"
using namespace std;


class Pit;
class Gameobject;

class Actor
{
public:
    Actor (){position_r = -1; position_c = -1; m_name = ' ';}
    Actor (int r, int c, char name, string full_name, Pit* p){position_r=r; position_c=c; m_name = name; m_full_name = full_name; m_pit = p;}
    //accesser
    int return_row () {return position_r;}
    int return_col () {return position_c;}
    char return_name () {return m_name;}
    Pit* return_pit() {return m_pit;}
    int return_Hit_point () {return Hit_Points;}
    int return_armor_points () {return armor_points;}
    int return_strength_points () {return strength_points;}
    int return_dexterity_points() {return Dexterity;}
    int return_sleep_time () {return sleep_time;}
	int return_damage_point() { return damage_point; }
	Gameobject* return_weapon_current_wwielding (){ return weapon_current_wwielding; }
    string return_weapon_wielding () {return weapon_wielding;}
    string return_full_name () {return m_full_name;}
 //Gameobject** return_my_object() {return m_object;}
       //mutator
    void set_row (int r){position_r = r;}
    void set_col (int c){position_c = c;}
    void set_name(char name){m_name = name;}
    void set_Hit_points (int n) {Hit_Points = n;}
    void set_armor_points (int n) {armor_points = n;}
    void set_stregth_points (int n) {strength_points = n;}
    void set_desterity (int n) {Dexterity = n;}
    void set_sleeptime (int n) {sleep_time = n;}
    void set_weapon_wielding (string n) {weapon_wielding = n;}
    void set_pit (Pit* pp) {m_pit = pp;}
    void set_full_name (string full_name){m_full_name = full_name;}
	void set_damage_point(int n) { damage_point = n; }
	void set_weapon_current_wwielding(Gameobject* wp) { weapon_current_wwielding = wp; }
    //move one step specified by direction
    bool move (char direc);
    //===========================picking up object
    void operator + (Gameobject* object);
    void display_inventory ();
    
    int return_first_null_index_of_inventory();
    void put_object_to_inventory(int position, Gameobject* object);
	string use_a_scroll(int index);
	string wield_a_weapon(int index);
    
    //=============================move function
    int how_many_steps_needed (int s_r, int s_c, int e_r, int e_c);
    void stupid_move (int s_r, int s_c, int e_r, int e_c, int max_step);
    virtual void monster_move (int s_r, int s_c, int e_r, int e_c){}
    void smart_move (int s_r, int s_c, int e_r, int e_c, char a [][70]);
    int step_needed_for_smart_move (int s_r, int s_c, int e_r, int e_c, char a [][70], int n);
    void generate_an_array_with_monster_indicated(char a[][70]);
	Gameobject* m_object[25];
    
  
private:
    Pit* m_pit;
	Gameobject* weapon_current_wwielding;
    int position_r;
    int position_c;
    char m_name;
    string m_full_name;
   
    
    
    ///////////////properties
    int Hit_Points; //integer from 0 to 99
    int armor_points; //0 to 99 indicating the protectness of the actor, the higher the well protected
    int strength_points; //0-99 how string the actor is when attacking
    int Dexterity; //0-99 how skilled the actor is when using weapon, the higher, the more likely will hit oppent
    int sleep_time; //0-9 how long the actor is gonna to sleep
	int damage_point;//how mch damage caused to a monster.
    string weapon_wielding; //the name of the weapon the actor is holding
    
};

#endif /* defined(__project_3_newestedition__Actor__) */
