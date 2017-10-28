#include "human.h"
#include <iostream>
#include "../ticTacToe.h"

Human::Human(char symb) {
    symbol_ = symb;
    turn_ = true;
}

bool Human::turn(int *coord, TicTacToe* game) {
    return game->updateBoard(coord[0], coord[1], symbol_);
}