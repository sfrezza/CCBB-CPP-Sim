//
//  Player.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include "Space.hpp"

class Player {
public:
    std::string myColor;
    Space currentSpace;
    
    Player (std::string color, Space start) {
        myColor = color;
        currentSpace = start;
    }
}
#endif /* Player_hpp */
