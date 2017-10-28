#include "ticTacToeCell.h"

TicTacToeCell::TicTacToeCell() {
    active_ = true;
    value_ = ' ';
}

bool TicTacToeCell::setValue(char val) {
    if(active_) {
        value_ = val;
        active_ = false;
        return true;
    }
    return false;
}

char TicTacToeCell::getValue() {
    return value_;
}

bool TicTacToeCell::getActive() {
    return active_;
}

bool TicTacToeCell::compare(TicTacToeCell cell) {
    if (value_ == cell.getValue()) {
        return !getActive();
    } else {
        return false;
    }
}