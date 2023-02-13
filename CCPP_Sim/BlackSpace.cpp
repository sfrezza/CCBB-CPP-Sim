//
//  BlackSpace.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#include "BlackSpace.hpp"



Space BlackSpace::endMovementOn(Player player) {
    std::string buttonColor = myRoute.myMagicButton.buttonColor;
    
    if (player.myColor == buttonColor) {  // Advance to the next route
        return myRoute.nextRoute.startSpace.endMovementOn(player);
    }
    else { // Change the Magic Button to the car color
        myRoute.myMagicButton = player.myColor;
        Space* super = (Space*) this; // force call to parent function
        return super->endMovementOn(player);
    }
}
