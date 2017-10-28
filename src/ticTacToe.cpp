#include "ticTacToe.h"


// constructor
TicTacToe::TicTacToe(int numOfPlayers) {
    // set defaults
    live_ = true;
    turnCount_ = 0;
    invalidChoice_ = false;

    // keep track of number of players
    numberOfPlayers_ = numOfPlayers;

    // create the number of players that are in the game
    createPlayers(numOfPlayers);

    // create tictactoe board
    createBoard();

}

// destructor
TicTacToe::~TicTacToe() {
    // delete stuff
    deleteBoard();
    deletePlayers();
}

void TicTacToe::createPlayers(int numOfPlayers) {

    // playerOne will always be human
    // create it before
    playerOne_ = new Human('x');

    // if one player
    if(numOfPlayers == 1) {
        // create computer player
        playerTwo_ = new Computer('o');
    }
    else {
        // create a second human player
        playerTwo_ = new Human('o');
        // set turn to false
        playerTwo_->setTurn(false);
    }
}

void TicTacToe::deletePlayers() {
    delete playerOne_;
    delete playerTwo_;
}

// create 3x3 board
void TicTacToe::createBoard() {
    for(int i = 0; i < 3; i++) {
        for(int p = 0; p < 3; p++) {
            board_[i][p] = new TicTacToeCell();
        }
    }
}

void TicTacToe::deleteBoard() {
    // delete all pointers in board_
    for (const auto &p : board_) {
        for (const auto &x : p) {
            delete x;
        }
    }
}

bool TicTacToe::updateBoard(int row, int col, char symb) {
    // if set value completes
    if(board_[row][col]->setValue(symb) && live_) {
        // create temp array with row and column
        int temp[] = { row, col };
        // remove item at index temp is contained
        remainingNumbers_.remove(temp);
        // invalid choice is set to false
        invalidChoice_ = false;
        // change turns
        next();
        return true;
    }
    // if failure to update board set invalidchoice to true
    invalidChoice_ = true;
    return false;
}


bool TicTacToe::getInvalidMessage() {
    return invalidChoice_;
}

void TicTacToe::setInvalidMessage(bool x) {
    invalidChoice_ = x;
}

void TicTacToe::next() {
    // add one to turn count
    turnCount_++;
    // toggle turns
    playerOne_->toggleTurn();
    playerTwo_->toggleTurn();
}

void TicTacToe::setWinner(char symb) {
    if(symb == 'x') {
        winner_ = X;
    } else if(symb == 'o') {
        winner_ = O;
    }
}

bool TicTacToe::winCheck() {
    /*
    if(tieCheck()) {
        live_ = false;
        winner_ = TIE;
        return true;
    }
    */
    // horizontal
    for (int i = 0; i < 3; i++) {
        if (board_[i][0]->getValue() == board_[i][1]->getValue() && board_[i][0]->getValue() == board_[i][2]->getValue() && !board_[i][0]->getActive() && !board_[i][1]->getActive() && !board_[i][2]->getActive()) {
            setWinner(board_[i][0]->getValue());
            live_ = false;
            return true;
        }
    }
    // vertical
    for (int i = 0; i < 3; i++) {
        if (board_[0][i]->getValue() == board_[1][i]->getValue() && board_[0][i]->getValue() == board_[2][i]->getValue() && !board_[0][i]->getActive() && !board_[1][i]->getActive() && !board_[2][i]->getActive()) {
            setWinner(board_[0][i]->getValue());
            live_ = false;
            return true;
        }
    }

    // diagonal
    if (board_[0][0]->getValue() == board_[1][1]->getValue() && board_[0][0]->getValue() == board_[2][2]->getValue() && !board_[2][2]->getActive() && !board_[1][1]->getActive() && !board_[0][0]->getActive()) {
        setWinner(board_[0][0]->getValue());
        live_ = false;
        return true;
    }
    if (board_[0][2]->getValue() == board_[1][1]->getValue() && board_[0][2]->getValue() == board_[2][0]->getValue() && !board_[0][2]->getActive() && !board_[1][1]->getActive() && !board_[2][0]->getActive()) {
        setWinner(board_[0][2]->getValue());
        live_ = false;
        return true;
    }

    // if turncount is greater than 9
    if (turnCount_ == 9) {
        winner_ = TIE;
        live_ = false;
        return true;
    }

    return false;
}

int TicTacToe::getWinner() {
    return winner_;
}

bool TicTacToe::isLive() {
    return live_;
}
