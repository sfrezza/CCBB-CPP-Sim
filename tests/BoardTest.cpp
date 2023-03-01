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
            class BoardTest : public ::testing::Test
            {
            protected:
                // You can remove any or all of the following functions if their bodies would
                // be empty.

                BoardTest()
                {
                    // You can do set-up work for each test here.
                }

                ~BoardTest() override
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
            TEST_F(BoardTest, ConstructorWorks)
            {
                Board *b = new Board();
                // CircularRoute 1
                EXPECT_EQ(b->route1->path[3]->myColor, "Yellow");
                EXPECT_EQ(b->route1->path[5]->myColor, "Green");
                EXPECT_EQ(b->route1->path[7]->myColor, "Blue");
                EXPECT_EQ(b->route1->path[9]->myColor, "Red");
                EXPECT_EQ(b->route1->path[11]->myColor, "Yellow");
                EXPECT_EQ(b->route1->path[13]->myColor, "Green");
                EXPECT_EQ(b->route1->path[15]->myColor, "Blue");
                EXPECT_EQ(b->route1->path[17]->myColor, "Red");
                EXPECT_EQ(b->route1->path[19]->myColor, "Yellow");
                EXPECT_EQ(b->route1->path[21]->myColor, "Green");
                EXPECT_EQ(b->route1->path[23]->myColor, "Blue");
                EXPECT_EQ(b->route1->path[25]->myColor, "Red");
                // CircularRoute 2
                EXPECT_EQ(b->route2->path[2]->myColor, "Red");
                EXPECT_EQ(b->route2->path[4]->myColor, "Green");
                EXPECT_EQ(b->route2->path[6]->myColor, "Yellow");
                EXPECT_EQ(b->route2->path[8]->myColor, "Blue");
                EXPECT_EQ(b->route2->path[10]->myColor, "Red");
                EXPECT_EQ(b->route2->path[12]->myColor, "Green");
                EXPECT_EQ(b->route2->path[14]->myColor, "Yellow");
                EXPECT_EQ(b->route2->path[16]->myColor, "Blue");
                // Players
                EXPECT_EQ(b->players[0]->myColor, "Red");
                EXPECT_EQ(b->players[1]->myColor, "Green");
                EXPECT_EQ(b->players[2]->myColor, "Blue");
                EXPECT_EQ(b->players[3]->myColor, "Yellow");
                EXPECT_EQ(b->players[0]->currentSpace, b->route1->path[3]);
                EXPECT_EQ(b->players[1]->currentSpace, b->route1->path[3]);
                EXPECT_EQ(b->players[2]->currentSpace, b->route1->path[3]);
                EXPECT_EQ(b->players[3]->currentSpace, b->route1->path[3]);
            }

        } // namespace
    }     // namespace project
} // namespace my
