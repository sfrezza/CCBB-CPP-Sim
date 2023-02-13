//
//  Space.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#include "Space.hpp"
    Space::Space(std::string color)
    {
        myColor = color;
    }
    
    Space* Space::endMovementOn(Player *player) {
        currentPlayers.insert(player);
        player->currentSpace = this;
        return this;
    }
    void startMovement(Player *player) {
        currentPlayers.erase(player);
    }
}
