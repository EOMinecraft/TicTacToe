#ifndef GAME_COMPUTER_H
#define GAME_COMPUTER_H

#include "player.h"

class Computer : public Player {
public:
    explicit Computer(char);
    bool turn(int[], TicTacToe*) override;
    int randomNumber(TicTacToe*);
    bool playerCanWin(char, int&, int&, TicTacToe*);

};


#endif //GAME_COMPUTER_H
