//
//  Board.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef Board_hpp
#define Board_hpp

#include "Player.hpp"
#include "CircularRoute.hpp"
#include "LinearRoute.hpp"
#include "WheelSpace.hpp"

class Board {
public:
    LinearRoute *route3 = new LinearRoute(16);
    CircularRoute *route2 = new CircularRoute(18, &route3);
    CircularRoute *route1 = new CircularRoute(26, &route2);
    std::vector<Player*> players = {};
    
    Board() {
        initializeLinearRoute(route3);
        initializeCircularRoute2();
        initializeCircularRoute1();
        initializePlayers();
    }
    void dieRoll(std::string playerColor, int value);
    
private:
    int getPlayerIndex(std::string color);
    Player* getPlayerFromColor(std::string color);
    void initializeLinearRoute(Route* target);
    void initializeCircularRoute2();
    void initializeCircularRoute1();
    void initializePlayers();
};
    
#endif /* Board_hpp */
