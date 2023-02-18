//
//  PersonTest.cpp
//  CCBB-CPP-X
//
//  Created by Steve Frezza on 2/18/23.
//

#include "PlayerTest.hpp"
#include "src/Space.hpp"
#include "src/Player.hpp"
#include "src/LinearRoute.hpp"

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
    Player *p;

  PlayerTest() {
     // You can do set-up work for each test here.
      testColor = "Green";
      someRoute = new LinearRoute(5);
      someSpace = someRoute->startSpace;
      p = new Player(testColor,someSpace);
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

// Tests that the Foo::Bar() method does Abc.
TEST_F(PlayerTest, ConstructorWorks) {
    EXPECT_EQ(p->currentSpace,someSpace);
    EXPECT_EQ(p->myColor.compare(testColor),0);
}

}  // namespace
}  // namespace project
}  // namespace my
