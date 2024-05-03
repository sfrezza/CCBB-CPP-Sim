#pragma once
#include "Player.hpp"
#include <vector>
#include "Board.hpp"
#include <set>

struct TurnTuple {
    Player* player;
    int roll;

    TurnTuple() {};
    TurnTuple(Player* p, int r)
    {
        player = p;
        roll = r;
    }
};

class AutoSim {
private: 
    Board *myBoard;
    std::vector<Player*> myPlayerSequence;
    std::vector<std::string> randomizeFourPlayerColors(int playerCount);
    
public:
	AutoSim(int playerCount);
	AutoSim(std::vector<std::string> playerColorOrder);
    
    std::vector<Player*> getPlayers();
    Board* getBoard();
    
    Player* nextPlayer();
    TurnTuple takeTurn();

};
