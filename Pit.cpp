//
//  Pit.cpp
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/19/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//



#include "Bogeymen.h"
#include "Snakewomen.h"
#include "Dragons.h"
#include "Goblins.h"
#include "Actor.h"
#include "utilities.h"
#include "Pit.h"
#include "Gameobject.h"
#include "enhence_dexterity.h"
#include "enhence_health.h"
#include "improve_armor.h"
#include "raise_strength.h"
#include "teleportation.h"
#include "Scrolls.h"
#include "Maces.h"
#include "Shortsword.h"
#include "Longswort.h"
#include "Stairs.h"
#include "Goldidol.h"
#include "Magicaxces.h"
#include "Magic_fangs.h"


//==================================helper functions for dungeon
bool Pit:: check_available (int r, int c, int length, int width)
{
    if (r<1||r+width>16||c<1||c+length>68)
        return false;
    for (int i1 = r-1; i1<r+width+1; i1++)
    {
        for (int i2=c-1; i2<c+length+1; i2++)
        {
            if (dungeon[i1][i2]!='#')
                return false;
        }
    }
    
    return true;
}

//given a certain position and size, generate a room/coridor
void Pit:: build_feature(int r, int c, int length, int width)
{
    for (int i1=r; i1<r+width; i1++)
    {
        for (int i2=c; i2<c+length; i2++)
            dungeon[i1][i2] = ' ';
    }
}

//generate the first room, the room always positioned at [2][3]
void Pit:: generate_first_room (int&rand_length, int& rand_width)
{
   
    rand_length = randInt(8)+3;
    rand_width = randInt(6)+3;
    build_feature(9, 35, rand_length, rand_width);
}

//take in the position of the upper left point of room, the length and width of room
bool Pit:: generate_dungeon(int r, int c, int length, int width)
{
    int cori_width(0), cori_length(0), room_width(0), room_length(0);
    //check and build in north direction
    cori_length=rand()%3+2; room_width=rand()%6+4; room_length=rand()%8+4;
    
    int lower_corridor_colon = (rand()%length)+c;
    int upper_corridor_colon = lower_corridor_colon-(rand()%room_length);
    if (check_available(r-cori_length-room_width, upper_corridor_colon, room_length, room_width))
    {
        build_feature(r-cori_length-room_width, upper_corridor_colon, room_length, room_width);
        build_feature(r-cori_length, lower_corridor_colon, 1, cori_length);
        generate_dungeon(r-cori_length-room_width, upper_corridor_colon, room_length, room_width);
    }
    
    
    //check and build in south direction
    cori_length=rand()%3+2; room_width=rand()%6+4; room_length=rand()%8+4;
    lower_corridor_colon = (rand()%length)+c;
    upper_corridor_colon = lower_corridor_colon-(rand()%room_length);
    if (check_available(r+cori_length+width, upper_corridor_colon-1, room_length, room_width))
    {
        build_feature(r+cori_length+width, upper_corridor_colon, room_length, room_width);
        build_feature(r+width, lower_corridor_colon, 1, cori_length);
        generate_dungeon(r+cori_length+width, upper_corridor_colon, room_length, room_width);
    }
    
    
    //check and build in east direction
    cori_length=rand()%3+2; room_width=rand()%6+4; room_length=rand()%8+4;
    int close_row = (rand()%width)+r;
    int far_row= close_row-(rand()%room_width);
    if (check_available(far_row, c+length+cori_length, room_length, room_width))
    {
        build_feature(far_row, c+length+cori_length, room_length, room_width);
        build_feature(close_row, c+length, cori_length, 1);
        generate_dungeon(far_row, c+length+cori_length, room_length, room_width);
    }
    
    
    //check and build in west direction
    cori_length=rand()%3+2; room_width=rand()%6+4; room_length=rand()%8+4;
    close_row = (rand()%width)+r;
    far_row= close_row-(rand()%room_width);
    if (check_available(far_row, c-room_length-cori_length, room_length, room_width))
    {
        build_feature(far_row, c-cori_length-room_length, room_length, room_width);
        build_feature(close_row, c-cori_length, cori_length, 1);
        generate_dungeon(far_row, c-cori_length-room_length, room_length, room_width);
    }
    
    
    return false;
}

void Pit:: set_up_dungeon()
{
    
    
            fill_with_wall();
        int first_room_length(0), first_room_width(0);
        generate_first_room(first_room_length, first_room_width);
        generate_dungeon(9, 35,first_room_length, first_room_width);
    
}

