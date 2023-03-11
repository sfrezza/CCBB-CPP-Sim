//
//

#include "Move.hpp"
#include "Board.hpp"
#include <gtest/gtest.h>

namespace {

class MoveClassTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.
    Board *myBoard;
    Move *someMove;

    MoveClassTest() {
     // You can do set-up work for each test here.
      myBoard = new Board();
    }

    ~MoveClassTest() override {
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
};

// Class member functions declared here can be used by all tests in the test suite
// for Foo.

TEST_F(MoveClassTest, PlayerConstructor) {
    std::string playerColor = "Red";
    int dieRoll = 4;

    Move *m = new Move(playerColor,dieRoll);
    
    EXPECT_STREQ(m->playerColor.c_str(), "Red");
    EXPECT_EQ(m->dieRoll, 4);
    //EXPECT_EQ(m->gameBoard, 0);
    EXPECT_STREQ(m->result.c_str(), ""); 
}
}
