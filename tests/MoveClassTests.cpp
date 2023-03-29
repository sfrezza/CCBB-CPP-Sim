#include "Board.hpp"
#include "Player.hpp"
#include "Route.hpp"
#include "Space.hpp"
#include "BlackSpace.hpp"
#include "CircularRoute.hpp"
#include "LinearRoute.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <gtest/gtest.h>

/*
 
 // Aliases to 'make' (pun intended) this easier. //
 // Just copy and paste into terminal. //
 
 alias cln='echo y | make clean'; alias mke='cmake -B build'; alias bld='cmake --build build'; alias go="cln; mke; bld;"
 
 */

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
                Player *q;
                Route *currentRoute;
                Space *endSpace;

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

            TEST_F(MoveClassTest, CorrectSpaceReturned_Fair)
            {
                /* Description: Tests to ensure that, for a random noSpaces value between 1 and 6,
                                the movePlayer() function returns the correct space that the player
                                is supposed to end on in path[]. It also check that the player's
                                currentSpace is the same as the returned space after the function call.
                */
                
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
                currentRoute = p->currentSpace->myRoute;
                endSpace = currentRoute->movePlayer(p, noSpaces);
                
                // Testing that the returned space matches the expected space in currentRoute's path //
                EXPECT_EQ(endSpace, currentRoute->path[noSpaces - 1]);
                // Testing that the player's currentSpace matches the returnedSpace after the function call //
                EXPECT_EQ(endSpace, p->currentSpace);
            }

            TEST_F(MoveClassTest, CurrentPlayersUpdated_Fair)
            {
                /* Description: Tests to ensure that, for a random noSpaces value between 1 and 6,
                                the movePlayer() function correctly removes the player from the
                                original space's currentPlayers, and adds the player to the new
                                space's currentPlayers.
                */

                // Setup //
                p = b->players[1]; // "Green"

                // Setting up noSpaces as a random number between 1 and 6, inclusive.
                srand(time(0));
                int noSpaces = rand() % 6 + 1;

                // Pre-condition Tests //
                EXPECT_EQ(p->currentSpace, b->route1->startSpace);            // Test: p is initialized on correct space
                EXPECT_EQ(p->myColor, "Green");                               // Test: p has a valid color, "Red"
                EXPECT_EQ(b->route1->startSpace->currentPlayers.count(p), 1); // Test: currentPlayers has p
                EXPECT_EQ(p->currentSpace->currentPlayers.count(p), 1);       // Test: currentPlayers has p

                // Inputs //
                currentRoute = p->currentSpace->myRoute;
                endSpace = currentRoute->movePlayer(p, noSpaces);

                // Testing that the current space has gained a player //
                EXPECT_EQ(p->currentSpace->currentPlayers.count(p), 1);
                // Testing that the player is removed from the previous space //
                EXPECT_EQ(b->route1->startSpace->currentPlayers.count(p), 0);
            }

            /*————————————————————————*\
             *  Stormy Weather Tests  *
            \*————————————————————————*/

            TEST_F(MoveClassTest, NoSpacesBVAOutHigh_Stormy)
            {
                /* Description: Tests values for noSpaces that are greater than 6. The specifications do not
                                indicate how this should be handled, so the behavior is undefined. It's presumed
                                that movePlayer will work as normal.
                 */
                
                // Here we assume all preconditions are true, so no pre-condition tests are needed.
                
                // Setup //
                p = b->players[2]; // "Blue"
                Route *currentRoute;
                Space *endSpace;
                int noSpaces;
                
                // noSpaces is between 7 and 26.
                srand(time(0));
                noSpaces = rand() % 20 + 7;

                // Inputs //
                currentRoute = p->currentSpace->myRoute;
                Space *startingSpace = p->currentSpace;
                endSpace = currentRoute->movePlayer(p, noSpaces);

                // Expected Output //
                EXPECT_EQ(endSpace, p->currentSpace);
                EXPECT_EQ(startingSpace, p->currentSpace); //EXPECT_NE — Should not move
                                                                              // Test case that tests bad results

                // The test may pass but it is not correct. A roll greater than 6 shouldn't be allowed to work.
            }
        
            TEST_F(MoveClassTest, NoSpacesBVAOutLow_Stormy)
            {
                /* Description: Tests values for noSpaces that are less than 1 (0 in this case) The
                                specifications do not indicate how this should be handled, so the behavior
                                is undefined.
                */
            
                // Here we assume all preconditions are true, so no pre-condition tests are needed.
            
                // Setup //
                q = b->players[3]; // "Yellow
                Route *currentRoute;
                Space *endSpace;
                int noSpaces;

                // noSpaces is less than 1 in this case.
                noSpaces = 0;
            
                // Inputs //
                
                currentRoute = q->currentSpace->myRoute;
                Space *startingSpace = q->currentSpace;
                //EXPECT_EQ(currentRoute->startSpace, q->currentSpace); // Testing to ensure player starts on startSpace.
                
                endSpace = currentRoute->movePlayer(q, noSpaces);
            
                // Expected Output //
                EXPECT_EQ(endSpace, q->currentSpace);
                EXPECT_EQ(startingSpace, q->currentSpace);
            }
        
            TEST_F(MoveClassTest, NoSpacesNegative_Stormy)
            {
                /* Description: Tests a negative value for noSpaces. The behavior at this point is
                                undefined, although it would make sense for a segmentation fault or
                                another error to return.
                 */
                
                // Here we assume all preconditions are true, so no pre-condition tests are needed.
                
                // Setup //
                p = b->players[2]; // "Blue"
                Route *currentRoute;
                Space *endSpace;
                int noSpaces;
            
                noSpaces = -1;
                
                // Inputs //
                currentRoute = p->currentSpace->myRoute;
                endSpace = currentRoute->movePlayer(p, noSpaces);

                // Expected Output //
                EXPECT_EQ(endSpace, p->currentSpace);
                // should end on the same space it started on
            }
            
            TEST_F(MoveClassTest, BadPlayer_Stormy)
            {
                /* Description: Tests movePlayer using a new player that is not initialized in the board class.
                                This player is on the route2 startSpace. The player is purposefully not
                                correctly initialized, so that it is not located in currentPlayers. This
                                test should either fail or break.
                 */
                
                // Setup //
                Player *bad = new Player("Purple", b->route2->startSpace);
                Route *currentRoute;
                Space *endSpace;
                int noSpaces;
                
                srand(time(0));
                noSpaces = rand() % 6 + 1;
                
                // Inputs //
                currentRoute = bad->currentSpace->myRoute;
                endSpace = currentRoute->movePlayer(bad, noSpaces);
                
                // Expected Output //
                EXPECT_EQ(endSpace, b->route2->path[noSpaces - 1]);
            }
        
            TEST_F(MoveClassTest, NoSpacesGTCircRoute_Stormy)
            {
                /* Description: The purpose of this test is to evaluate what happens on a circular route when a roll goes over
                                the length of the current route. Tests movePlayer using a short route and a player that are not
                                initialized in the board class. noSpaces is assigned the value of the route's length + 1, so the
                                expected end space would be at path[0].
                 */
                
                // Setup //
                int routeLength = 3;
                int noSpaces = routeLength + 1;
                LinearRoute *testLinear = new LinearRoute(routeLength);
                CircularRoute *testCircular = new CircularRoute(3, testLinear);
                for (int i = 0; i < routeLength; i++)
                {
                    testCircular->path[i] = new BlackSpace(testCircular);
                }
                p = new Player("Red", testCircular->startSpace); //"Red"
                testCircular->startSpace->endMovementOn(p);
                    
                // Inputs
                currentRoute = p->currentSpace->myRoute;
                endSpace = currentRoute->movePlayer(p, noSpaces); // Is supposed to update currentPlayers
                
                EXPECT_EQ(endSpace, testCircular->path[0]);
                EXPECT_EQ(p->currentSpace, testCircular->path[0]);
            }
        } // namespace
    } // namespace project
} // namespace my
