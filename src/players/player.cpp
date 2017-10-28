#include "player.h"
#include <iostream>
#include "../ticTacToe.h"

void Player::toggleTurn() {
    turn_ = !turn_;
}

void Player::setTurn(bool turn) {
    turn_ = turn;
}

bool Player::getTurn() {
    return turn_;
}

char Player::getSymbol() {
    return symbol_;
}
