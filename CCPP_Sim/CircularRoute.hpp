//
//  CircularRoute.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef CircularRoute_hpp
#define CircularRoute_hpp

#include "Route.hpp"
#include "MagicButton.hpp"
#include "BlackSpace.hpp"

class CircularRoute : public Route {
public:
    Route *nextRoute;
    MagicButton myMagicButton;
    
    CircularRoute(int length, Route *next) : Route(length) {
        nextRoute = next;
        for (int index=0; index < length; index++) {
            BlackSpace newBlackSpace = BlackSpace(this);
            path.push_back(&newBlackSpace);
        }
    }
    Space* movePlayer(Player *player, int noSpaces) override; 
};
#endif /* CircularRoute_hpp */
