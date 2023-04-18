//
//  RoutePropertyTest.cpp
//  CCBB-CPP-X
//
//  Created by Steve Frezza on 3/22/23.
//

#include "Space.hpp"
#include "Player.hpp"
#include "LinearRoute.hpp"
#include "Board.hpp"

#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <rapidcheck.h>

namespace my {
namespace project {

// Tests that the Player::Player() constructor method does what it should.
RC_GTEST_PROP(MyRapidPlayerTest, ConstructorWorksAllColors, ()) {
    LinearRoute *someRoute = new LinearRoute(5);
    Space *someSpace = someRoute->startSpace;
    //const auto testColor = *rc::gen::build(
    //    // List all of the acceptable colors
    //    rc::gen::element("Red","Blue","Green","Yellow"));

    Player *p = new Player("Red", someSpace);
    RC_ASSERT(p->currentSpace == someSpace);
    //RC_ASSERT(p->myColor.compare(testColor) == 0);
}

/*
// Should succeed:
RC_GTEST_PROP(MyTestCase, firstMoves,()) {
// Properties to vary:
   const auto playerNumber = *rc::gen::inRange(0,3);
   const auto dieRoll = *rc::gen::inRange(1,6);

// Test setup:
   Board *b = new Board();
   Player *p;
   RC_ASSERT(p=b->players[playerNumber]->currentSpace == b->route1->startSpace);

   Space *endSpace = b->route1->movePlayer(p,dieRoll); // This should reset the current space, etc.
   std::set<Player*> playersOnEndSpace = endSpace->currentPlayers;
   RC_ASSERT_TRUE(playersOnEndSpace.find(p) != playersOnEndSpace.end() );

   std::set<Player*> playersOnStartSpace = b->route1->startSpace->currentPlayers;
   RC_ASSERT_TRUE(playersOnStartSpace.find(p) == playersOnStartSpace.end() );

   RC_ASSERT_EQ(b->route1->path[dieRoll-1],p->currentSpace);
}
*/


}  // namespace project
}  // namespace my
