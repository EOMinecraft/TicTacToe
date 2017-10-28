#ifndef GAME_TICTACTOECELL_H
#define GAME_TICTACTOECELL_H


class TicTacToeCell {
private:
    friend class TicTacToe;
    bool active_;
    char value_;
public:
    TicTacToeCell();
    bool setValue(char);
    char getValue();
    bool compare(TicTacToeCell);
    bool getActive();
};


#endif //GAME_TICTACTOECELL_H
