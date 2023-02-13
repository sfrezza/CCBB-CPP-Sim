//
//  Board.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#include "Board.hpp"

void Board::dieRoll(std::string playerColor, int noSpaces) {
    Player player = players[getPlayerIndex(playerColor)];
    Route *currentRoute = player.currentSpace.myRoute;
    currentRoute->movePlayer(player, noSpaces);
}
    
int Board::getPlayerIndex(std::string color){
    int index = 0;
    for (Player p : players) {
        if (p.myColor == color) {
            return index;
        }
        index += 1;
    }
    // should really throw an error if index > players.count
    return index;
}
    
Player Board::getPlayerFromColor(std::string color) {
    int index = getPlayerIndex(color);
    return players[index];
}
    
void Board::initializePlayers() {
    players.push_back(Player("Red", route1->startSpace));
    players.push_back(Player("Green", route1->startSpace));
    players.push_back(Player("Blue", route1->startSpace));
    players.push_back(Player("Yellow", route1->startSpace)); // This can be randomized later
    for (Player p : players) {
        route1.startSpace.endMovementOn(p);
    }
}
    
void Board::initializeLinearRoute(LinearRoute *target) {
        // Assumes this is built as a generic 'Route' of the proper length
    target.path[5] = WheelSpace(route2,target);
    target.path[11] = WheelSpace(target,target);
    }
    
void Board::initializeCircularRoute2() {
        route2->path[2] = ColoredSpace( "Red", route2)
        route2->path[4] = ColoredSpace(color: "Green", route: route2)
        route2->path[6] = ColoredSpace(color: "Yellow", route: route2)
        route2->path[8] = ColoredSpace(color: "Blue", route: route2)
        route2->path[10] = ColoredSpace(color: "Red", route: route2)
        route2->path[12] = ColoredSpace(color: "Green", route: route2)
        route2->path[14] = ColoredSpace(color: "Yellow", route: route2)
        route2->path[16] = ColoredSpace(color: "Blue", route: route2)
    }
    
    fileprivate func initializeCircularRoute1() {
        route1.path[3] = ColoredSpace(color: "Yellow", route: route1)
        route1.path[5] = ColoredSpace(color: "Green", route: route1)
        route1.path[7] = ColoredSpace(color: "Blue", route: route1)
        route1.path[9] = ColoredSpace(color: "Red", route: route1)
        route1.path[11] = ColoredSpace(color: "Yellow", route: route1)
        route1.path[13] = ColoredSpace(color: "Green", route: route1)
        route1.path[15] = ColoredSpace(color: "Blue", route: route1)
        route1.path[17] = ColoredSpace(color: "Red", route: route1)
        route1.path[19] = ColoredSpace(color: "Yellow", route: route1)
        route1.path[21] = ColoredSpace(color: "Green", route: route1)
        route1.path[23] = ColoredSpace(color: "Blue", route: route1)
        route1.path[25] = ColoredSpace(color: "Red", route: route1)
    }
}
