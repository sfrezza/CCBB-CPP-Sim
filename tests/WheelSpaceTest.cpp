//–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//
//  WheelSpaceTest.cpp                                                                                     //
//                                                                                                         //
//  Created by Brendan O'Neill                                                                             //
//                                                                                                         //
//  Note: Anytime I try to implement    <space> -> endMovementOn(<player>)    I get a segmentation fault.  //
//        The constructor has one private data member, which cannot be tested directly.                    //
//–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//

#include <iostream>
#include "Player.hpp"
#include "LinearRoute.hpp"
#include "CircularRoute.hpp"
#include "WheelSpace.hpp"

#include <gtest/gtest.h>

namespace my {
namespace project {
namespace {

class WheelSpaceTest : public ::testing::Test {
protected:
    
    Route *route3; // Owning route
    Route *route2; // Target route
    Route *super;
    Player *p;

  WheelSpaceTest() {
      route3 = new LinearRoute(10);
      route2 = new CircularRoute(5, route3);
      super = (Route*)(route2);
  }

  ~WheelSpaceTest() override {}
  void SetUp() override {}
  void TearDown() override {}
};


//–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//
// Code needed to test the endMovementOn(player) function                  //
// Issue: Segmentation Fault at the line super->path[2]->endMovementOn(p); //
//–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//

/*TEST_F(WheelSpaceTest, EndMovementOnWorks) {
    p = new Player("Red", route3->startSpace);
    EXPECT_EQ(p->currentSpace,route3->startSpace);
    super->path[2] = new WheelSpace(route2, route3);
    super->path[2]->endMovementOn(p);
    EXPECT_EQ(p->currentSpace, super->path[2]); // Sidenote: original: expectedEndSpace instead of super->path[2]
}*/

}  // namespace
}  // namespace project
}  // namespace my
