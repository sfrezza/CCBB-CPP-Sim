//
//  WheelSpace.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef WheelSpace_hpp
#define WheelSpace_hpp

#include "Space.hpp"
class WheelSpace : public Space {
public:
    Space *jumpTo;
    
    WheelSpace(Route *jumpTarget, Route *owningRoute): Space("Jump") {
        jumpTo = jumpTarget->startSpace;
        myRoute = owningRoute;
    }
    Space endMovementOn(Player player) override;
};
#endif /* WheelSpace_hpp */
