//
//  Pit.h
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/19/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#ifndef __project_3_newestedition__Pit__
#define __project_3_newestedition__Pit__

#include <stdio.h>
#include <iostream>
#include "Player.h"

using namespace std;

class Player;
class Monster;
class Gameobject;

class Pit
{
public:
    
    Pit  (int level);
    //display the dungeon and the objects on it
    //right now only dungeon and player are available.
    void display();
    //check certain position is avilable to place a monster or a player
    bool is_available (int r, int c);
    bool is_available_for_object(int r, int c);

    //generate a random position where can put a monster or player
    bool generate_random_avilable_position (int& r, int &c);
    
    //add player, objects, and monsters
    void add_player (int r, int c);
    
    //generate numbers of each four monsters
    void generate_random_number_of_monster (int& n_bogeymen, int& n_snakewomen,int& n_dragons, int& n_goblins);
    bool generate_random_avilable_position_for_object (int&r, int&c);

    //accesser
    Player* return_player (){return m_player;}
    int return_level () {return m_level;}
    Actor* return_pointer_to_actor_on_certain_direction (int r, int c, char direc);
    Actor* return_pointer_to_actor_on_position(int r, int c);
    Gameobject* return_pointer_to_object_on_position (int r, int c);
    //mutator
    void set_player(Player* pp){m_player = pp;}
    
    //add monsters
    void add_bogeymen (int r, int c) {}
    
    //attacking function
    bool weather_hit(Actor* attacker, Actor* defender);
    string attack (Actor* attacker , Actor* defender);
    
    //set to death
    bool set_death (Actor* dead_monster);
    
    //pick shit function
    
    string pick_up (Actor* plr, Gameobject* object_picked_up);
    char return_char_on_certain_position (int r, int c);
    int return_first_available_index_in_m_object();

private:
   
    Player* m_player;
    Monster* m_monster[26];
    Gameobject* m_objects[100];
    char dungeon [18] [70];
    //start from 0-4
    int m_level;
       //create a 18*70 dungeon with space and path on it.
    void create_dungeon ();
    //add items to the pit:
    
    //void add_monster (int r, int c);
    //void add_player (int r, int c);
    //void add_weapon (int r, int c);
    //void add_scrolls (int r, int c);
    
    //dungeon generator
    void set_up_dungeon();
    bool check_available (int r, int c, int length, int width);
    void build_feature(int r, int c, int length, int width);
    void generate_first_room (int&rand_length, int& rand_width);
    bool generate_dungeon (int r, int c, int width, int length);
    bool check_if_available_to_put_room_on_given_wall(int r, int c, int length, int width, int direction);
    void fill_with_wall ();
    //return a pointer to the actor on that certain position
    
    
    
    
    
};


#endif /* defined(__project_3_newestedition__Pit__) */
