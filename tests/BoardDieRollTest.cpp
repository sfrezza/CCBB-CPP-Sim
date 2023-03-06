//
//  PersonTest.cpp
//  CCBB-CPP-X
//
//  Created by Steve Frezza on 2/18/23.
//

#include "Board.cpp"
#include "Board.hpp"

#include <gtest/gtest.h>

namespace my
{
    namespace project
    {
        namespace
        {

            // The fixture for testing class Foo.
            class BoardDieRollTest : public ::testing::Test
            {
            protected:
                // You can remove any or all of the following functions if their bodies would
                // be empty.

                BoardDieRollTest()
                {
                    // You can do set-up work for each test here.
                }

                ~BoardDieRollTest() override
                {
                    // You can do clean-up work that doesn't throw exceptions here.
                }

                // If the constructor and destructor are not enough for setting up
                // and cleaning up each test, you can define the following methods:

                void SetUp() override
                {
                    // Code here will be called immediately after the constructor (right
                    // before each test).
                }

                void TearDown() override
                {
                    // Code here will be called immediately after each test (right
                    // before the destructor).
                }

                // Class member functions declared here can be used by all tests in the test suite
                // for Foo.
            };

            // Tests that the Player::Player() method does what it should.
            TEST_F(BoardDieRollTest, FunctionWorks)
            {
                Board *b = new Board();
                Player *p = b->players[0];
                b->dieRoll("red", 3);
                EXPECT_EQ(p->currentSpace->myColor, "red");
                EXPECT_EQ(p->currentSpace->myRoute, b->route1->path[3]);
            }

        } // namespace
    }     // namespace project
} // namespace my
