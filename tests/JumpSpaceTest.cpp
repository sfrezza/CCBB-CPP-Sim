//
//  PersonTest.cpp
//  CCBB-CPP-X
//
//  Created by Steve Frezza on 2/18/23.
//

#include "Space.hpp"
#include "Player.hpp"
#include "LinearRoute.hpp"
#include "JumpSpace.hpp"

#include <gtest/gtest.h>

namespace my {
    namespace project {
        namespace {

            // The fixture for testing class Foo.
            class JumpSpaceTest : public ::testing::Test {
            protected:
                // You can remove any or all of the following functions if their bodies would
                // be empty.
                std::string testColor;
                Route* owningRoute;
                Space* Jump;
                Route* jumpTarget;
                

                JumpSpaceTest() {
                    // You can do set-up work for each test here.
                    testColor = "Green Wheel";
                    owningRoute = new LinearRoute(16);
                    
                    
                }

                ~JumpSpaceTest() override {
                    // You can do clean-up work that doesn't throw exceptions here.
                }

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

            // Tests that the Player::Player() method does what it should.
            TEST_F(JumpSpaceTest, ConstructorWorks) {
                Player* p = new Player(testColor, Jump);
                EXPECT_EQ(p->currentSpace, Jump);
                EXPECT_EQ(p->myColor.compare(testColor), 0);
            }

        }  // namespace
    }  // namespace project
}  // namespace my
