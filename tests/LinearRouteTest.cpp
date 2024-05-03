//
//  CCBB-CPP
//
//  Created by Steve Frezza on 2/18/23.
//

#include "Space.hpp"
#include "Player.hpp"
#include "LinearRoute.hpp"

#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <rapidcheck.h>

#include <iostream>

namespace my {
namespace project {

class LinearRouteTestFixture : public testing::Test {
protected:
    // Instantiated variables available to all tests using this fixture:
    LinearRoute *aRoute;
    int routeLength;
    
    LinearRouteTestFixture() {
        std::cout << "..." ;
        routeLength = 7;
        aRoute = new LinearRoute(routeLength); // build something...
    }
    LinearRouteTestFixture(int pathLength) {
        std::cout << pathLength << "..." ;
        routeLength = pathLength;
        aRoute = new LinearRoute(routeLength); // build something...
    }
    void SetUp() override {
    // SetUp works as usual... Instantiating the elements of the fixture
        std::cout << "**" ;
        EXPECT_EQ(aRoute->path.size(),routeLength);
    }

    void TearDown() override {
        delete aRoute;
        std::cout << "!" ;
    }
};


RC_GTEST_PROP(LinearRouteTest, ConstructorWorks,( )) {
    const auto routeLength = *rc::gen::inRange(1,10).as("Number of spaces on route") ;
    LinearRoute *linRoute = new LinearRoute(int(routeLength));
    
    RC_ASSERT(linRoute->endSpace->myColor.compare("End") == 0);
    for(int index = 0; index < routeLength; index++) {
        RC_ASSERT(linRoute->path.at(index)->myColor.compare("Purple") == 0);
    }
    RC_ASSERT(linRoute->endSpace->myRoute == linRoute);
}

RC_GTEST_PROP(LinearRouteTest, MovePlayerNearEnd, ( )) {
    const auto routeLength = *rc::gen::inRange(6,10).as("Number of spaces on path");
    const auto dieRoll = *rc::gen::inRange(1,15).as("Number of spaces moved");
    const auto playerColor = *rc::gen::element("Red","Blue","Green","Yellow").as("Player Color");
    const auto startMove = *rc::gen::inRange(0,2).as("Initial spaces moved off start space");

    LinearRoute *aRoute = new LinearRoute(int(routeLength));
    
    //Setup
    Player* p = new Player(std::string(playerColor), aRoute->startSpace);
    Space* turnStartSpace = p->currentSpace;
    
    //Preconditions
    // std::cout << p->myColor;
    RC_ASSERT(p->currentSpace == aRoute->startSpace);
    
    int spacesMoved = int(dieRoll);
    int spacesRemainingInRoute = int(routeLength + 1);
    int initialMove = int(startMove);
    Space *endSpace;
    
    if (initialMove > 0) {
        endSpace = aRoute->movePlayer(p, initialMove); // move off the startSpace
        RC_ASSERT(p->currentSpace != turnStartSpace);
        RC_ASSERT(endSpace == aRoute->path[initialMove - 1]);
        turnStartSpace = p->currentSpace;
        // std::cout << " starting on " << initialMove-1 << ".. ";
        spacesRemainingInRoute -= initialMove;
    }
    
    //Contract
    // std::cout << " rolled " << spacesMoved << " (" << spacesRemainingInRoute;
    endSpace = aRoute->movePlayer(p, spacesMoved);
        
    //PostConditions
    if (spacesMoved > spacesRemainingInRoute) { // No movement condition
        RC_ASSERT(p->currentSpace != aRoute->endSpace);
        RC_ASSERT(p->currentSpace == endSpace);
        RC_ASSERT(p->currentSpace == turnStartSpace);
        // std::cout << ") and stalled.\n";
    }
    else if (spacesMoved < spacesRemainingInRoute) { // Should have moved
        RC_ASSERT(p->currentSpace != aRoute->endSpace);
        RC_ASSERT(p->currentSpace != turnStartSpace);
        RC_ASSERT(p->currentSpace == endSpace);
        RC_ASSERT(endSpace == aRoute->path[initialMove + spacesMoved-1]);
        // std::cout << ") and moved.\n";
    }
    else { // Game won - End space
        RC_ASSERT(p->currentSpace == aRoute->endSpace);
        RC_ASSERT(p->currentSpace != turnStartSpace);
        RC_ASSERT(p->currentSpace == endSpace);
        // std::cout << ") and won.\n";
    }
}

/*
RC_GTEST_FIXTURE_PROP(LinearRouteTestFixture, MovePlayer, ( )) {
    const auto dieRoll = *rc::gen::inRange(routeLength+1,routeLength+6).as("Number of spaces moved");
    const auto playerColor = *rc::gen::element("Red","Blue","Green","Yellow").as("Player Color");
//    const auto routeLength = *rc::gen::inRange(1,10).as("Number of spaces on route") ;
//    LinearRoute *aRoute = new LinearRoute(int(routeLength));
    
    //Setup
    Player* p = new Player(std::string(playerColor), aRoute->startSpace);
    Space* turnStartSpace = p->currentSpace;
    
    //Preconditions
    std::cout << p->myColor;
    RC_ASSERT(p->currentSpace == aRoute->startSpace);
    int spacesMoved = int(dieRoll);
    int spacesInRoute = int(routeLength) + 1;
        
    //Contract
    std::cout << " rolled " << spacesMoved << " (" << spacesInRoute;
    Space *endSpace = aRoute->movePlayer(p, spacesMoved);
        
    //PostConditions
    if (spacesMoved > spacesInRoute) { // No movement condition
        RC_ASSERT(p->currentSpace != aRoute->endSpace);
        RC_ASSERT(p->currentSpace == endSpace);
        RC_ASSERT(p->currentSpace == turnStartSpace);
        std::cout << ") and stalled.\n";
    }
    else if (spacesMoved < spacesInRoute) { // Should have moved
        RC_ASSERT(p->currentSpace != aRoute->endSpace);
        RC_ASSERT(p->currentSpace != turnStartSpace);
        RC_ASSERT(p->currentSpace == endSpace);
        RC_ASSERT(endSpace == aRoute->path[spacesMoved-1]);
        std::cout << ") and moved.\n";
    }
    else { // Game won - End space
        RC_ASSERT(p->currentSpace == aRoute->endSpace);
        RC_ASSERT(p->currentSpace != turnStartSpace);
        RC_ASSERT(p->currentSpace == endSpace);
        std::cout << ") and won.\n";
    }
}
*/

}  // namespace project
}  // namespace my
