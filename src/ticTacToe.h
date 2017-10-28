#ifndef GAME_TICTACTOE_H
#define GAME_TICTACTOE_H

#include "ticTacToeCell.h"
#include "bin/remainingNumbers.h"
#include "players/computer.h"
#include "players/human.h"

class TicTacToe {
private:
    friend class Menu;
    friend class Computer;
    TicTacToeCell* board_[3][3];
    RemainingNumbers remainingNumbers_;
    Player* playerOne_;
    Player* playerTwo_;
    int numberOfPlayers_;
    int currentTurn_;
    int turnCount_;
    enum WINSTATUS {X, O, TIE};
    int winner_;
    bool live_;
    bool invalidChoice_;
    void createBoard();
    void deleteBoard();
    void createPlayers(int);
    void deletePlayers();
public:
    explicit TicTacToe(int);
    ~TicTacToe();
    void setInvalidMessage(bool x);
    bool getInvalidMessage();
    bool updateBoard(int, int, char);
    void next();
    void setWinner(char);
    bool winCheck();
    int getWinner();
    bool isLive();
};


#endif //GAME_TICTACTOE_H
