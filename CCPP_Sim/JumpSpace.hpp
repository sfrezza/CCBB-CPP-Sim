//
//  JumpSpace.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef JumpSpace_hpp
#define JumpSpace_hpp

#include <stdio.h>
#include "Space.hpp"

class JumpSpace : public Space {
public:
    Space jumpTo;
    JumpSpace():Space("Jump") {}; //force default construction behavior
    JumpSpace(Route *jumpTarget, Route *owningRoute);
    
    Space endMovementOn(Player player) override;
};
#endif /* JumpSpace_hpp */
