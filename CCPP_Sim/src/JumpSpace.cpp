//
//  JumpSpace.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#include "Player.hpp"
#include "JumpSpace.hpp"
#include "Route.hpp"
#include "Space.hpp"

JumpSpace::JumpSpace() : Space("Jump") {}; //force default construction behavior

JumpSpace::JumpSpace(Route *jumpTarget, Route *owningRoute):Space("Jump") {
        jumpTo = jumpTarget->startSpace;
        myRoute = owningRoute;
}
    
Space *JumpSpace::endMovementOn(Player *player) {
    Space *newEndSpace = jumpTo->endMovementOn(player);
    return newEndSpace;
}
    
