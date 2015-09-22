// Game.cpp

#include "Game.h"
#include "utilities.h"
#include <iostream>
#include "Actor.h"
using namespace std;

// Implement these and other Game member functions you may have added.

Game::Game(int goblinSmellDistance)
{
    
}

void Game::play()
{
	string outcome0(""), outcome1(""), outcome2(""), outcome3(""), outcome4(""), out_come_pick_scroll(""), out_come_use_scroll(""); //used to store the outcome of each attack;
    int level = 0;  //indicate which level the pit currently is
    m_pit = new Pit(level);
    //generate random position for player to put
    int plr_r, plr_c;
    m_pit->generate_random_avilable_position(plr_r, plr_c);
    //create player
    m_pit->set_player(new Player(plr_r, plr_c, '@' ,"Player", m_pit));
    Player* original_player = m_pit->return_player();  //record a pointer to the player
    char dush = getCharacter();
    while (dush !='q')//&&m_pit->return_player()->return_Hit_point()>0
    {
		if (dush == '>'&& m_pit->return_pointer_to_object_on_position(original_player->return_row(), original_player->return_col()) != nullptr
			&& m_pit->return_pointer_to_object_on_position(original_player->return_row(), original_player->return_col())->return_name() == '>') //generate a new level
        {
            m_pit = new Pit(++level);
            m_pit->generate_random_avilable_position(plr_r, plr_c);
            original_player->set_row(plr_r);
            original_player->set_col(plr_c);
            original_player->set_pit(m_pit);
            m_pit->set_player(original_player);
        }
        else if (dush == 'g')//picking up staff
        {
            if (m_pit->return_pointer_to_object_on_position(m_pit->return_player()->return_row(), m_pit->return_player()->return_col())!= nullptr)
            {
				if (m_pit->return_pointer_to_object_on_position(m_pit->return_player()->return_row(), m_pit->return_player()->return_col())->return_name() == '&')
				{
					cout << "Congratulations, you won!";
					break;
				}
                out_come_pick_scroll= m_pit->pick_up(m_pit->return_player(),m_pit->return_pointer_to_object_on_position(m_pit->return_player()->return_row(), m_pit->return_player()->return_col()) );
            }
                
        }
        else if (dush=='i')//display inventory
        {
            m_pit->return_player()->display_inventory();
			char temp = getCharacter();
			if (temp == 'q')
				break;

        }
		else if (dush == 'r')//use scrolls
		{
			m_pit->return_player()->display_inventory();
			char temp2 = getCharacter();
			temp2 = temp2 - 97;
			if (temp2 < 0 || temp2>25)
				continue;
			else
				out_come_use_scroll = m_pit->return_player()->use_a_scroll(temp2);
        }
		else if (dush == 'w') //wield weapons
		{
			m_pit->return_player()->display_inventory();
			char temp2 = getCharacter();
			temp2 = temp2 - 97;
			if (temp2 < 0 || temp2>25)
				continue;
			else
				out_come_use_scroll = m_pit->return_player()->wield_a_weapon(temp2);
		}
        else if (dush =='c')
        {
            m_pit->return_player()->set_Hit_points(50);
            m_pit->return_player()->set_stregth_points(9);
        }
        else //player move
        {
           if (! m_pit->return_player()->move(dush))
           {
              outcome0=m_pit->attack(m_pit->return_player(),//attacker
              m_pit->return_pointer_to_actor_on_certain_direction(m_pit->return_player()->return_row(), m_pit->return_player()->return_col(), dush));//defender
           }
             outcome1 = m_pit->attack(m_pit->return_pointer_to_actor_on_position(m_pit->return_player()->return_row()+1, m_pit->return_player()->return_col()), m_pit->return_player());
             outcome2 = m_pit->attack(m_pit->return_pointer_to_actor_on_position(m_pit->return_player()->return_row()-1, m_pit->return_player()->return_col()), m_pit->return_player());
             outcome3 = m_pit->attack(m_pit->return_pointer_to_actor_on_position(m_pit->return_player()->return_row(), m_pit->return_player()->return_col()+1), m_pit->return_player());
             outcome4 = m_pit->attack(m_pit->return_pointer_to_actor_on_position(m_pit->return_player()->return_row(), m_pit->return_player()->return_col()-1), m_pit->return_player());
        }
        
        //monsters move anyways;
        for (int i1 = 0; i1<18; i1++)
        {
            for (int i2=0; i2<70; i2++)
            {
                if (m_pit->return_pointer_to_actor_on_position(i1, i2)!=nullptr)
                {
                    m_pit->return_pointer_to_actor_on_position(i1, i2)->monster_move(i1, i2, original_player->return_row(), original_player->return_col());
                }
            }
        }
        
        //=============raise up HP in 1/10 chance
        if (randInt(10)==5)
        {
            m_pit->return_player()->set_Hit_points(m_pit->return_player()->return_Hit_point()+1);
        }
        
        
        m_pit->display();
        cout<<outcome0<<endl;
        if (outcome1!="") {cout<<outcome1<<endl; outcome1 = "";}
        if (outcome2!="") {cout<<outcome2<<endl;outcome2 = "";}
        if (outcome3!="") {cout<<outcome3<<endl;outcome3 = "";}
        if (outcome4!="") {cout<<outcome4<<endl;outcome4 = "";}
        if (out_come_pick_scroll != "") {cout << out_come_pick_scroll << endl;out_come_pick_scroll="";}
        if (out_come_use_scroll != "") {cout << out_come_use_scroll <<  endl;out_come_use_scroll="";}
        dush = getCharacter();

    }
    cout << "Press q to exit game." << endl;
}

// You will presumably add to this project other .h/.cpp files for the
// various classes of objects you need to play the game:  player, monsters,
// weapons, etc.  You might have a separate .h/.cpp pair for each class
// (e.g., Player.h, Boegeyman.h, etc.), or you might put the class
// declarations for all actors in Actor.h, all game objects in GameObject.h,
// etc.
