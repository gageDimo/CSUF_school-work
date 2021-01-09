# Lab-10
Programming a game using 2D arrays and functions.

## Objectives
* Gain an understanding of how to program with 2D arrays
* Learn to pass statically-allocated 2D arrays with pre-determined size to functions
* Visualize 2D arrays as grids accessed by row and column
* Practice organizing code into various helper functions to keep code concise and readable
* Practice using nested `for` loops to traverse 2D arrays
* Gain familiarity with short-circuiting functions using the `return` statement
* Practice using functions that call other functions

## Instructions
Tic Tac Toe (https://en.wikipedia.org/wiki/Tic-tac-toe) is a popular 2-player game on a 3x3 grid. Players take turns marking spaces on the grid with their respective game pieces, typically `x` or `o`. The first player to achieve 3 in a row, column, or diagonal, wins. The game is drawn if the board is full yet neither player has achieved 3 in a row.

Write a simple Tic Tac Toe program that plays against the computer according to the following specifications:
* The board should be represented as a 2D array of `char`s
  * An empty spot is denoted using the space character, `' '`
  * The human player goes first and plays with `x`
  * The computer goes second and plays with  `o`
* The computer plays with a primitive AI that chooses a random available row/column to put its pieces.
  * For full credit: If a chosen random row/column is taken, just keep choosing another random row/column until a free one is available. Statistically, this should always converge on an available row/column, assuming one is available. Your code should check that the game isn't over before reaching this point.
  * For 0.5 extra credit points: The method above can take many guesses at available squares, especially as fewer and fewer become available. There is however a more efficient method that uses only what we've learned in class so far that can avoid unnecessary random guessing:
    * HINT: The 3x3 grid can be treated as 1 long array, with each spot corresponding to one of 0 - 8.
    * HINT: Traverse the 1 long array version of the grid and "record" which spots are still available into a second array and how many available spots have been found.
    * HINT: Use a random number generator to pick the available spot using the second array and the number of available spots.
  * For another 0.5 extra credit points: Make the computer play with some sort of intelligence of your design. For example, if the user is about to win on a row/column/diagonal, pick a move to try to block the user from winning. Similarly, if the computer has a potential win, pick the winning move. 

Because the board starts empty, it can be difficult to tell what spaces are available, and what row/column each one corresponds to (remember, rows and columns are not the same as x-y coordinates!)

Print your grid using 2 nested `for` loops, but with some extra helper symbols to make it look more like a tic-tac-toe board:
```
 | |
-+-+-
 | |
-+-+-
 | |
```

As the game progresses, depending on the moves played, the board should print out to look something like:
```
x|x|o
-+-+-
 |o|
-+-+-
 |o|x
```

As always you may use any output messages you wish, as long as they are within pg-13 levels of sarcastic sassy savagery.

#### Test Cases
1. For the player's move, attempt to assign a row/column out of bounds (e.g. (-1, 0), (3, 3)). Ensure the player is repeatedly re-prompted for a valid row/column before assigning their piece to the board.
2. For the player's move, attempt to assign a row/column that is already occupied by either one of their own pieces or one of the computer's. Ensure the player is repeatedly re-prompted for an unoccupied row/column before assigning their piece to the board.
3. Fill the board with no winner. Ensure the game ends with the outcome of a draw.
4. Play to beat the computer. Ensure the game ends with the outcome of the player winning.
5. Play to lose to the computer. Ensure the game ends with the outcome of the computer winning.

These are by no means exhaustive test cases, and there are a variety of ways to further test your individual functions to ensure they behave correctly in all basic scenarios. This is called "unit-testing" which is meant as a concise yet thorough way to test code to reveal fundamental issues or verify basic behavior, which will be covered in a separate lecture/lab.

## Grading
* (1 point): Your code uses a function to print the board's rows and columns correctly after each of the player's and computer's moves
* (1 point): Your code uses a function that allows the user only to select only valid (unoccupied) rows/columns to place pieces
* (1 point): Your code correctly displays the user's piece at the specified row/column
* (1 point): Your code uses a function to implement any sort of computer move generation (e.g. random available row/column)
* (1 point): Your code correctly chooses computer moves in available spaces only
* (1 point): Your code correctly displays the computer's move in the grid
* (1 point): Your code alternates between player and computer moves
* (1 point): Your code uses a function to check the state of the game
* (1 point): Your code displays the correct result when the game is over
* (1 point): Your code disallows further moves from either player immediately upon a winner being decided or a drawn game is achieved
* (0.5 points extra credit): Your code uses a more efficient algorithm for determining remaining available moves, such as the method described in the specifications
* (0.5 points extra credit): Your computer uses any sort of AI that can successfully defend or win in a variety of scenarios

## Hints
### Short circuiting functions
The `return` statement, when called anywhere in a function, can be used to stop execution of that function immediately and return to the caller right then and there. No code after a `return` statement, if reached, will execute.

For example,
```
bool IsValidDayOfWeek(string day_of_week) {
  string valid_days[7] = {"Sunday",
                          "Monday",
                          "Tuesday",
                          "Wednesday",
                          "Thursday",
                          "Friday",
                          "Saturday"};

  for (int i = 0; i < 7; i ++) {
    cout << "Checking " << day_of_week << "..." << endl;
    if (day_of_week == valid_days[i]) {
      // As soon as a match is found, return true immediately and don't bother
      // checking anything that comes after.
      cout << day_of_week << " is a valid day of the week. Rock will not be chosen on your behalf." << endl;
      return true;
    }
    cout << day_of_week << " is not " << valid_days[i] << "." << endl;
  }

  // If the code made it all the way down here, then day_of_week was not in the
  // array and therefore must not be a valid day of the week.
  return false;
}

int main(int argc, char* argv[]) {
  bool is_valid = IsValidDayOfWeek("Tuesday");
  return 0;
}

> ./a.out
Checking Sunday...
Tuesday is not Sunday
Checking Monday...
Tuesday is not Monday
Checking Tuesday...
Tuesday is a valid day of the week. Rock will not be chosen on your behalf.
```
In the above example, the code only had to check `Sunday`, `Monday`, and `Tuesday`, which matched the string perfectly,  causing the `return` statement to kick in and the whole function returned `true` to the caller.
