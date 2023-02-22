#include <gtest/gtest.h>

#include "Space.hpp"
#include "Player.hpp"
#include "LinearRoute.hpp"
#include "Board.hpp"
class BoardTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.
    std::string testColor;
    LinearRoute *someRoute;
    Space *someSpace;

  BoardTest() {
     // You can do set-up work for each test here.
      testColor = "Green";
      someRoute = new LinearRoute(5);
      someSpace = someRoute->startSpace;
  }

  ~BoardTest() override {
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
TEST_F(BoardTest, ConstructorWorks) {
    Player *p = new Player(testColor,someSpace);
    Board *b = new Board();

    EXPECT_EQ(p->currentSpace,someSpace);
    EXPECT_EQ(p->myColor.compare(testColor),0);
}