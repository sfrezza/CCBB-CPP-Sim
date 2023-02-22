//
//  PersonTest.cpp
//  CCBB-CPP-X
//
//  Created by Steve Frezza on 2/18/23.
//
#include <iostream>
#include "Space.hpp"
#include "Player.hpp"
#include "Route.hpp"
#include "WheelSpace.hpp"

#include <gtest/gtest.h>

namespace my {
namespace project {
namespace {

// The fixture for testing class Foo.
class WheelSpace_Test : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.
    //std::string testColor;
    Route *someTargetRoute;
    Route *someOwningRoute;
    Player *p;
    Space *someOwningSpace;
    Space *testSpace;

  WheelSpace_Test() {
     // You can do set-up work for each test here.
      //testColor = "Green";
      someTargetRoute = new Route(10);
      someOwningRoute = new Route(5);
      someOwningSpace = someOwningRoute->startSpace;
      Player *p = new Player("Green", someOwningSpace);
      
  }

  ~WheelSpace_Test() override {
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

// Tests that the WheelSpace::WheelSpace() method does what it should.
/*TEST_F(WheelSpace_Test, ConstructorWorks) {
    WheelSpace *wheel1 = new WheelSpace (someTargetRoute,someOwningRoute);
    EXPECT_EQ(wheel1->jumpTo,someTargetRoute->startSpace);
    EXPECT_EQ(wheel1->WheelSpace::my,someOwningspace);
}*/

TEST_F(WheelSpace_Test, EndMovementOnWorks) {
    WheelSpace *wheel2 = new WheelSpace (someTargetRoute,someOwningRoute);
    //EXPECT_EQ(wheel2->endMovementOn(p), wheel2->newEndSpace);
    testSpace = wheel2->endMovementOn(p);
    EXPECT_EQ(testSpace, someTargetRoute->startSpace);
//    EXPECT_EQ(p->myColor.compare(testColor),0);
}

}  // namespace
}  // namespace project
}  // namespace my