void Pit:: fill_with_wall ()
{
    for (int i=0; i<18; i++)
    {
        for (int i2=0; i2<70; i2++)
            dungeon[i][i2]='#';
        
    }
    
}
//======================================================end of the helper function for dungeon

Pit::Pit(int level)
{
    int n_bogeymen(0), n_snakewomen(0), n_dragons(0),  n_goblins(0);//random number for each monster;
    int p_r(0),  p_c(0);
    int number_of_objects = randInt(2)+2;//2 or 3
    m_level = level;
    set_up_dungeon();
    generate_random_number_of_monster(n_bogeymen, n_snakewomen, n_dragons, n_goblins);

    for (int i =0; i<n_bogeymen; i++)//generate bogeymen
    {
        
        generate_random_avilable_position(p_r, p_c);
        m_monster[i] = new Bogeymen (p_r, p_c, 'B', "Bogeymen", this);
        
    }
    for (int i=n_bogeymen; i<n_bogeymen+n_snakewomen; i++)//generate snakewomen
    {
        generate_random_avilable_position(p_r, p_c);
        m_monster[i] = new Snakewomen (p_r, p_c, 'S', "Snakewomen", this);
    }
    for(int i = n_bogeymen+n_snakewomen; i<n_bogeymen+n_snakewomen+n_dragons; i++ )//generate dragons
    {
        generate_random_avilable_position(p_r, p_c);
        m_monster[i] = new Dragons (p_r, p_c, 'D',"Dragons", this);
    }
    for (int i = n_bogeymen+n_snakewomen+n_dragons; i<n_bogeymen+n_snakewomen+n_dragons+n_goblins; i++)//generate goblins
    {
        generate_random_avilable_position(p_r, p_c);
        m_monster[i] = new Goblins (p_r, p_c, 'G', "Goblins", this);
    }
    //set up scrolls and weapons
    for (int i = 0; i<number_of_objects; i++)
    {
        int r(0), c(0);
        generate_random_avilable_position_for_object(r, c);
        int index_of_objects = randInt(7);//from 0 to 6, each number means a certain kind of objects. eg. 0-4 stads
        switch (index_of_objects)
        {
            case 0://improve_armor
                m_objects[i]=new Improve_armor (r,c,'?',"Improve_armor",this,m_player);
                break;
            case 1://raise_strength
                m_objects[i] = new Raise_strength (r,c,'?',"Raise_strength",this,m_player);
                break;
            case 2://enhence_health
                m_objects[i] = new enhence_health (r,c,'?',"enhence_health",this,m_player);
                break;
            case 3: //enhence_dexterity
                m_objects[i] = new enhence_dexterity (r,c,'?',"enhence_dexterity",this,m_player);
                break;
			case 4:
				m_objects[i] = new Maces(r, c, ')', "Maces", this, m_player);
				break;
			case 5:
				m_objects[i] = new Shortsword(r, c, ')', "Short swords", this, m_player);
				break;
			case 6:
				m_objects[i] = new Longswort(r, c, ')', "Long swords", this, m_player);
				break;
        }
    }
	int r(0), c(0);
	generate_random_avilable_position_for_object(r, c);
	m_objects[97] = new Stairs(r, c, '>', "Stairs", this, m_player);
	if (m_level == 4)
	{
		generate_random_avilable_position_for_object(r, c);
		m_objects[98] = new Goldidol (r, c, '&',"Gold idol", this, m_player);
	}
	

    
}

void Pit:: display()
{
    clearScreen();
    cout<<endl;
    for (int i1=0; i1<18; i1++)
    {
        for (int i2=0; i2<70; i2++)
        {
            
            if(return_pointer_to_actor_on_position(i1, i2)!=nullptr)
            {
                cout<<return_pointer_to_actor_on_position(i1, i2)->return_name();
            }
            else if (return_pointer_to_object_on_position(i1, i2)!=nullptr)
            {
                cout<<return_pointer_to_object_on_position(i1, i2)->return_name();
            }
            
            else
                cout<<dungeon[i1][i2];
            
        }
        cout<<endl;
    }
    
    cout<<"Dungeon Level: "<<m_level<<", "<<"Hit points: "<<m_player->return_Hit_point()
    <<", Armor: "<<m_player->return_armor_points()<<", Strength: "<<m_player->return_strength_points()
    <<", Dexterity: "<<m_player->return_dexterity_points()<<endl;
}

