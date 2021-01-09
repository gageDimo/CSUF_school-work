// Michael Dimapindan CPSC 120 Section 6
#include <iostream>
#include <ctime>

using namespace std;

  const int ROWS = 6;
  const int COLUMNS = 7;

  const char USER = 'O';
  const char COMP = 'X';
  const char SPACE = ' ';

  const string WIN = "You win!";
  const string LOSE = "You lose!";
  const string DRAW = "Tie game!";
  const string NOT_DONE;

  void PrintBoard(char board[ROWS][COLUMNS]) {

    for (int i = 0; i < ROWS; i++) {

      for (int j = 1; j <= COLUMNS; j++) {

        cout << "| " << board[i][j];

        if (j == COLUMNS) {
          cout << "|";
        }

      }

      cout << endl;

    }

  }

  void SetPlayerMove(char array[ROWS][COLUMNS], char piece) {

    int columnChoice;

        cout << "Select a column to place your piece: ";
        cin >> columnChoice;

        while (columnChoice < 1 || columnChoice > 7) {
          cout << "Invalid input. Select a column from 1 to 7: ";
          cin >> columnChoice;
        }

          while (array[0][columnChoice] != SPACE) {

            cout << "This is column is full. Select a new column." << endl;
            cin >> columnChoice;

          }

          int j = ROWS;
          while (array[j][columnChoice] != SPACE) {
            j--;
          }

      for(int a = 0; a<=j; a++) {

        array[a][columnChoice] = piece;

        if(a != 0) {
        array[a-1][columnChoice] = SPACE;
        }
      }

  }

  void SetComputerMove(char array[ROWS][COLUMNS], char piece) {

    srand(time(0));
    int columnChoice = (rand() % 7) + 1;

    while (array[0][columnChoice] != SPACE) {
      columnChoice = (rand() % 7) + 1;
    }

        int i = ROWS;
        while (array[i][columnChoice] != SPACE) {
          i--;
        }

      for(int b = 0; b <= i; b++) {

        array[b][columnChoice] = piece;

        if (b != 0) {
        array[b-1][columnChoice] = SPACE;
        }

      }

  }

  bool CheckColumns (char array[ROWS][COLUMNS], char piece) {
    bool column_win;
    for (int i = 0; i < ROWS; i++) {
      for (int j = 1; j <= COLUMNS; j++) {
        if ((array[i][j] == piece) && (array[i+1][j] == piece) &&
            (array[i+2][j] == piece) && (array[i+3][j] == piece)) {
              column_win = true;
            }
        else {
          column_win = false;
        }
      }
    }
      return column_win;
  }

  bool CheckRows (char array[ROWS][COLUMNS], char piece) {

    bool row_win;

    for (int i = 0; i < ROWS; i++) {
      for (int j = 1; j <= COLUMNS; j++) {
        if ((array[i][j] == piece) && (array[i][j+1]) == piece &&
            (array[i][j+2] == piece) && (array[i][j+3] == piece)) {
              row_win = true;
            }
        else {
          row_win = false;
        }
      }
    }
      return row_win;
  }

  bool CheckDiagonals (char array[ROWS][COLUMNS], char piece) {

    bool cross_win;

    for (int i = 0; i < ROWS; i++) {
      for (int j = 1; j <= COLUMNS; j++) {
        if ((array[i][j] == piece) && (array[i+1][j+1] == piece) &&
            (array[i+2][j+2] == piece) && (array[i+3][j+3] == piece)) {
              cross_win = true;
            }
        else if ((array[i][j] == piece) && (array[i-1][j+1] == piece) &&
                 (array[i-2][j+2] == piece) && (array[i-3][j+3] == piece)) {
                   cross_win = true;
                 }
        else {
          cross_win = false;
        }
      }
    }

    return cross_win;

  }

  bool GameWon(char array[ROWS][COLUMNS], char piece) {
    if((CheckRows(array, piece) == true) || (CheckColumns(array,piece) == true)
      || (CheckDiagonals(array, piece) == true)) {
        return true;
      }
    else {
      return false;
    }

  }

  bool BoardFull(char array[ROWS][COLUMNS]) {

    for (int i = 0; i < ROWS; i++) {
      for (int j = 1; j <= COLUMNS; j++) {
        if (array[i][j] == SPACE) {
          return false;
        }
        else {
          return true;
        }
      }
    }

  }

  string BoardState(char array[ROWS][COLUMNS], char o, char x) {

    if((GameWon(array, o) == true) &&
       (GameWon(array, x) == false)) {
      return WIN;
    }

    else if((GameWon(array, x) == true) &&
           (GameWon(array, o) == false)) {
      return LOSE;
    }
    else if((BoardFull(array) == true) && (GameWon(array, x) == false) &&
       (GameWon(array, o) == false)) {
      return DRAW;
    }
    else {
      return NOT_DONE;
    }

  }

int main (int argc, char* argv[]) {
  srand(time(0));

  char game[ROWS][COLUMNS];
  for (int i = 0; i < ROWS; i++) {
    for (int j = 1; j <= COLUMNS; j++) {
      game[i][j] = SPACE;
    }
  }

  PrintBoard(game);

  while (BoardState(game, USER, COMP) == NOT_DONE) {

      SetPlayerMove(game, USER);
      SetComputerMove(game, COMP);

      cout << endl;
      PrintBoard(game);

        }

    cout << endl;
    string result = BoardState(game, USER, COMP);
    cout << result << endl;

    return 0;

}
