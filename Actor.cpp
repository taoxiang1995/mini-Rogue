//
//  Actor.cpp
//  project#3 newestedition
//
//  Created by Tao Xiang on 5/19/15.
//  Copyright (c) 2015 Tao Xiang. All rights reserved.
//

#include "Actor.h"
#include "utilities.h"
#include "Pit.h"
#include "Gameobject.h"

//========================================for pick and use weapon and scrolls
void Actor:: operator + (Gameobject* object)
{
    if (object->return_full_name()=="teleportation")
    {
        m_pit->generate_random_avilable_position(position_r, position_c);
        
    }
    Hit_Points = Hit_Points+object->return_MAX_hitpoint_enhence();
    armor_points = armor_points+object->return_armor_enhence();
    strength_points = strength_points+object->return_strength_enhence();
    Dexterity = Dexterity+object->return_dexterity_enhence();
    
}

void Actor::display_inventory()
{
	clearScreen();
	cout << "Inventory:" << endl;
	char index = 'a';

	for (int i = 0; i < 25; i++)
	{
		if (m_object[i] != nullptr)
			cout << index++ << ". " << m_object[i]->return_full_name() << endl;

	}
}

int Actor:: return_first_null_index_of_inventory()
{
    for (int i=0; i<25; i++)
    {
        if (m_object[i]==nullptr)
            return i;
    }
    
        return 25;
}

void Actor:: put_object_to_inventory(int position, Gameobject* object)
{
    m_object[position]= object;
    
}

string Actor::use_a_scroll(int index)
{
	if (m_object[index] == nullptr || m_object[index]->return_name()!='?')
		return "";
	else
	{
		operator+(m_object[index]);
		string temp=
	"You read the scroll called scroll of " + m_object[index]->return_full_name() + "\n" + m_object[index]->return_functionality();
		
		delete m_object[index];
		m_object[index] = nullptr;
		return temp;

	}
	

}

string Actor::wield_a_weapon(int index)
{
	if (m_object[index] == nullptr || m_object[index]->return_name() != ')')
		return "";
	else
	{
		weapon_current_wwielding = m_object[index];
		
		string temp =
			"You are wielding " + m_object[index]->return_full_name();
		set_desterity(2 + m_object[index]->return_dexterity_enhence());
		set_damage_point(m_object[index]->return_damage_amount());

		return temp;

	}

}

//=====================move functions

bool Actor:: move(char direc)
{
    switch (direc)
    {
        case ARROW_DOWN:
            if (return_pit()->is_available(return_row()+1, return_col()))
                set_row(return_row()+1);
            else
                
                return false;
            
            break;
        case ARROW_UP:
            if (return_pit()->is_available(return_row()-1, return_col()))
                set_row(return_row()-1);
            else
                return false;
            break;
        case ARROW_LEFT:
            if (return_pit()->is_available(return_row(), return_col()-1))
                set_col(return_col()-1);
            else
                return false;
            break;
        case ARROW_RIGHT:
            if (return_pit()->is_available(return_row(), return_col()+1))
                set_col(return_col()+1);
            else
                return false;
            break;
    }
    
    return true;
    
}

int Actor:: how_many_steps_needed (int s_r, int s_c, int e_r, int e_c)
{
    int absolute_value_of_row=0;
    if ((s_r-e_r)<0)
        absolute_value_of_row = -(s_r-e_r);
    else
        absolute_value_of_row = (s_r-e_r);
    
    int absolute_value_of_cal = 0;
    if ((s_c-e_c)<0)
        absolute_value_of_cal = -(s_c-e_c);
    else
        absolute_value_of_cal = (s_c-e_c);
    
    return absolute_value_of_cal+absolute_value_of_row;
    
}

void Actor:: stupid_move (int s_r, int s_c, int e_r, int e_c, int max_step)
{
    int step_needed = how_many_steps_needed(s_r, s_c, e_r, e_c);
    if (step_needed>max_step)
        return;
    else if (how_many_steps_needed(s_r+1, s_c, e_r, e_c)<step_needed&&move(ARROW_DOWN))
    {
        
    }
    else if(how_many_steps_needed(s_r-1, s_c, e_r, e_c)<step_needed&&move(ARROW_UP))
    {
        
    }
    
    else if(how_many_steps_needed(s_r, s_c+1, e_r, e_c)<step_needed&&move(ARROW_RIGHT))
    {
        
    }
    
    else if(how_many_steps_needed(s_r, s_c-1, e_r, e_c)<step_needed&&move(ARROW_LEFT))
    {
        
    }
}
//takein the current position and destination position, return the step needed to get to the destination (get by the wall)
int Actor:: step_needed_for_smart_move (int s_r, int s_c, int e_r, int e_c, char a [][70], int n)
{
    char depth = 'a';
    int up(16), down(16), left(16), right(16);
    int numbers [4];
    if (how_many_steps_needed(s_r, s_c, e_r, e_c)==1)
    {
        return 1;
    }
    
    else
    {
        if ((depth+n)<a[s_r][s_c])
        {
            a[s_r][s_c]= depth+n;
        }
        else
            return 16;
        
        if (a[s_r-1][s_c]=='.')
        {
             up = 1+step_needed_for_smart_move(s_r-1, s_c, e_r, e_c, a, n++);
            
        }
        
        
        if (a[s_r+1][s_c]=='.')
        {
            down = 1+step_needed_for_smart_move(s_r+1, s_c, e_r, e_c, a, n++);
            
        }
        
        
        if (a[s_r][s_c-1]=='.')
        {
            left = 1+step_needed_for_smart_move(s_r, s_c-1, e_r, e_c, a, n++);
            
        }
        
        
        if (a[s_r][s_c+1]=='.')
        {
            right = 1+step_needed_for_smart_move(s_r, s_c+1, e_r, e_c, a, n++);
            
        }
        
        numbers[0] = up; numbers[1] = down; numbers[2] = left; numbers[3] = right;
        int smallest = numbers[0];
        for (int i=0; i<4; i++)
        {
           if (smallest>numbers[i])
               smallest = numbers[i];
        }
        
        return smallest;
        
        
    }
    
}

void Actor:: generate_an_array_with_monster_indicated(char a[][70])
{
    for (int i1=0; i1<18; i1++)
    {
        for (int i2=0; i2<70; i2++)
        {
            if (m_pit->return_pointer_to_actor_on_position(i1, i2)!=nullptr)
                a[i1][i2] = '#';
            else if (m_pit->return_char_on_certain_position(i1, i2)==' ')
                a[i1][i2] = '.';
            else
                a[i1][i2] = m_pit->return_char_on_certain_position(i1, i2);
        }
    }
}

void Actor:: smart_move (int s_r, int s_c, int e_r, int e_c, char a [][70])
{
    int step_needed = step_needed_for_smart_move(s_r, s_c, e_r, e_c, a, 0);
    cout<<step_needed<<"here here!!!!";
    
    if (step_needed<=15)
        {
            if (step_needed>step_needed_for_smart_move(s_r+1, s_c, e_r, e_c, a, 0)&&move(ARROW_DOWN));
            else if (step_needed>step_needed_for_smart_move(s_r-1, s_c, e_r, e_c, a, 0)&&move(ARROW_UP));
            else if (step_needed>step_needed_for_smart_move(s_r, s_c+1, e_r, e_c, a, 0)&&move(ARROW_RIGHT));
            else if (step_needed>step_needed_for_smart_move(s_r, s_c-1, e_r, e_c, a, 0)&&move(ARROW_LEFT));

        }
}


