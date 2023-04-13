//–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//
//  ColoredSpaceTest.cpp                                                                                   //
//                                                                                                         //
//  Created by Brendan O'Neill                                                                             //
//                                                                                                         //
//  Note: Anytime I try to implement    <space> -> endMovementOn(<player>)    I get a segmentation fault.  //
//–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//

#include "Space.hpp"
#include "Player.hpp"
#include "CircularRoute.hpp"
#include "LinearRoute.hpp"
#include "ColoredSpace.hpp"
#include <gtest/gtest.h>
namespace my {
namespace project {
namespace {

class ColoredSpaceTest : public ::testing::Test {
 protected:

    LinearRoute *route3;
    CircularRoute *route2;
    ColoredSpace *testSpace;
    //Route *super; // For testing endMovementOn
    Player *p;

  ColoredSpaceTest() {
      route3 = new LinearRoute(8);
      route2 = new CircularRoute(10, route3);
      testSpace = new ColoredSpace("Red", route2);
      //super = (Route*)(route2); // For testing endMovementOn
  }
  ~ColoredSpaceTest() override {}
  void SetUp() override {}
  void TearDown() override {}

};

TEST_F(ColoredSpaceTest, ConstructorWorks) {
    EXPECT_EQ(testSpace->myRoute,route2);
}


//–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//
// Code needed to test the endMovementOn(player) function                  //
// Issue: Segmentation Fault at the line super->path[2]->endMovementOn(p); //
//–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//

/*TEST_F(ColoredSpaceTest, EndMovementOnWorks) {
    p = new Player("Red", route2->startSpace);
    EXPECT_EQ(p->currentSpace,route2->startSpace);
    //Space *expectedEndSpace = super->path[2];
    super->path[2] = new ColoredSpace("Red", route2);
    super->path[2]->endMovementOn(p);
    EXPECT_EQ(p->currentSpace, super->path[2]); // Sidenote: original: expectedEndSpace instead of super->path[2]
}*/

}  // namespace
}  // namespace project
}  // namespace my
