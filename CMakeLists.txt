cmake_minimum_required(VERSION 3.8)
project(game)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp src/players/player.cpp src/players/player.h src/players/human.cpp src/players/human.h src/players/computer.cpp src/players/computer.h src/ticTacToeCell.cpp src/ticTacToeCell.h src/ticTacToe.cpp src/ticTacToe.h src/bin/remainingNumbers.cpp src/bin/remainingNumbers.h src/menu.cpp src/menu.h)
add_executable(game ${SOURCE_FILES})