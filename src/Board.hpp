//
//  Board.hpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#ifndef Board_hpp
#define Board_hpp

#include <vector>

class Player;
class Route;
class CircularRoute;
class LinearRoute;

class Board {
public:
    LinearRoute *route3;
    CircularRoute *route2;
    CircularRoute *route1;
    std::vector<Player*> players;
    Board();

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