void Pit::add_player(int r, int c)
{
    m_player = new Player(r, c, '@', "Player", this);
}

bool Pit:: is_available(int r, int c)
{
    if (dungeon[r][c]=='#')
        return false;
    else if (return_pointer_to_actor_on_position(r, c)!=nullptr)
        return false;
    else
        return true;
}

bool Pit:: is_available_for_object(int r, int c)
{
    if (dungeon[r][c]=='#')
        return false;
    else if (return_pointer_to_object_on_position(r, c) !=nullptr)
        return false;
    else
        return true;
}

bool Pit:: generate_random_avilable_position(int& r, int& c)
{
    r=randInt(18);
    c=randInt(70);
    while (!is_available(r, c))
    {
        r=randInt(18);
        c=randInt(70);
    }
    
    return true;
}

bool Pit:: generate_random_avilable_position_for_object (int&r, int&c)
{
    r=randInt(18);
    c=randInt(70);
    while (!is_available_for_object(r, c))
    {
        r=randInt(18);
        c=randInt(70);
    }
    
    return true;
    
}
void Pit::generate_random_number_of_monster(int& n_bogeymen, int& n_snakewomen,int& n_dragons, int& n_goblins)
{
    switch (m_level)
    {
        case 0:
            n_bogeymen = 0;
            n_dragons = 0;
            n_snakewomen = randInt(5)+1;
            n_goblins = randInt(5-n_snakewomen+1)+1;
            break;
            
        case 1:
            n_bogeymen = 0;
            n_dragons = 0;
            n_snakewomen = randInt(10)+1;
            n_goblins = randInt(10-n_snakewomen+1)+1;
            break;
        case 2:
            n_bogeymen = randInt(15)+1;
            n_dragons = 0;
            n_snakewomen = randInt(15-n_bogeymen+1)+1;
            n_goblins = randInt(15-n_bogeymen-n_snakewomen+2);
            break;
        case 3:
            n_bogeymen = randInt(18)+1;
            n_dragons = randInt(18-n_bogeymen+1)+1;
            n_goblins = randInt(18-n_bogeymen-n_dragons+2);
            n_snakewomen = randInt(18-n_goblins-n_dragons-n_bogeymen+3);
            break;
        
        case 4:
            n_bogeymen = randInt(23)+1;
            n_dragons = randInt(23-n_bogeymen+1)+1;
            n_goblins = randInt(23-n_bogeymen-n_dragons+2);
            n_snakewomen = randInt(23-n_goblins-n_dragons-n_bogeymen+3);
            break;
    }
}

Actor* Pit::return_pointer_to_actor_on_position(int r, int c)
{
    if (m_player!=nullptr&& m_player->return_row()==r&&m_player->return_col()==c)
        return m_player;
    else
    {
        for (int i=0;i<26; i++)
        {
            //cout<<"r:"<<r<<"return r"<<m_monster[i]->return_row()<<endl;
            if (m_monster[i]!=nullptr&&m_monster[i]->return_row()==r&&m_monster[i]->return_col()==c)
            {
                
                return m_monster[i];
            }
        }
    }
    return nullptr;
}

Gameobject* Pit::return_pointer_to_object_on_position (int r, int c)
{
    for (int i=0;i<100;i++)
    {
        if (m_objects[i]!=nullptr&&m_objects[i]->return_r()==r&&m_objects[i]->return_c()==c)
            return m_objects[i];
    }
    return nullptr;
}



//=============battle function:

bool Pit:: weather_hit(Actor* attacker, Actor* defender)
{
    if(attacker==nullptr||defender==nullptr)
        return false;
    else
    {
        int attackerPoints = attacker->return_dexterity_points(); //missing weapon dexterity bonus
        int defenderPoints = defender->return_dexterity_points(); //missing weapons dexterity bonus
        return (randInt(attackerPoints)>=randInt(defenderPoints));

        
    }
}


