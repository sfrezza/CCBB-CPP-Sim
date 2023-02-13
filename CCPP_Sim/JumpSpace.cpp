//
//  JumpSpace.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#include "JumpSpace.hpp"

JumpSpace::JumpSpace(Route *jumpTarget, Route *owningRoute):Space("Jump") {
        jumpTo = jumpTarget->startSpace;
        myRoute = owningRoute;
}
    
Space JumpSpace::endMovementOn(Player player){
    Space newEndSpace = jumpTo.endMovementOn(player);
    return newEndSpace;
}
    
