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
    // Board *myBoard;
    // std::vector<Player*> myPlayerSequence;
    
public:
	AutoSim(int);
	AutoSim(std::vector<std::string>);
	std::vector<Player*> getPlayers();
	Board* getBoard();
    TurnTuple takeTurn();
    Player* nextPlayer();
};
