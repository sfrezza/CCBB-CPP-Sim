#include <iostream>
#include <gtest/gtest.h>

#include "Board.hpp"

TEST(FakeTest, SFrezzaFakeTesting) {
    EXPECT_STREQ("Red", "Red");
}



int main(int argc, char * argv[]) {
    // insert code here...
    std::cout << "Hello, CCBB World!\n";
    Board *myBoard = new Board();

    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}
