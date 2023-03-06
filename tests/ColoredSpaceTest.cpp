//–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//
//  ColoredSpaceTest.cpp                                                                                   //
//  Created by Brendan O'Neill                                                                             //
//–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//

#include "Board.hpp"
#include "Space.hpp"
#include "Player.hpp"
#include "CircularRoute.hpp"
#include "LinearRoute.hpp"
#include "ColoredSpace.hpp"
#include "BlackSpace.hpp"
#include <gtest/gtest.h>
#include <iostream>

namespace my {
namespace project {
namespace {

class ColoredSpaceTest : public ::testing::Test {
    
protected:
    
    Board *b;
    Player *p;
    
    ColoredSpaceTest() {
        b = new Board();
        p = b->players[0]; // "Red"
    }
    
    ~ColoredSpaceTest() override {}
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(ColoredSpaceTest, EndMovementOnInitial) {
    // MagicButton is not pointing to a specific color yet; therefore, player does not proceed.
    EXPECT_EQ(p->currentSpace, b->route1->startSpace);
    b->route1->path[3]->endMovementOn(p);
    EXPECT_EQ(b->route1->path[3],p->currentSpace);
}

//
// The following to not work yet because I need to figure out magic button color error (forward declaration)
//   when I try to endMovementOn a black space, etc. to change the magic button color.
//

// Spec: Player moves to next route if they land on a colored space and the magic button color matches the space's color.

Test_F(ColoredSpaceTest, EndMovementOnWrongColor) {
    // * Need a line to change magic button color
    EXPECT_EQ(y->currentSpace, b->route1->startSpace);
    b->route1->path[3]->endMovementOn(y);
    EXPECT_EQ(b->route1->path[3],y->currentSpace);
}

TEST_F(ColoredSpaceTest, EndMovementOnCorrectColor) {
    // * Need a line to change magic button color
    EXPECT_EQ(y->currentSpace, b->route1->startSpace);
    b->route1->path[3]->endMovementOn(y);
    EXPECT_EQ(b->route2->startSpace,y->currentSpace);
}

}  // namespace
}  // namespace project
}  // namespace my




