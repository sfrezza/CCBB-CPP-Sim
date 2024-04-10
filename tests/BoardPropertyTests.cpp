//
//  BoardPropertyTest.cpp
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

#include <iostream>
using namespace std;

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

class RandomizedMoveTestFixture : public testing::Test {
protected:
//    RandomizedMoveTestFixture() {}

    void SetUp() override {
    // SetUp works as usual... Instantiating the elements of the fixture
        myBoard = new Board();
        playerOrder = {"Red", "Green", "Blue", "Yellow"};
        myBoard->initializePlayers(playerOrder);
        EXPECT_EQ(myBoard->route3->path.size(),16);
        EXPECT_EQ(myBoard->route2->path.size(),18);
        EXPECT_EQ(myBoard->route1->path.size(),26);
    }

    Player* advanceOnePlayer() { // randomly play until some player has advanced to a different route.
       // for (std::vector<std::string>::iterator pColor = std::begin(v); pColor != std::end(v); ++i) {}
        
        int dieRoll;
        const int lowRoll = 1;
        const int highRoll = 6;
        Route *currentRoute;
        Space *endSpace;
        bool didAdvance = false;
        bool didWin = false;
        int turnCount = 0;
        
        while (!didAdvance) { // this could loop forever.
            for (auto player : myBoard->players) {
                dieRoll = lowRoll + ( std::rand() % ( highRoll - lowRoll + 1 ) );  // Should generate a random roll between lowRoll and highRoll...
                std::cerr << player->myColor[0] << dieRoll << ".";
                
                currentRoute = player->currentSpace->myRoute;
                endSpace = currentRoute->movePlayer(player,dieRoll); // This should reset the player's position
                didAdvance = (endSpace->myRoute != currentRoute);
                didWin = (endSpace->myColor.compare("End") == 0 );
                
                if (didAdvance || didWin)
                {
                    std::cerr << player->myColor[0] << "(" << turnCount << ")\n";
                    return player;
                }
            }
            turnCount++;
            // Needs another way to stop if players never advance...
            
        }
        return 0; // Very Bad...
    }

    void TearDown() override {
    }

    // Instantiated variables available to all tests using this fixture:
    Board *myBoard;
    std::vector<std::string> playerOrder;
};

RC_GTEST_FIXTURE_PROP(RandomizedMoveTestFixture, advanceASinglePlayer,()) {
    const auto p = *rc::gen::elementOf(myBoard->players);
    CircularRoute *startingRoute = (CircularRoute *)(p->currentSpace->myRoute);
    Player *justAdvanced = advanceOnePlayer();
    std::cerr << justAdvanced->myColor << " advanced";
    
    if (p==justAdvanced) { // If they advanced, then they are correctly on a different route
        RC_ASSERT(startingRoute != justAdvanced->currentSpace->myRoute);
        RC_ASSERT(startingRoute->nextRoute == justAdvanced->currentSpace->myRoute);  // in my dreams of dynamic binding ;)
        std::cerr << ", correctly. \n";
    }
    else {
        RC_ASSERT(startingRoute == p->currentSpace->myRoute);
        std::cerr << " while " << p->myColor << " remained on the route correctly. \n";
    }
}


TEST_F(RandomizedMoveTestFixture, checkFixtureInitialization) {
    ASSERT_EQ(myBoard->players.size(), 4);
}


RC_GTEST_FIXTURE_PROP(RandomizedMoveTestFixture, firstMoves,()) {
// Properties to vary:
    //const auto playerNumber = *rc::gen::inRange(0,3).as("Player index");
    const auto dieRoll = *rc::gen::inRange(1,6).as("Die roll for moves");
    //const auto playerColor = *rc::gen::elementOf(playerOrder).as("Player color being moved");
    
    //const auto smallEven = *gen::suchThat(gen::inRange(0, 100), [](int x) { return (x % 2) == 0; });
        
    const auto p = *rc::gen::elementOf(myBoard->players);
    //Player *p = myBoard->players[playerNumber];
    RC_ASSERT(p->currentSpace == myBoard->route1->startSpace);
    std::set<Player*> playersOnStartSpace = myBoard->route1->startSpace->currentPlayers;
    RC_ASSERT(playersOnStartSpace.find(p) != playersOnStartSpace.end() );
    RC_ASSERT(playersOnStartSpace.count(p) == 1);

    Route *currentRoute = p->currentSpace->myRoute;
    Space *endSpace = currentRoute->movePlayer(p,dieRoll); // This should reset the current space, etc.

    RC_ASSERT(currentRoute->path[dieRoll-1]== p->currentSpace);
    std::set<Player*> playersOnEndSpace = endSpace->currentPlayers;
    RC_ASSERT(playersOnEndSpace.find(p) != playersOnEndSpace.end() );
    RC_ASSERT(playersOnEndSpace.count(p) == 1);

    std::set<Player*> remainingPlayersOnStartSpace = myBoard->route1->startSpace->currentPlayers;
        // RC_ASSERT(remainingPlayersOnStartSpace.count(p) == 0);
}


/* shows RC Failures */
/*
RC_GTEST_FIXTURE_PROP(RandomizedMoveTestFixture, advancePlayerWdieRollFunction,()) {
// Properties to vary:
    const auto dieRoll = *rc::gen::inRange(1,6).as("Die roll for moves");
    const auto playerColor = *rc::gen::elementOf(playerOrder).as("Player color being moved");
        
    const auto p = *rc::gen::elementOf(myBoard->players);
    Route *initialRoute = p->currentSpace->myRoute;

    if (p->myColor.compare(playerColor) == 0) { //RC_PRE() probably more useful
        bool wonGame = myBoard->dieRoll(playerColor,dieRoll); //Randomly move any player
        
        RC_ASSERT(p->currentSpace == myBoard->route1->startSpace); // should fail
        Route *currentRoute = p->currentSpace->myRoute;
        RC_ASSERT(currentRoute != initialRoute); // should eventually fail...
    }
}
*/
