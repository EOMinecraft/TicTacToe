#include "menu.h"
#include <iostream>

Menu::Menu() {
    currentMenu = MENU;
    firstLaunch = true;
}

Menu::~Menu() {
    delete game;
}

void Menu::displaySplash() {
    std::cout << "Tic-Tac-Toe\n";
    std::cout << "---------------\n";
    std::cout << "Press H for help\n";
}

void Menu::displayMenu() {
    // display title
    std::cout << "TIC-TAC-TOE\n";
    std::cout << "---------------\n";

    // get console object so we can change the colors
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // default color
    SetConsoleTextAttribute(hConsole, 7);
    for(int i = 0; i < 3; i++) {
        // default color
        SetConsoleTextAttribute(hConsole, 7);

        // if i == our currentMenuSelection
        if(i == currentMenuSelection) {
            // changes the background color
            SetConsoleTextAttribute(hConsole, 16);
        }
        //displays object from array menuOptions
        std::cout << menuOptions[i] << "\n";
    }
    // this prevents the colors from breaking
    SetConsoleTextAttribute(hConsole, 7);
}

void Menu::displayBoard() {

    // get console output object
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // set the console color
    //SetConsoleTextAttribute(hConsole, 7);
    std::cout << "-------------------------------------------------\n";
    for(int i = 0; i < 3; i++) {
        std::cout << "|";
        SetConsoleTextAttribute(hConsole, 7);
        for(int p = 0; p < 3; p++) {
            // if current selected row and column are selected
            if(i == currentSelectedRow && p == currentSelectedCol) {
                // highlight blue
                SetConsoleTextAttribute(hConsole, 16);
            }
            // print cell information
            std::cout << "\t" << game->board_[i][p]->getValue() << "\t";
            // set color back
            SetConsoleTextAttribute(hConsole, 7);
            std::cout << "|";
        }
        //SetConsoleTextAttribute(hConsole, 7);
        std::cout << "\n-------------------------------------------------\n";
    }
    if(game->getInvalidMessage()) {
        std::cout << "\n\nInvalid Space\n";
    }

}

void Menu::displayWinner() {
    // if game is not live_
    if(!game->live_) {
        // if winner_ is == to enum TIE
        if(game->winner_ == game->WINSTATUS::TIE) {
            // display results
            std::cout << "\nGame was a draw\n";
        }
            // if winner_ in the game object is enum X
        else if(game->winner_ == game->WINSTATUS::X) {
            // display results
            std::cout << "\nPlayer One Wins\n";
        }
            // if winner_ in the game object is enum O
        else if(game->winner_ == game->WINSTATUS::O) {
            // display results
            std::cout << "\nPlayer Two Wins\n";
        }
    }
}

void Menu::displayAgain() {
    // display board_
    displayBoard();
    // display winner_
    displayWinner();

    // get console output object
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // set the console color
    //SetConsoleTextAttribute(hConsole, 7);

    // prompt user to play again
    std::cout << "\n\nDo you want to play again?\n";
    for (int i = 0; i < 2; i++) {
        // set default color
        SetConsoleTextAttribute(hConsole, 7);
        // if current iterator == menu selection
        if(i == currentMenuSelection) {
            // set background color to blue
            SetConsoleTextAttribute(hConsole, 16);
        }
        // display from array
        std::cout << againOptions[i] << "\n";
    }
    // this prevents the colors from breaking
    SetConsoleTextAttribute(hConsole, 7);
}

void Menu::displayHelp() {
    std::cout << "Tic Tac Toe\n";
    std::cout << "------------------------------------\n";
    std::cout << "Player One is: " << game->playerOne_->getSymbol() << "\n";
    std::cout << "Player Two is: " << game->playerTwo_->getSymbol() << "\n";
    std::cout << "------------------------------------\n";
    std::cout << "Use the arrow keys to select a square\n";
    std::cout << "Press Enter to select a square\n";
    std::cout << "Press Escape to quit\n";
    std::cout << "Press any key to continue...\n";
}

void Menu::redraw() {
    // clear screen
    system("CLS");
    // display menu
    switch(currentMenu) {
        case MENU:
            // display menu screen
            displayMenu();
            break;
        case BOARD:
            // display board_ screen
            displayBoard();
            break;
        case AGAIN:
            // display the again screen
            displayAgain();
            break;
    }
}

