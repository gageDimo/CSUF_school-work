// Michael Dimapindan CPSC 120 Section 06

#include <iostream>
#include <ctime>

using namespace std;

// TODO: Declare a bunch of constants in ALL_CAPS up here to represent:
// * The number of rows, 3 (which is taken care of for you below).
// * The number of columns, 3 (which is taken care of for you below).
// * An empty spot, using a space character ' '
// * The player's piece, using the character 'x'
// * The computer's piece, using the character 'o'
// * A string signifying the player wins
// * A string signifying the computer wins
// * A string signifying the game is a draw
// * A string signifying the game is not finished yet.
const int ROWS = 3;
const int COLUMNS = 3;

const char BLANK = ' ';
const char PLYR_PIECE = 'x';
const char COMP_PIECE = 'o';

const string WIN = "You Win!";
const string LOSE = "You Lose!";
const string DRAW = "Cat's Game!";
const string NOT_DONE;


// TODO: Create a void function called Print that takes a 2D char array as
// input. The declaraion has been created for you as an example for how to pass
// a statically-allocated 2D array as a parameter to a function.
void Print(char board[ROWS][COLUMNS]) {
  // TODO: Use 2 nested for loops to print the contents of the board in the
  // format:
  //  | |
  // -+-+-
  //  | |
  // -+-+-
  //  | |
  // Remember to use the outer for loop to iterate over the rows, and the inner
  // for loop to iterate over the columns.

    for(int i = 0; i < ROWS; i++) {

      for(int j = 0; j < COLUMNS; j++) {

        cout << board[i][j];
        if (j < 2) {
          cout << "|";
        }

    }

    cout << endl;
    if (i < 2) {
    cout << "-+-+-" << endl;
    }
  }

  // TODO: Use | between each column, but don't put one at the end. HINT: Use
  // an if statement to check which column you're at and whether to print |.

  // TODO: Print a "-+-+-" after each row except the last. HINT: Like the |, use
  // an if statement to check which row you're at and whether to print -+-+-.
}


// TODO: Create a void function called SetPlayerMove that takes a 2D char array
// as input and assigns the player's piece to an available row and column.
// Prompt the user for a valid row and column (0-2 each). If either is
// invalid, e.g. -1 or 3, re-prompt them. If the board already has a piece
// there, re-prompt them.
// Upon entering a valid, unoccupied row and column, set the board to the
// player's piece (defined in your constants above).

void SetPlayerMove(char array[ROWS][COLUMNS], char piece) {

  int rowChoice;
  int columnChoice;

  do {
  cout << "Please select the row to put your piece: " << endl;
  cin >> rowChoice;
  while (rowChoice < 0 || rowChoice > 2) {
    cout << "Invalid input for rows. Please select a valid input\n0, 1, or 2:"
        << " ";
        cin >> rowChoice;
  }

  cout << "Now select the column to put your piece: " << endl;
  cin >> columnChoice;
  while (columnChoice < 0 || columnChoice > 2) {
    cout << "Invalid input for columns. Please select a valid input\n"
        "0, 1, or 2: ";
        cin >> columnChoice;
  }

  if(array[rowChoice][columnChoice] != BLANK) {
    cout << "That space is already occupied. Please select a new row and/or "
          "column." << endl;
      }
  }
  while (array[rowChoice][columnChoice] != BLANK);

  array[rowChoice][columnChoice] = piece;

}


// TODO: Create a void function called SetComputerMove that takes a 2D char
// array as input and assigns the computer's piece to an available row and
// column.
// The computer should choose a random row and column. If you need a refresher
// how get a random 0, 1, or 2, refer to your rock paper scissors code.
// Should the random row/column be already occupied, choose another until an
// empty one is found. Your code shouldn't be here if there are no empty spaces.

  void SetComputerMove(char array[ROWS][COLUMNS], char piece) {

    int rowChoice;
    int columnChoice;

    srand(time(0));
    do {
      rowChoice = rand() % 3;
      columnChoice = rand() % 3;
    }
    while(array[rowChoice][columnChoice] != BLANK);

    array[rowChoice][columnChoice] = piece;

  }


