//
//  PersonTest.cpp
//  CCBB-CPP-X
//
//  Created by Steve Frezza on 2/18/23.
//

#include "PlayerTest.hpp"
#include "Space.hpp"
#include "Player.hpp"
#include "LinearRoute.hpp"
#include "Board.hpp"

#include <gtest/gtest.h>

namespace my {
namespace project {
namespace {

// The fixture for testing class Foo.
class PlayerTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.
    std::string testColor;
    Route *someRoute;
    Space *someSpace;

  PlayerTest() {
     // You can do set-up work for each test here.
      testColor = "Green";
      someRoute = new LinearRoute(5);
      someSpace = someRoute->startSpace;
  }

  ~PlayerTest() override {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

  // Class member functions declared here can be used by all tests in the test suite
  // for Foo.
};

// Tests that the Player::Player() method does what it should.
TEST_F(PlayerTest, ConstructorWorks) {
    Player *p = new Player(testColor,someSpace);
    EXPECT_EQ(p->currentSpace,someSpace);
    EXPECT_EQ(p->myColor.compare(testColor),0);
    EXPECT_STREQ(p->myColor.c_str(),"Green"); // Repeat of previous compare
}
TEST_F(PlayerTest,EndMovementOnWorks) {
   Board *b = new Board();
   Player *p = b->players[1];
   Player *p0 = b->players[0];
   ASSERT_EQ(p->currentSpace, b->route1->startSpace);
   SpaceTuple sTuple = b->route1->startPlayerMove(p); // This should only generate a tuple.
   std::set<Player*> playersOnStartSpace = b->route1->startSpace->currentPlayers;
   ASSERT_TRUE(playersOnStartSpace.find(p0) != playersOnStartSpace.end() );
   ASSERT_TRUE(playersOnStartSpace.find(p) != playersOnStartSpace.end() );
   ASSERT_EQ(sTuple.space, p->currentSpace);

   b->route1->path[3]->endMovementOn(p);
   ASSERT_EQ(b->route1->path[3],p->currentSpace);

}
TEST_F(PlayerTest,MovePlayerWorks) {
   Board *b = new Board();
   Player *p = b->players[1];
   Player *p0 = b->players[0];

   ASSERT_EQ(p->currentSpace, b->route1->startSpace);
   
   Space *endSpace = b->route1->movePlayer(p,3); // This should reset the current space, etc.
   std::set<Player*> playersOnEndSpace = endSpace->currentPlayers;
   ASSERT_TRUE(playersOnEndSpace.find(p0) == playersOnEndSpace.end() );
   ASSERT_TRUE(playersOnEndSpace.find(p) != playersOnEndSpace.end() );

   std::set<Player*> playersOnStartSpace = b->route1->startSpace->currentPlayers;
   ASSERT_TRUE(playersOnStartSpace.find(p0) != playersOnStartSpace.end() );
   ASSERT_TRUE(playersOnStartSpace.find(p) == playersOnStartSpace.end() );

   ASSERT_EQ(b->route1->path[3],p->currentSpace);

}
}  // namespace
}  // namespace project
}  // namespace my
