//Michael Dimapindan CPSC 120 Section 06

#include <chrono>
#include <ctime>
#include <curses.h>
#include <iostream>
#include <stdlib.h>
#include <thread>
using namespace std;

const int ROWS = 48;
const int COLUMNS = 160;
const string LIVE = "*";
const string DEAD = " ";
bool next_world[ROWS][COLUMNS];

void InitializeCurses() {
  // Initialize curses to control where to output to the terminal. No need to
  // modify this function, but make sure it is called in main at the beginning.
  initscr();
  cbreak();
  noecho();
  clear();
}


void PrintExitInstructions() {
  // Prints instructions near the bottom of the screen for how to exit. No need
  // to modify this function.
  mvaddstr(ROWS + 1, 0, "Press ctrl+c to quit ");
  refresh();
}


void PrintRow(string row_to_print, int row) {
  mvaddstr(row, 0, row_to_print.c_str());
  refresh();

  // Optional: Use the following line to create a short delay between each
  // tick if you want to watch your population grow/shrink more slowly:
  this_thread::sleep_for(chrono::milliseconds(1));
}

void PrintWorld(bool world[ROWS][COLUMNS]) {

  for (int i = 0; i < ROWS; i++) {
    string printed_row = "";
    for (int j = 0; j < COLUMNS; j++) {
      if (world[i][j] == true) {
        printed_row += LIVE;
      }
      else {
        printed_row += DEAD;
      }
    }
    PrintRow(printed_row, i);
  }

}

void setNextCycle(bool world[ROWS][COLUMNS]) {

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      //implementing rules of life
      int aliveCount = 0;
      if (world[i-1][j-1] == true) {
        aliveCount++;
      }
      if (world[i-1][j] == true) {
        aliveCount++;
      }
      if (world[i-1][j+1] == true) {
        aliveCount++;
      }
      if (world[i][j-1] == true) {
        aliveCount++;
      }
      if (world[i][j] == true) {
        aliveCount++;
      }
      if (world[i][j+1] == true) {
        aliveCount++;
      }
      if (world[i+1][j-1] == true) {
        aliveCount++;
      }
      if (world[i+1][j] == true) {
        aliveCount++;
      }
      if (world[i+1][j+1] == true) {
        aliveCount++;
      }
    next_world[i][j] = false;
    //if-statements below checks the rules of Conway's game
      if (world[i][j] == true && aliveCount < 2) {
        next_world[i][j] = false;
      }
      else if (world[i][j] == true && (aliveCount == 2 || aliveCount == 3)) {
        next_world[i][j] = true;
      }
      else if (world[i][j] == true && aliveCount > 3) {
        next_world[i][j] = false;
      }
      else if (world[i][j] == false && aliveCount == 3) {
        next_world[i][j] = true;
      }
    }
  }

}

void getNextCycle(bool world[ROWS][COLUMNS]) {

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      world[i][j] = next_world[i][j];
    }
  }

}

int main(int argc, char* argv[]) {
  InitializeCurses();
  PrintExitInstructions();

  bool conway_game[ROWS][COLUMNS];

  // TODO: Implement Conway's Game of Life.
  while (true) {
    PrintWorld(conway_game);
    setNextCycle(conway_game);
    getNextCycle(conway_game);
  }

  endwin();
  return 0;
}