// TODO: Create a bool function called CheckRows that determines whether any
// row has the same piece. CheckRows should take a 2D char array and a char
// representing the piece to check for.
bool CheckRows(char board[ROWS][COLUMNS], char piece) {
  // TODO: Use a for loop to check each row. In each row, check the columns
  // that all 3 have the piece from the input. (HINT: Use an if statement and
  // &&s). If they do, return true immediately, which will cause this function
  // to stop and return to the caller right away (short-circuiting).

  bool row_win;

  for (int i = 0; i < ROWS; i++) {
    if ((board[i][0] == board[i][1]) &&
        (board[i][1] == board[i][2]) &&
        (board[i][0] == piece)) {
          row_win = true;
        }
    else {
      row_win = false;
    }
  }

  return row_win;

  // TODO: If the code made it here, there must not have been any row with 3 of
  // a kind, so return false;
}

// TODO: Create a bool function called CheckColumns that determines whether
// any column has the same piece. CheckColumns should take a 2D char array and a
// char representing the piece to check for. Basically the same as CheckRows but
// operates on columns intead.

bool CheckColumns(char board[ROWS][COLUMNS], char piece) {

  bool column_win;

  for(int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      if((board[0][j] == board[1][j]) &&
         (board[1][j] == board[2][j]) &&
         (board[0][j] == piece)) {
          column_win = true;
      }
      else {
        column_win = false;
      }
    }
  }
  return column_win;
}


// TODO: Create a bool function called CheckDiagonals that takes a 2D char array
// and a char and returns whether either diagonal has the same piece (HINT:
// This can be done with just &&, ||, and checking certain spots in the board).

  bool CheckDiagonals (char array[ROWS][COLUMNS], char piece) {

    bool cross_win;

    if ((array[0][0] == array[1][1]) &&
        (array[1][1] == array[2][2]) &&
        (array[0][0] == piece)) {
          cross_win = true;
        }
    else if ((array[0][2] == array[1][1]) &&
             (array[1][1] == array[2][0]) &&
             (array[0][2] == piece)) {
               cross_win = true;
             }
    else {
      cross_win = false;
    }

    return cross_win;

  }

// TODO: Create a bool function called IsWinner that takes a 2D char array and a
// char representing a piece and determines whether that piece has won the game.
// HINT: Call CheckRows, CheckColumns, and CheckDiagonals.

  bool IsWinner(char array[ROWS][COLUMNS], char piece) {

    if ((CheckRows(array, piece) == true) ||
        (CheckColumns(array, piece) == true) ||
        (CheckDiagonals(array, piece) == true)) {
      return true;
    }
    else {
      return false;
    }

  }

// TODO: Create a bool function called IsBoardFull that takes a 2D char array
// and determines whether every spot is occupied. If at any point when a spot
// is empty, then the board can't possibly be full, and the function can return
// false immediately (short-circuiting).

  bool IsBoardFull(char array[ROWS][COLUMNS]) {

    char piece;

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLUMNS; j++) {
        while (array[i][j] == BLANK) {
            return false;
        }
      }
    }
    return true;

  }


// TODO: create a function called DetermineBoardState that takes a 2D char array
// as input and returns a string representing the outcome as defined in your
// constants above. Use IsWinner and IsBoardFull somewhere to determine what
// potential outcomes could be.

  string DetermineBoardState(char array[ROWS][COLUMNS], char x, char o) {

    if ((IsWinner(array, x) == true) &&
        (IsWinner(array, o) == false)) {
      return WIN;
    }
    else if ((IsWinner(array, o) == true) &&
             (IsWinner(array, x) == false)) {
      return LOSE;
    }
    else if ((IsBoardFull(array) == true) &&
             (IsWinner(array, x) == false) &&
             (IsWinner(array, o) == false)) {
               return DRAW;
    }
    else {
      return NOT_DONE;
    }
  }


int main(int argc, char* argv[]) {
  srand(time(0));

  // TODO: Create a 2D array of type char to represent the board. Initialize
  // all rows and columns to empty, as defined in your constants above, and
  /// using the array initializer syntax {}.

  char game[ROWS][COLUMNS];

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      game[i][j] = BLANK;
    }
  }

  // TODO: Print the board before starting gameplay.

  Print(game);
  cout << endl;

  // TODO: Alternate turns between the player and the computer until an outcome
  // is decided. Make use of your SetPlayerMove, SetComputerMove,
  // DetermineBoardState, and Print functions.

    while (DetermineBoardState(game, PLYR_PIECE, COMP_PIECE) == NOT_DONE) {
      SetPlayerMove(game, PLYR_PIECE);
      SetComputerMove(game, COMP_PIECE);
      cout << endl;
      Print(game);
    }

  // TODO: Print the final outcome of the game.

  cout << endl;
  string result = DetermineBoardState(game, PLYR_PIECE, COMP_PIECE);
  cout << result << endl;


  return 0;
}
