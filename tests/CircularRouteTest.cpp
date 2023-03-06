//
//  CircularRouteTest.cpp
//  CCBB-CPP-X
//
//  Created by Steve Frezza on 2/18/23.
//

#include "Board.cpp"
#include "Board.hpp"
#include "Space.hpp"
#include "Player.hpp"
#include "LinearRoute.hpp"
#include "CircularRoute.hpp"
#include "CircularRoute.cpp"

#include <gtest/gtest.h>

namespace my {
namespace project {
namespace {

// The fixture for testing class Foo.
class CircularRouteTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.
    std::string testColor;
    Route *someRoute;
    Space *someSpace;

  CircularRouteTest() {
     // You can do set-up work for each test here.
      someRoute = new LinearRoute(5);
      someSpace = someRoute->startSpace;
  }

  ~CircularRouteTest() override {
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

// Sanity check for the CircularRouteTest::CircularRouteTest() method, so we know that GTesting works.
TEST(CircularRouteTest, SanityCheck) {
    EXPECT_TRUE(true);
}

TEST(CircularRouteTest, CurrentSpace) {
   Space *s = new Space();
   s->Space("blue");
   EXCEPT_EQ(space->"blue")
}
}  // namespace
}  // namespace project
}  // namespace my