//
//  ColoredSpace.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef ColoredSpace_hpp
#define ColoredSpace_hpp

#include "Space.hpp"
#include "CircularRoute.hpp"

class ColoredSpace : public Space {
public:
    ColoredSpace(std::string color, Route *route) : Space(color) {
        myRoute = route;
    }
    Space *endMovementOn(Player *player) override;
};

#endif /* ColoredSpace_hpp */
