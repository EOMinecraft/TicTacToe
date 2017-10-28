#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

class TicTacToe;

class Player {
protected:
    char symbol_;
    bool turn_;
public:
    void toggleTurn();
    void setTurn(bool);
    bool getTurn();
    char getSymbol();
    virtual bool turn(int[], TicTacToe*) { return false; };
};


#endif //GAME_PLAYER_H
