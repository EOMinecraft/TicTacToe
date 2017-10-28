#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "ticTacToe.h"
#include <Windows.h>

class Menu {
private:
    TicTacToe *game;
    enum CURRENTMENU { MENU, BOARD, AGAIN, HELP};
    char menuOptions[3][15] = { "One Player", "Two Player", "Quit" };
    char againOptions[2][4] = { "Yes", "No" };
    int currentMenu;
    bool firstLaunch;
    int currentMenuSelection = 0;
    int currentSelectedCol = 0;
    int currentSelectedRow = 0;
public:
    Menu();
    ~Menu();
    void displaySplash();
    void displayMenu();
    void displayBoard();
    void displayWinner();
    void displayAgain();
    void displayHelp();
    void redraw();
    void restart();
    void splashMenu(DWORD &mode, INPUT_RECORD &event, HANDLE &hstdin);
    void mainMenu(DWORD &mode, INPUT_RECORD &event, HANDLE &hstdin);
    void helpMenu(DWORD &mode, INPUT_RECORD &event, HANDLE &hstdin);
    void gameBoard(DWORD &mode, INPUT_RECORD &event, HANDLE &hstdin);
    void againMenu(DWORD &mode, INPUT_RECORD &event, HANDLE &hstdin);
    void start();
};


#endif //GAME_MENU_H
