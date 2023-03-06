//–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//
//  BlackSpaceTest.cpp                                                                                     //
//  Created by Brendan O'Neill                                                                             //
//–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––//

#include "Space.hpp"
#include "Player.hpp"
#include "CircularRoute.hpp"
#include "LinearRoute.hpp"
#include "BlackSpace.hpp"
#include "Board.hpp"
#include <gtest/gtest.h>

namespace my {
namespace project {
namespace {

class BlackSpaceTest : public ::testing::Test {
 protected:

    Board *b;
    Player *p;

    BlackSpaceTest() {
        b = new Board();
    }
    
    ~BlackSpaceTest() override {}
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(BlackSpaceTest, EndMovementOnInitial) {
    // MagicButton is not pointing to a specific color yet; therefore, player does not proceed.
    p = b->players[3]; // "Yellow"
    EXPECT_EQ(p->currentSpace, b->route1->startSpace);
    b->route1->path[3]->endMovementOn(p);
    EXPECT_EQ(b->route1->path[3],p->currentSpace);
}

//
// The following to not work yet because I need to figure out magic button color error (forward declaration)
//   when I try to endMovementOn a black space, etc. to change the magic button color.
//

// Spec: Player moves to next route if they land on a black space and the magic button color matches the player's color.

TEST_F(BlackSpaceTest, EndMovementOnWrongColor) {
    p = b->players[0]; // "Red"
    EXPECT_EQ(p->currentSpace, b->route1->startSpace);
    // b->dieRoll("Red", 1); // Segmentation fault
    b->route1->path[3]->endMovementOn(p);
    EXPECT_EQ(b->route1->path[3],p->currentSpace); // Bus Error (when using dieRoll prior)
}

TEST_F(BlackSpaceTest, EndMovementOnRightColor) {
    p = b->players[3]; // "Yellow"
    EXPECT_EQ(p->currentSpace, b->route1->startSpace);
    b->dieRoll("Yellow", 1); // Segmentation fault
    b->route1->path[3]->endMovementOn(p);
    EXPECT_EQ(b->route2->startSpace,p->currentSpace); // Bus Error (when using dieRoll prior)
}

}  // namespace
}  // namespace project
}  // namespace my