void Menu::restart() {
    // deletes our game object so it can be recreated if a new game is started
    delete game;
}

void Menu::splashMenu(DWORD &mode, INPUT_RECORD &event, HANDLE &hstdin) {
    // clear the screen
    system("CLS");
    // display splash screen
    displaySplash();

    // loop until stopped
    while (true) {
        DWORD count;
        // wait for input
        if (WaitForSingleObject(hstdin, 0) == WAIT_OBJECT_0) {
            // get console input
            ReadConsoleInput(hstdin, &event, 1, &count);
            // on keydown
            if ((event.EventType == KEY_EVENT) && event.Event.KeyEvent.bKeyDown) {
                // if escape is pressed exit the program
                if(event.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
                    exit(0);
                }
                // set first launch to false
                // this screen won't be seen again unless the program is restarted
                firstLaunch = false;
                // fadeaway clearscreen
                system("CLS");
                break;
            }
        }
    }
    // redraw the previous menu
}

void Menu::mainMenu(DWORD &mode, INPUT_RECORD &event, HANDLE &hstdin) {
    // reset currentMenuSelection to 0
    currentMenuSelection = 0;
    // display menu
    displayMenu();

    // loop until currentMenu changes
    while (currentMenu == MENU) {
        // count object
        DWORD count;

        // wait for console
        if (WaitForSingleObject(hstdin, 0) == WAIT_OBJECT_0) {
            // get console input
            ReadConsoleInput(hstdin, &event, 1, &count);
            // on keydown
            if ((event.EventType == KEY_EVENT) && event.Event.KeyEvent.bKeyDown) {
                switch (event.Event.KeyEvent.wVirtualKeyCode) {
                    // escape key
                    case VK_ESCAPE:
                        // exit the program
                        exit(0);
                        // up key
                    case VK_UP:
                        // if currentMenuSelection is greater than zero
                        if (currentMenuSelection > 0) {
                            // subtract 1
                            currentMenuSelection--;
                            // redraw
                            redraw();
                        }
                        break;
                        // down arrow key
                    case VK_DOWN:
                        // if currentMenuSlection less than 2
                        if (currentMenuSelection < 2) {
                            // add 1
                            currentMenuSelection++;
                            // redraw
                            redraw();
                        }
                        break;
                        // enter key
                    case VK_RETURN:
                        // if currentMenuSelection == 2
                        if (currentMenuSelection == 2) {
                            // exit
                            exit(0);
                        }
                        // create new game with amount of players + 1;
                        game = new TicTacToe(currentMenuSelection + 1);
                        // change the current menu
                        currentMenu = BOARD;
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

void Menu::helpMenu(DWORD &mode, INPUT_RECORD &event, HANDLE &hstdin) {
    // clear screen
    system("CLS");
    // display help menu
    displayHelp();
    while(true) {
        DWORD count;
        // wait for input
        if (WaitForSingleObject(hstdin, 0) == WAIT_OBJECT_0) {
            // get console input
            ReadConsoleInput(hstdin, &event, 1, &count);
            // on keydown
            if ((event.EventType == KEY_EVENT) && event.Event.KeyEvent.bKeyDown) {
                // if escape is pressed exit the program
                if (event.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
                    exit(0);
                }
                break;
            }
        }
    }
    // redraw the previous menu
    redraw();
}

void Menu::gameBoard(DWORD &mode, INPUT_RECORD &event, HANDLE &hstdin) {
    // clear screen
    system("CLS");
    // display board_
    displayBoard();

    // if live_ from game object is live_ and currentMenu is enum BOARD
    while (game->live_ && currentMenu == BOARD) {

        if(game->numberOfPlayers_ == 1 && game->playerTwo_->getTurn()) {
            game->playerTwo_->turn(NULL, game);

            redraw();
        }

        DWORD count;
        // wait for input
        if (WaitForSingleObject(hstdin, 0) == WAIT_OBJECT_0) {
            // get console input
            ReadConsoleInput(hstdin, &event, 1, &count);
            // on keydown
            if ((event.EventType == KEY_EVENT) && event.Event.KeyEvent.bKeyDown) {
                switch (event.Event.KeyEvent.wVirtualKeyCode) {
                    case VK_ESCAPE: // escape key
                        exit(0);
                        break;
                    case VK_UP: // up
                        if (currentSelectedRow > 0) {
                            currentSelectedRow--;
                            game->setInvalidMessage(false);
                            redraw();
                        }
                        break;
                    case VK_DOWN: // down
                        if (currentSelectedRow < 2) {
                            currentSelectedRow++;
                            game->setInvalidMessage(false);
                            redraw();
                        }
                        break;
                    case VK_RIGHT: // right
                        if (currentSelectedCol < 2) {
                            currentSelectedCol++;
                            game->setInvalidMessage(false);
                            redraw();
                        }
                        break;
                    case VK_LEFT:
                        if (currentSelectedCol > 0) {
                            currentSelectedCol--;
                            game->setInvalidMessage(false);
                            redraw();
                        }
                        break;
                    case VK_RETURN: {
                        int coordinates[] = {currentSelectedRow, currentSelectedCol};
                        // if it's player ones turn
                        if (game->playerOne_->getTurn()) {
                            // if player ones turn is successful
                            if (game->playerOne_->turn(coordinates, game)) {
                                // if wincheck
                                if(game->winCheck()) {
                                    displayWinner();
                                    currentMenu = AGAIN;
                                    break;
                                }
                                // redraw
                                redraw();
                                // if single player
                                if (game->numberOfPlayers_ == 1) {
                                    // computer turn
                                    game->playerTwo_->turn(coordinates, game);

                                    if(game->winCheck()) {
                                        displayWinner();
                                        currentMenu = AGAIN;
                                        break;
                                    }
                                }
                            }
                        } else if (game->playerTwo_->getTurn() && game->numberOfPlayers_ >= 2) {
                            if(game->playerTwo_->turn(coordinates, game)) {
                                if(game->winCheck()) {
                                    displayWinner();
                                    currentMenu = AGAIN;
                                    break;
                                }
                            }
                        }
                        /*game logic will go here*/
                        redraw();
                        break;
                    }
                    case 0x48:
                        helpMenu(mode, event, hstdin);
                        break;
                    default:
                        break;
                }
            }
        }

    }
}

void Menu::againMenu(DWORD &mode, INPUT_RECORD &event, HANDLE &hstdin) {
    // reset currentMenuSelection to zero
    currentMenuSelection = 0;
    // clear screen
    system("CLS");
    displayAgain();

    while (currentMenu == AGAIN) {

        DWORD count;
        // wait for input
        if (WaitForSingleObject(hstdin, 0) == WAIT_OBJECT_0) {
            // get console input
            ReadConsoleInput(hstdin, &event, 1, &count);
            // on keydown
            if ((event.EventType == KEY_EVENT) && event.Event.KeyEvent.bKeyDown) {
                switch (event.Event.KeyEvent.wVirtualKeyCode) {
                    case VK_ESCAPE:
                        exit(0);
                    case VK_UP:
                        if (currentMenuSelection > 0) {
                            currentMenuSelection--;
                            redraw();
                        }
                        break;
                    case VK_DOWN:
                        if (currentMenuSelection < 1) {
                            currentMenuSelection++;
                            redraw();
                        }
                        break;
                    case VK_RETURN:
                        if (currentMenuSelection == 1) {
                            exit(0);
                        }
                        if (currentMenuSelection == 0) {
                            currentMenu = MENU;
                            restart();
                        }

                        break;
                    default:
                        break;
                }
            }
        }
    }
}

void Menu::start() {
    system("CLS");
    // initialize variables to contain console inputs
    DWORD mode;
    INPUT_RECORD event;
    HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hstdin, &mode);
    SetConsoleMode(hstdin, 0);

    // display title screen if it's the programs first time running
    if(firstLaunch) {
        splashMenu(mode, event, hstdin);
    }

    // logic for the main menu
    mainMenu(mode, event, hstdin);
    // logic for the game board_
    gameBoard(mode, event, hstdin);
    // logic for prompting the user to play again
    againMenu(mode, event, hstdin);

    /*
     * Restarts the game
     * This will trigger until the user quits the game
     */
    start();
}