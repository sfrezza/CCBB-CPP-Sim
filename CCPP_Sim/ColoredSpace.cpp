//
//  ColoredSpace.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#include "ColoredSpace.hpp"

Space *ColoredSpace::endMovementOn(Player *player) {
    CircularRoute *myCircRoute = (CircularRoute*)myRoute;
    std::string myRoutesButtonColor = myCircRoute->myMagicButton.buttonColor;

    if (myColor == myRoutesButtonColor) { // Advance to the next route
        return myCircRoute->nextRoute->startSpace->endMovementOn(player);
    }
    else { // do nothing
        Space* super = (Space*)this; //force call to parent function
        return super->endMovementOn(player);
    }
}
