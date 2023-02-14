//
//  JumpSpace.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef JumpSpace_hpp
#define JumpSpace_hpp

class Route;
#include "Space.hpp"

class JumpSpace : public Space {
private:
    Space *jumpTo;

public:
    JumpSpace();
    JumpSpace(Route *jumpTarget, Route *owningRoute);
    
    Space* endMovementOn(Player *player) override;
};
#endif /* JumpSpace_hpp */
