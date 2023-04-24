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


/*
// Tests that the Player::Player() constructor method does what it should.
RC_GTEST_PROP(MyRapidPlayerTest, ConstructorWorksAllColors, ()) {
    LinearRoute *someRoute = new LinearRoute(5);
    Space *someSpace = someRoute->startSpace;
//    const auto testColor = *rc::gen::build(
    //    // List all of the acceptable colors
    const auto testColor = *rc::gen::element("Red","Blue","Green","Yellow");

    Player *p = new Player(std::string(testColor), someSpace);
    RC_ASSERT(p->currentSpace == someSpace);
    RC_ASSERT(p->myColor.compare(testColor) == 0);
}
*/


RC_GTEST_PROP(RandomizeMoveTestCase, firstMoves,()) {
// Test setup:
   Board *b = new Board();

// Properties to vary:
   const auto playerNumber = *rc::gen::inRange(0,3).as("Player index");
   const auto dieRoll = *rc::gen::inRange(1,6).as("Die roll for moves");

   Player *p = b->players[playerNumber];;
   RC_ASSERT(p->currentSpace == b->route1->startSpace);

   std::set<Player*> playersOnStartSpace = b->route1->startSpace->currentPlayers;
   RC_ASSERT(playersOnStartSpace.find(p) != playersOnStartSpace.end() );
   RC_ASSERT(playersOnStartSpace.count(p) == 1);

   Space *endSpace = b->route1->movePlayer(p,dieRoll); // This should reset the current space, etc.

   RC_ASSERT(b->route1->path[dieRoll-1]== p->currentSpace);
   std::set<Player*> playersOnEndSpace = endSpace->currentPlayers;
   RC_ASSERT(playersOnEndSpace.find(p) != playersOnEndSpace.end() );
   RC_ASSERT(playersOnEndSpace.count(p) == 1);

   std::set<Player*> remainingPlayersOnStartSpace = b->route1->startSpace->currentPlayers;
   // RC_ASSERT(remainingPlayersOnStartSpace.count(p) == 0);
}



}  // namespace project
}  // namespace my
