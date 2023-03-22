#include "Board.hpp"
#include "Player.hpp"
#include "Route.hpp"
#include "Space.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <gtest/gtest.h>

namespace my
{
    namespace project
    {
        namespace
        {

            class MoveClassTest : public ::testing::Test
            {

            protected:
                Board *b;
                Player *p;

                MoveClassTest()
                {
                    b = new Board();
                }

                ~MoveClassTest() override {}
                void SetUp() override {}
                void TearDown() override {}
            };

            /*——————————————————————*\
             *  Fair Weather Tests  *
            \*——————————————————————*/

            TEST_F(MoveClassTest, FairWeather_1)
            {

                // Setup //
                p = b->players[0]; // "Red"

                // Setting up noSpaces as a random number between 1 and 6, inclusive.
                srand(time(0));
                int noSpaces = rand() % 6 + 1;

                // Pre-condition Tests //
                EXPECT_EQ(p->currentSpace, b->route1->startSpace);            // Test: p is initialized on correct space
                EXPECT_EQ(p->myColor, "Red");                                 // Test: p has a valid color, "Red"
                EXPECT_EQ(b->route1->startSpace->currentPlayers.count(p), 1); // Test: currentPlayers has p
                EXPECT_EQ(p->currentSpace->currentPlayers.count(p), 1);       // Test: currentPlayers has p

                // Inputs //
                Route *currentRoute = p->currentSpace->myRoute;
                currentRoute->movePlayer(p, noSpaces);

                // *** Segmentation fault on movePlayer() *** //
                Space *endSpace = currentRoute->movePlayer(p, noSpaces);

                EXPECT_EQ(endSpace, currentRoute->path[noSpaces - 1]);
                EXPECT_EQ(endSpace, p->currentSpace);
            }

            TEST_F(MoveClassTest, FairWeather_2)
            {

                // Setup //
                p = b->players[0]; // "Red"

                // Setting up noSpaces as a random number between 1 and 6, inclusive.
                srand(time(0));
                int noSpaces = rand() % 6 + 1;

                // Pre-condition Tests //
                EXPECT_EQ(p->currentSpace, b->route1->startSpace);            // Test: p is initialized on correct space
                EXPECT_EQ(p->myColor, "Red");                                 // Test: p has a valid color, "Red"
                EXPECT_EQ(b->route1->startSpace->currentPlayers.count(p), 1); // Test: currentPlayers has p
                EXPECT_EQ(p->currentSpace->currentPlayers.count(p), 1);       // Test: currentPlayers has p

                // Inputs //
                Route *currentRoute = p->currentSpace->myRoute;
                currentRoute->movePlayer(p, noSpaces);
                Space *endSpace = currentRoute->movePlayer(p, noSpaces);

                // Testing that the current space has gained a player //
                EXPECT_EQ(p->currentSpace->currentPlayers.count(p), 1);
                // Testing that the player is removed from the previous space //
                EXPECT_EQ(b->route1->startSpace->currentPlayers.count(p), 0);
            }

            /*————————————————————————*\
             *  Stormy Weather Tests  *
            \*————————————————————————*/

            TEST_F(MoveClassTest, StormyWeather_1)
            {

                // Setup //
                p = b->players[0]; // "Red"

                // noSpaces is greater than 6 in this case; we expect the move to be invalid.
                srand(time(0));
                int noSpaces = 10;

                // We assume all preconditions are true, so no pre-condition tests are needed.

                // Inputs //
                Route *currentRoute = p->currentSpace->myRoute;
                Space *endSpace = currentRoute->movePlayer(p, noSpaces);

                // Expected Outputs //
                EXPECT_EQ(endSpace, p->currentSpace);

                // We expect an error to be thrown, so we don't run any further tests.
            }

        } // namespace
    }     // namespace project
} // namespace my
