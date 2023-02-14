//
//  Space.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef Space_hpp
#define Space_hpp

#include <stdio.h>
#include <string>
#include <set>

class Player;
class Route;
struct SpaceTuple {
    Space *space;
    int index;
    
    SpaceTuple(){};
    SpaceTuple(Space *s, int i)
    {
        space = s;
        index = i;
    }
};

class Space {
public:
    std::string myColor;
    std::set<Player*> currentPlayers;
    Route *myRoute;
    
public:
    Space(){myColor = "Unassigned"; currentPlayers = {};}
    Space(std::string color);
    virtual Space* endMovementOn(Player *player);
    void startMovement(Player *player);
};

#endif /* Space_hpp */
