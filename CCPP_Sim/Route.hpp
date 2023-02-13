//
//  Route.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef Route_hpp
#define Route_hpp

#include <vector>
#include "Space.hpp"

class Route {
public:
    Space startSpace = Space("Start");
    std::vector<Space*> path = {};

public:
    Route(int length) {
        for (int index =0; index < (length - 1); index++) {
            Space newSpace = Space(std::string("Black"));
            newSpace.myRoute = this;
            path.push_back(&newSpace);
        }
        startSpace.myRoute = this;
    }
    
    SpaceTuple getCurrentSpace(Player player);
    virtual Space movePlayer (Player player, int noSpaces);
    
    SpaceTuple startPlayerMove(Player player, int noSpaces);
};

#endif /* Route_hpp */
