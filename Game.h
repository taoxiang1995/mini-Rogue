// Game.h

#ifndef GAME_INCLUDED
#define GAME_INCLUDED
#include "Pit.h"
#include "Player.h"

// You may add data members and other member functions to this class.

class Game
{
public:
    Game(int goblinSmellDistance);
    void play();
    
private:
    Pit* m_pit;
    //Player* m_player;
};

#endif // GAME_INCLUDED
