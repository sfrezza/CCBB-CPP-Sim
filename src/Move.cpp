#include "Move.hpp"
#include "Board.hpp"

Move::Move() {
    gameBoard = 0;
    playerColor = std::string("");
    result = std::string("");
    dieRoll = 0;
}
Move::Move(std::string color, int roll) {
    gameBoard = 0;
    result = std::string("");
    playerColor = color;
    dieRoll = roll;
}

void Move::Action() {

}

void Move::SetGame(Board *b) {

}
