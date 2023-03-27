//
//  MoveClassTests.cpp
//  CCBB-CPP-X
//
//  Document by Steve Frezza on 3/26/23.
//  Tests by Gian Asci, Kaden Mescher, and Carmen Alexander

#include "Space.hpp"
#include "Player.hpp"
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
                ~
                MoveClassTests() {
                    // You can do set-up work for each test here.
                    testColor = "Green";
                    someRoute = new LinearRoute(5);
                    someSpace = someRoute->startSpace;
                }

                ~MoveClassTests() override {}
                void SetUp() override {}
                void TearDown() override {}

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
                Player* p = new Player(testColor, someSpace);
                EXPECT_EQ(p->currentSpace, someSpace);
                EXPECT_EQ(p->myColor.compare(testColor), 0);
            }

        }  // namespace
    }  // namespace project
}  // namespace my
