//
//  BlackSpace.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//
#include "Player.hpp"
#include "BlackSpace.hpp"
#include "Space.hpp"
#include "MagicButton.hpp"

Space* BlackSpace::endMovementOn(Player *player) {
    CircularRoute *myCircRoute = (CircularRoute *)myRoute;  // Not sure why this is necessary...
    std::string buttonColor = myCircRoute->myMagicButton.buttonColor;
    
    if (player->myColor == buttonColor) {  // Advance to the next route
        return myCircRoute->nextRoute->startSpace->endMovementOn(player);
    }
    else { // Change the Magic Button to the car color
        myCircRoute->myMagicButton->buttonColor = player->myColor;
        Space* super = (Space*) this; // force call to parent function
        return super->endMovementOn(player);
    }
}
