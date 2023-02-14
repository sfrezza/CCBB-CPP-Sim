//
//  Board.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#include "Board.hpp"
#include "ColoredSpace.hpp"
#include "Route.hpp"
#include "Space.hpp"

void Board::dieRoll(std::string playerColor, int noSpaces) {
    Player *player = players[ getPlayerIndex(playerColor) ];
    Route *currentRoute = player->currentSpace->myRoute;
    currentRoute->movePlayer(player, noSpaces);
}
    
int Board::getPlayerIndex(std::string color){
    int index = 0;
    for (Player *p : players) {
        if (p->myColor == color) {
            return index;
        }
        index += 1;
    }
    // should really throw an error if index > players.count
    return index;
}
    
Player* Board::getPlayerFromColor(std::string color) {
    int index = getPlayerIndex(color);
    return players[index];
}
    
void Board::initializePlayers() {
    players.push_back(new Player("Red", route1->startSpace));
    players.push_back(new Player("Green", route1->startSpace));
    players.push_back(new Player("Blue", route1->startSpace));
    players.push_back(new Player("Yellow", route1->startSpace)); // This can be randomized later

    Route* super = (Route*)(route1);    // Not clear why needed.
    for (Player *p : players) {
        super->startSpace->endMovementOn(p);
    }
}
    
void Board::initializeLinearRoute(Route *target) {
        // Assumes this is built as a generic 'Route' of the proper length
    target->path[5] = new WheelSpace(route2,target);
    target->path[11] = new WheelSpace(target,target);
    }
    
void Board::initializeCircularRoute2() {
        Route* super = (Route*)(route2);
        super->path[2] = new ColoredSpace("Red", route2);
        super->path[4] = new ColoredSpace("Green", route2);
        super->path[6] = new ColoredSpace("Yellow", route2);
        super->path[8] = new ColoredSpace("Blue", route2);
        super->path[10] = new ColoredSpace("Red", route2);
        super->path[12] = new ColoredSpace("Green", route2);
        super->path[14] = new ColoredSpace("Yellow", route2);
        super->path[16] = new ColoredSpace("Blue", route2);
    }
    
    void Board::initializeCircularRoute1() {
        Route* super = (Route*)(route1);
        super->path[3] = new ColoredSpace("Yellow", (Route*)route1);
        super->path[5] = new ColoredSpace("Green", (Route*)route1);
        super->path[7] = new ColoredSpace("Blue", (Route*)route1);
        super->path[9] = new ColoredSpace("Red", (Route*)route1);
        super->path[11] = new ColoredSpace("Yellow", (Route*)route1);
        super->path[13] = new ColoredSpace("Green", (Route*)route1);
        super->path[15] = new ColoredSpace("Blue", (Route*)route1);
        super->path[17] = new ColoredSpace("Red", (Route*)route1);
        super->path[19] = new ColoredSpace("Yellow", (Route*)route1);
        super->path[21] = new ColoredSpace("Green", (Route*)route1);
        super->path[23] = new ColoredSpace( "Blue", (Route*)route1);
        super->path[25] = new ColoredSpace( "Red", (Route*)route1);
    }

