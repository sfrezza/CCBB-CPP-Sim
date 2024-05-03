//
//  LinearRoute.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#include "LinearRoute.hpp"
#include "Route.hpp"
#include "Space.hpp"

#include <iostream>

LinearRoute::LinearRoute(int length) : Route() {
    endSpace = new Space("End");
    for (int index=0; index<length; index++) {
        Space *newSpace = new Space("Purple");
        newSpace->myRoute = this;
        path.push_back(newSpace);
    }
    endSpace->myRoute = this;
}

Space* LinearRoute::movePlayer(Player *player, int noSpaces) {
    SpaceTuple spaceTuple = Route::startPlayerMove(player, 0); // C++ism: Not sure why the cast is required...
    int newIndex = spaceTuple.index + noSpaces;
    // std::cout << "(" <<newIndex << ").";
    Space *movementEndSpace = spaceTuple.space;
        
    if (newIndex > path.size()) { // Handle the 'no movement' part of linear movement
        newIndex = spaceTuple.index; // No movement
        if (newIndex == -1) { // true if player is on start space;
            movementEndSpace = startSpace->endMovementOn(player);
        }
        else { // normal case
            movementEndSpace = path[newIndex]->endMovementOn(player);
        }
    }
 
    if (newIndex < path.size()) { // Normal Move
        movementEndSpace = path[newIndex]->endMovementOn(player);
    }
    else if (newIndex == path.size()) { // someone just finished!
        movementEndSpace = endSpace->endMovementOn(player);
    }
    return movementEndSpace;
}