string Pit:: attack (Actor* attacker, Actor* defender)
{
    string outcome;
    if (attacker==nullptr||defender==nullptr)
        return outcome;
    
    else if (weather_hit(attacker, defender))
    {
		int damage_points = attacker->return_damage_point();// missing weapon demage amount
        int defender_new_hp = defender->return_Hit_point()-damage_points;
        defender->set_Hit_points(defender_new_hp);
        if (defender->return_name()=='D'&&randInt(10)==3)
        {
            defender->set_Hit_points(defender->return_Hit_point()+1);
        }
        if (defender_new_hp<=0)
        {
            
            outcome = attacker->return_full_name()+" slashes short sword at the "+defender->return_full_name()
            +" dealing a final blow.";
            //=========drop a object
            if (defender->return_name()=='B')
            {
                if (randInt(10)==5
                    &&return_pointer_to_object_on_position(defender->return_row(), defender->return_col())==nullptr)
                {
                    m_objects[return_first_available_index_in_m_object()]=
                    new Magicaxces(defender->return_row(), defender->return_col(), ')', "Magicaxces", this, m_player);
                }
            }
            
            if (defender->return_name()=='S')
            {
                if (randInt(3)==2
                    &&return_pointer_to_object_on_position(defender->return_row(), defender->return_col())==nullptr)
                {
                 
                    m_objects[return_first_available_index_in_m_object()]=
                    new Magic_fangs (defender->return_row(), defender->return_col(), ')', "Magic fangs", this, m_player);
                }
            }
            
            if (defender->return_name()=='D')
            {
                if (return_pointer_to_object_on_position(defender->return_row(), defender->return_col())==nullptr)
                {
                    
                    m_objects[return_first_available_index_in_m_object()]=
                    new teleportation (defender->return_row(), defender->return_col(), '?', "teleportation", this, m_player);
                }
            }
            
            if (defender->return_name()=='G')
            {
                if (randInt(3)==2
                    &&return_pointer_to_object_on_position(defender->return_row(), defender->return_col())==nullptr)
                {
                    if (randInt(2)==1)
                    {
                        m_objects[return_first_available_index_in_m_object()]=
                        new Magic_fangs (defender->return_row(), defender->return_col(), ')', "Magic fangs", this, m_player);
                    }
                    else
                    {
                        m_objects[return_first_available_index_in_m_object()]=
                        new Magicaxces(defender->return_row(), defender->return_col(), ')', "Magicaxces", this, m_player);
 
                    }
                    
                }
            }
            
            
            set_death(defender);
            //defender = nullptr;
        }
        else
        {
            outcome = attacker->return_full_name()+" slashes short sword at the "+defender->return_full_name()
            +" and hits.";
        }
    }
    else
    {
        outcome = attacker->return_full_name()+" slashes short sword at the "+defender->return_full_name()
        +" and misses.";
    }
    return outcome;
}

Actor* Pit::return_pointer_to_actor_on_certain_direction (int r, int c, char direc)
{
    switch (direc)
    {
        case ARROW_DOWN:
            return return_pointer_to_actor_on_position(r+1, c);
            
            break;
        case ARROW_UP:
            return return_pointer_to_actor_on_position(r-1, c);

            break;
        case ARROW_LEFT:
            return return_pointer_to_actor_on_position(r, c-1);

            break;
        case ARROW_RIGHT:
            return return_pointer_to_actor_on_position(r, c+1);

            break;
    }
    
    return nullptr;
}

//set to death
bool Pit:: set_death (Actor* dead_monster)
{
    for (int i=0; i<26; i++)
    {
        if (m_monster[i]==dead_monster)
        {
            delete m_monster[i];
            m_monster[i]=nullptr;
            return true;
        }
    }
    return false;
}

//==========picking things up

string Pit:: pick_up (Actor* plr, Gameobject* object_picked_up)
{
    int index_of_inventory =  plr->return_first_null_index_of_inventory();
    plr->put_object_to_inventory(index_of_inventory, object_picked_up);
	string outcome_pick_up_scroll = "";
	if (object_picked_up->return_name() == '?')
	{
		outcome_pick_up_scroll = "You pick up a scroll called " + object_picked_up->return_full_name();
		for (int i = 0; i<100; i++)
		{
			if (m_objects[i] == object_picked_up)
			{
				m_objects[i] = nullptr;
			}
		}
	}
		
	else if (object_picked_up->return_name() == ')')
	{
		outcome_pick_up_scroll = "You pick up " + object_picked_up->return_full_name();
		for (int i = 0; i<100; i++)
		{
			if (m_objects[i] == object_picked_up)
			{
				m_objects[i] = nullptr;
			}
		}
	}
		
	return outcome_pick_up_scroll;
}

char Pit:: return_char_on_certain_position (int r, int c)
{
    return dungeon[r][c];
}

int Pit:: return_first_available_index_in_m_object()
{
    for (int i=0; i<100; i++)
    {
        if (m_objects[i]==nullptr)
            return i;
    }
    return 100;
}
