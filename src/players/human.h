#ifndef GAME_HUMAN_H
#define GAME_HUMAN_H

#include "player.h"

class Human : public Player {
public:
    explicit Human(char);
    bool turn(int[], TicTacToe*) override;
};


#endif //GAME_HUMAN_H
