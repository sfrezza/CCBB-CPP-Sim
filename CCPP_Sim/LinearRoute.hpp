//
//  LinearRoute.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef LinearRoute_hpp
#define LinearRoute_hpp

#include "Route.hpp"

class LinearRoute : public Route {
public:
    Space endSpace = Space(color:"End");
    
    LinearRoute(int length):Route(length) {
        for (int index=0; index<length; index++) {
            Space newSpace = Space("Purple");
            newSpace.myRoute = this;
            path.push_back(&newSpace);
        }
        endSpace.myRoute = this;
    }
    Space movePlayer(Player player, int noSpaces); // override
};
#endif /* LinearRoute_hpp */
