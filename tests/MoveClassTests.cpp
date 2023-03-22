#include "Board.hpp"
#include "Player.hpp"
#include <gtest/gtest.h>

namespace my {
namespace project {
namespace {

class MoveClassTest : public ::testing::Test {
    
protected:
    
    Board *b;
    Player *p;
    
    MoveClassTest() {
        b = new Board();
    }
    
    ~MoveClassTest() override {}
    void SetUp() override {}
    void TearDown() override {}
};

/*——————————————————————*\
 *  Fair Weather Tests  *
\*——————————————————————*/

TEST_F(MoveClassTest, FairWeather_1) {
    // Pre-conditions //
    p = b->players[0]; // "Red"
    EXPECT_EQ(p->currentSpace, b->route1->startSpace);
}

/*————————————————————————*\
 *  Stormy Weather Tests  *
\*————————————————————————*/

}  // namespace
}  // namespace project
}  // namespace my

