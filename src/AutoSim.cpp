#include "AutoSim.hpp"
#include <iostream>

std::vector<std::string> AutoSim::randomizeFourPlayerColors(int playerCount) {
    std::vector<std::string> playerColorStrings = {"Red", "Yellow", "Green", "Blue"};
    std::vector<std::string> playerOrderSelected = {};
    int randomValidIndex[playerCount];
    for (int playerNumber = 0; (playerNumber < playerCount); playerNumber++) {
        int randomIndex = ( std::rand() % (playerColorStrings.size() - 1) );
        
        // ensure that the index (0-3) picked is not used already
        bool notUsed = true;
        for (int index = playerNumber-1; (index >= 0); index-- ) {
            if (randomValidIndex[index] == randomIndex)
            {
                notUsed = false;
                break;
            }
        }
        if (notUsed) {
            std::cerr << "Player " << playerNumber << " assigned to color " << playerColorStrings[randomIndex] << ".\n";
            randomValidIndex[playerNumber] = randomIndex;
            playerOrderSelected.push_back(playerColorStrings[randomIndex]);
        }
        else { //try again. Could be more efficient.
            std::cerr << "...Trying " << playerNumber << " again (" << randomIndex << ")\n";
            playerNumber--;
            break;
        }
    }
    return playerOrderSelected;
}

AutoSim::AutoSim(int playerCount)
{
    std::cout << "Called AutoSim( " << playerCount << ")\n";
    // Randomize game initialization with 2-4 players in a random order
    if (playerCount <2) playerCount = 2;
    else if (playerCount >4) playerCount = 4;
    
    myBoard = new Board();
    myBoard->initializePlayers(randomizeFourPlayerColors(playerCount));
    myPlayerSequence = myBoard->players;
}

AutoSim::AutoSim(std::vector<std::string> playerColorOrder)
{
    std::cout << "Called AutoSim( playerColorOrder )\n";
    myBoard = new Board();
    myBoard->initializePlayers(playerColorOrder);
}

std::vector<Player*> AutoSim::getPlayers()
{
	return myPlayerSequence;
}

Board* AutoSim::getBoard()
{
	return myBoard;
}

Player* AutoSim::nextPlayer()
{
    return nullptr;
}
TurnTuple AutoSim::takeTurn()
{
	return TurnTuple(nullptr, 0);
}


