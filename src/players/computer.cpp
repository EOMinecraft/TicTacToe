#include <iostream>
#include "computer.h"
#include "../ticTacToe.h"

#include <cstdlib>
#include <ctime>

Computer::Computer(char symb) {
    symbol_ = symb;
    turn_ = false;

    std::srand(time(NULL));

    std::rand();
}

bool Computer::turn(int[], TicTacToe* game) {
// in the event of a winner or game is not live, end the function
    // otherwise the computer will get an extra turn at the end of the game
    if (game->winCheck() || !game->isLive())
        return false;

    // player symbol
    const char playerSymbol = game->playerOne_->getSymbol();

    // declare variables to be passed by refrence
    // variables will change if player can win is true
    int row, col;
    // check if computer can win and end the game
    if (playerCanWin(symbol_, row, col, game)) {
        game->updateBoard(row, col, symbol_);
        return true;
    } // check if player can win and prevent the win
    else if (playerCanWin(playerSymbol, row, col, game)) {
        game->updateBoard(row, col, symbol_);
        return true;
    }

    // go to a random unoccupied square
    while(turn_ && !game->winCheck() && game->isLive()) {
        // get random number
        int index = randomNumber(game);

        // remove from remaining numbers
        row = game->remainingNumbers_.getArr()[index][0];
        col = game->remainingNumbers_.getArr()[index][1];

        // if space is active
        if(game->board_[row][col]->getActive()) {
            game->updateBoard(col, row, symbol_);
            return true;
        }

    }
    return false;
}

int Computer::randomNumber(TicTacToe* game) {
    return (std::rand() % (game->remainingNumbers_.getSize()));
}

bool Computer::playerCanWin(char symbol, int &row, int &col, TicTacToe* game) {
    for (int i = 0; i < 3; i++) {
        // horizontal
        if (game->board_[i][0]->getValue() == symbol && game->board_[i][1]->getValue() == symbol && game->board_[i][2]->getActive()) {
            row = i;
            col = 2;
            return true;
        }
        else if (game->board_[i][0]->getValue() == symbol && game->board_[i][2]->getValue() == symbol && game->board_[i][1]->getActive()) {
            row = i;
            col = 1;
            return true;
        }
        else if (game->board_[i][1]->getValue() == symbol && game->board_[i][2]->getValue() == symbol && game->board_[i][0]->getActive()) {
            row = i;
            col = 0;
            return true;
        }

            // vertical
        else if (game->board_[0][i]->getValue() == symbol && game->board_[1][i]->getValue() == symbol && game->board_[2][i]->getActive()) {
            row = 2;
            col = i;
            return true;
        }
        else if (game->board_[0][i]->getValue() == symbol && game->board_[2][i]->getValue() == symbol && game->board_[1][i]->getActive()) {
            row = 1;
            col = i;
            return true;
        }
        else if (game->board_[1][i]->getValue() == symbol && game->board_[2][i]->getValue() == symbol && game->board_[0][i]->getActive()) {
            row = 0;
            col = i;
            return true;
        }
    }

    // check for diagonal computer win conditions
    if (game->board_[0][0]->getValue() == symbol && game->board_[1][1]->getValue() == symbol && game->board_[2][2]->getActive()) {
        row = 2;
        col = 2;
        return true;
    }
    else if (game->board_[0][0]->getValue() == symbol && game->board_[2][2]->getValue() == symbol && game->board_[1][1]->getActive()) {
        row = 1;
        col = 1;
        return true;
    }
    else if (game->board_[1][1]->getValue() == symbol && game->board_[2][2]->getValue() == symbol && game->board_[0][0]->getActive()) {
        row = 0;
        col = 0;
        return true;
    }
    else if (game->board_[2][0]->getValue() == symbol && game->board_[1][1]->getValue() == symbol && game->board_[0][2]->getActive()) {
        row = 0;
        col = 2;
        return true;
    }
    else if (game->board_[2][0]->getValue() == symbol && game->board_[0][2]->getValue() == symbol && game->board_[1][1]->getActive()) {
        row = 1;
        col = 1;
        return true;
    }
    else if (game->board_[0][2]->getValue() == symbol && game->board_[1][1]->getValue() == symbol && game->board_[2][0]->getActive()) {
        row = 2;
        col = 0;
        return true;
    }
    return false;
}