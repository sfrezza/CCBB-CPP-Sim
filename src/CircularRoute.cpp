//
//  CircularRoute.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#include "MagicButton.hpp"
#include "BlackSpace.hpp"
#include "CircularRoute.hpp"
#include "Player.hpp"
    
CircularRoute::CircularRoute(int length, Route *next) : Route() {
    nextRoute = next;
    for (int index=0; index < length; index++) {
        BlackSpace *newBlackSpace = new BlackSpace(this);
        path.push_back(newBlackSpace);
    }
    myMagicButton = new MagicButton();
}

Space* CircularRoute::movePlayer(Player *player, int noSpaces) {
    SpaceTuple spaceTuple = Route::startPlayerMove(player);
    int newIndex = spaceTuple.index + noSpaces;
    if (newIndex >= path.size()) { // Handle the circular part of route movement
        newIndex -= path.size();
    }

    // Should call the 'endMovement' that matches the instance type.
    Space *landOnSpace = path[newIndex];
    Space *endSpace = path[newIndex]->endMovementOn(player);
    return endSpace;
}
