//
//  WheelSpace.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#include "WheelSpace.hpp"

Space WheelSpace::endMovementOn(Player player) {
    Space newEndSpace = jumpTo->endMovementOn(player);
    return newEndSpace;
}

