//
//  LinearRoute.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#include "LinearRoute.hpp"

Space LinearRoute::movePlayer(Player player, int noSpaces) {
    Route *parent = (Route*) this;
    SpaceTuple spaceTuple = parent->startPlayerMove(player, 0); // Not sure why the cast is required...
    int newIndex = spaceTuple.index + noSpaces;
    Space movementEndSpace = *spaceTuple.space;
        
    if (newIndex > path.size()) { // Handle the 'no movement' part of linear movement
        newIndex = spaceTuple.index; // No movement
        movementEndSpace = path[newIndex]->endMovementOn(player);
    }
 
    if (newIndex < path.size()) { // Normal Move
        movementEndSpace = path[newIndex]->endMovementOn(player);
    }
    else if (newIndex == path.size()) { // someone just finished!
        movementEndSpace = endSpace.endMovementOn(player);
    }
    return movementEndSpace;
}

