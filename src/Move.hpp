#ifndef Move_hpp
#define Move_hpp

#include <string>

class Board;
class Move {
public:
    Board *gameBoard;
    std::string playerColor;
    std::string result;
    int dieRoll;

    Move();
    Move(std::string color, int roll);
    void SetGame(Board *b);
    void Action();
};

#endif /* Move_hpp */