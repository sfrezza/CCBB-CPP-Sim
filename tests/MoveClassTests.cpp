
//  MoveClassTests.cpp
//  CCBB-CPP-X
//
//  Document by Steve Frezza on 3/26/23.
//  Tests by Gian Asci, Kaden Mescher, and Carmen Alexander

#include "Board.hpp"
#include "Player.hpp"
#include "Route.hpp"
#include "Space.hpp"
#include "BlackSpace.hpp"
#include "CircularRoute.hpp"
#include "LinearRoute.hpp"


#include <gtest/gtest.h>

namespace my {
    namespace project {
        namespace {

            // The fixture for testing class Foo.
            class MoveClassTests : public ::testing::Test {
            protected:
                // You can remove any or all of the following functions if their bodies would
                // be empty.
                std::string testColor;
                Route* someRoute;
                Space* someSpace;
                Board* b;
                Player* p;
                //Player* red = b->route1->path[0];
                MoveClassTests() {
                    // You can do set-up work for each test here.
                    testColor = "Green";
                    someRoute = new LinearRoute(5);
                    someSpace = someRoute->startSpace;
                    b = new Board();
                }
                ~MoveClassTests() override {}

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
            // Fair weather test. Sees if what happens when the dice is rolled.
            TEST_F(MoveClassTests, CorrectDieRole) {
                int dieRoll = 1 + (rand() % 6);
                EXPECT_EQ(p->currentSpace, someSpace);
            }
            
            
            // Tests that the Player::Player() method does what it should.
            TEST_F(MoveClassTests, ConstructorWorks) {
                p = new Player(testColor, someSpace);
                EXPECT_EQ(p->currentSpace, someSpace);
                EXPECT_EQ(p->myColor.compare(testColor), 0);

            }
            TEST_F(MoveClassTests, FairWeather)
            {
                p = b->players[3];
                srand(time(0));
                int noSpaces = 2;
                EXPECT_EQ(p->currentSpace, b->route1->startSpace);            
                EXPECT_EQ(p->myColor, "Yellow");                                 
                EXPECT_EQ(b->route1->startSpace->currentPlayers.count(p), 1); 
                EXPECT_EQ(p->currentSpace->currentPlayers.count(p), 1);       

               
                Route* currentRoute = p->currentSpace->myRoute;
                Space* endSpace = currentRoute->movePlayer(p, noSpaces);

                EXPECT_EQ(endSpace, currentRoute->path[noSpaces - 1]);
                EXPECT_EQ(endSpace, p->currentSpace);
            }
            //Test_F(MoveClassTests, Allpiecesmove) {
              //  Player* red = b->route1->path[0];
                //Player* blue = b->route1->path[0];
                //Player* green = b->route1->path[0];
                //Player* yellow = b->route1->path[0];

            //}

        }  // namespace
    }  // namespace project
}  // namespace my
