# Lab 08 - Functions/Methods
## Objective
* Introduce how to write functions/methods that return a value
* Introduce how to write functions/methods that take various inputs
* Refactor existing code
* Practice writing iteration using `do-while`
* Practice writing clean code and declaring global constants at the top of the program.

## Instructions
Start with your existing project1 code `rock_paper_scissors.cpp` (the gift that keeps on giving...). You may copy and paste it as-is from what you last submitted in Github into this lab's `rock_paper_scissors.cpp`. Alternatively, you may choose to start from scratch.

Go in order of parts: if you jump around you may not be able to run your code properly.

### Part-1: Declare constants used throughout the file
Declare 6 `string` constants at the top of the file before `main` to represent various words that will be used throughout the program:
1. One to represent `ROCK` with value `"rock"`.
2. One to represent `PAPER` with value `"paper"`.
3. One to represent `SCISSORS` with value `"scissors"`.
4. One to represent the word to represent the `PLAYER` with value `"player"`.
5. One to represent the word to represent the `COMPUTER` with value `"computer"`.
6. One to represent `TIE` games, `"tie"`.

For coding style, remember to name your constants in ALL_CAPS, with different words separated by underscores if needed. If you prefer, you may use the recommended names above in all caps.

```
#include <iostream>
#include <ctime>
using namespace std;

// TODO: Declare your new constants here.
// TODO: Deprecate (remove) your old constants, they won't be used anymore.

int main(int argc, char* argv[]) {
  // ... old existing code ...
}
```
### Part-2: Get the user's choice as a function
Near the top of the file, before `main` after your `const string`s, create a function/method that takes no input and returns a `string`. The body of the function should prompt the user for their choice as a word as a `string` using `cout` and `cin`. Name this function `GetPlayerChoice` or something along those lines. It will soon become clear why use `cin` this time over `argv`.

To keep things simple, assume only lower case letters are valid so "Rock" would be considered invalid. Check them against your `const string` values for `ROCK`, `PAPER`, `SCISSORS` for valid input. As before, if the user typed an invalid choice, yell at them and assign them `ROCK` or something.

Return the string that contains the word for what the user chose.
```
#include <iostream>
#include <ctime>
using namespace std;

// TODO: Constants go here.

string GetPlayerChoice() {
  string player_choice;

  // TODO: prompt the user.
  // TODO: Check against your constants, and assign them ROCK or something if
  // invalid.

  return player_choice;
}

// TODO: Create your other new functions here before main().

int main(int argc, char* argv[]) {
  // TODO: Deprecate the use of argc and argv, they won't be needed anymore.

  // TODO: Call your new function GetPlayerChoice and store it in a variable
  // just like below:
  string player_choice = GetPlayerChoice();

  // ... Existing other old code ...
}
```
When playing, the player is now expected to type the word "rock" "paper" or "scissors".
```
$ ./rock_paper_scissors
Enter your choice: rock
```

### Part-3: Get the computer's choice as a function
Refactor the part that determines the computer's choice into a function that takes no input/arguments, generates a random 0 1 or 2, and and returns the computer's choice as a `string`, either `"rock"`, `"paper"`, or `"scissors"` using the corresponding `const string`s. Name this function `GetComputerChoice` or something along those lines.

Create this function before `main` as well so it knows about it.

Call this function when it's time to decide the computer's choice, and store its result in a `string` variable. The function should also output the computer's choice to the terminal before returning it to the calling code.

```
// ... other code ...

string GetComputerChoice() {
  srand(time(0));
  int random_choice = rand() % 3;
  string computer_choice;
  // TODO: determine what to assign computer_choice based on random_choice.

  // TODO: Print what was assigned to the computer's choice so it's displayed
  // in the terminal.
  TODO: Return computer_choice
}

// ... other code ...

int main(int argc, char* argv[]) {
  string player_choice = GetPlayerChoice();

  // TODO: Call GetComputerChoice() and store its return value similar to above.

  // ... other code ...
}
```

### Part-4: Get the winner based on what the player and compute each chose as a function.
Refactor the part that decides the winner into a function that takes 2 `string`s as input: one representing the player's choice, and the other the computer's. The return value should be a `string`, either `"player"`, `"computer"`, or `"tie"` using your constants at the top of the file. The function should print the winner to the terminal (so the user can see what happened), and return the value to the calling code (so the calling code can remember that value and use it for other things later, like say, optional part 6.)

Refactor your code that prints the winner to use the result of this function as part of the output string.

```
// ... other code ...

string DetermineWinner(string player_choice, string computer_choice) {
  // TODO: Decide who won by comparing player_choice and computer_choice and
  // store the result ("player", "computer", or "tie") in a string.

  // TODO: Print a message incorporating the result above in a way that is clear
  // to the user.

  // TODO: return the result ("player", "computer", or "tie") so the calling can
  // can use it.
}

// ... other code ...

int main(int argc, char* argv[]) {
  // ... other code ...

  // Call DetermineWinner.
}
```

### Part-5 (Optional Challenge): Play multiple rounds
Create a function that takes no parameters, but returns a `char`, either `YES` or `NO`. In the body of the function, prompt the user for a character using `cout` and `cin`. Use a `do-while` loop to repeatedly prompt the user until either `y` or `n` is entered. For example, entering `c` should re-prompt them, just like the PIN number from lab-06. When either a `y` or `n` is entered, return that character's corresponding constant.

Name this function `PlayAnotherRound` or something similar.

Wrap the game code in a `do-while` loop to play multiple rounds until the user quits:
```
int main(int argc, char* argv[]) {
  // ... other code ...
  do {
    string player_choice = GetPlayerChoice();
    // TODO: move other game logic in here too../rock_paper_scissors easy

    // TODO: call the PlayAnotherRound function here.
  } while (Something with whether to play another around);
}
```

If going for part 7 too, this function will need to take `string difficulty` as an input as well.

### Part-6 Optional Challenge: Keep Score
Using the return value of `DetermineWinner`, count the number of times the computer wins, the player wins, or ties After the `do-while` loop, print a summary of wins/losses/ties.

### Part-7 Optional Challenge: Artificial Intelligence
Specify an optional argument in the command line (bring back `argv`) that allows the user to specify the `difficulty`: `"easy"`, `"medium"`, or `"impossible"`, and pass this argument to `GetComputerChoice(string player_choice, string difficulty)`

* easy: Based on what the player chose, always choose the losing game element.
* medium: Play normally with a random choice (`player_choice` is essentially ignored).
* impossible: Based on what the player chose, always choose the winning game element.

```
$ ./rock_paper_scissors easy
```

## Function Hints
### Declaring a function
Function declarations consist of 4 main parts (usually):
* What <b>type</b> of result does the function produce, if any at all?
* What should the function be <b>named</b>, according to what it does?
* What will the function consume as <b>input</b> that might affect its output/return value?
* When is it ready to `return` the value it's expected to produce? (all functions need this, except those with `void` return type which will be covered later in the class).

```
<type> <function name>(<type> input separated by commas...) {
  // Logic of the body goes here.
  // use return somewhere in here.
}
```

For example, a function that takes a `string` as input and produces an `int` containing the length of the string might look like:
```
int DetermineLengthOfString(string input) {
  int length = input.length();
  return length;
}
```

Another example of a function that takes 2 inputs arguments/parameters, a `string` and an `int` and produces a `char` output:
```
char GetCharacterAtIndex(string word, int index) {
  char character_at_index = word[index];
  return character_at_index;
}
```
Note the `,` that separates the inputs, which is needed in between each input parameter.

### Using a function's return value
The code that uses a function is called the <i>calling code</i>. Functions that return values (all but `void` functions, again which will be covered later), may want their returned value stored somewhere by the calling code. This can be accomplished by using a variable in the calling code, and assigning it the value of the function when called. For example,
```
int DetermineLengthOfString(string input) {
  int length = input.length();
  return length;
}

int main(int argc, char* argv[]) {
  string hello = "Hello";
  int length = DetermineLengthOfString(hello_world);
  cout << length < endl;
}

> 5
```

### Short-circuiting a function with `return`
Remember the `return` statement, when used inside a function will cause it to stop and report back to the calling code immediately with the value passed after saying `return`. Using `return` strategically in functions can lead to some very clear and concise code, but the details of which are to be discussed in a future class. You shouldn't 

## Grading
* (1 point): `GetPlayerChoice` exists with the correct return type and arguments.
* (1 point): `GetPlayerChoice` returns the player's choice as "rock" "paper" or "scissors".
* (1 point): `GetPlayerChoice` is called from somewhere in `main`.
* (1 point): `GetComputerChoice` exists with the correct return type and arguments.
* (1 point): `GetComputerChoice` prints the computer's choice and returns the corresponding `string` as "rock" "paper" or "scissors".
* (1 point): `GetComputerChoice` is called from somewhere in `main`.
* (1 point): `DetermineWinner` exists with the correct return type and arguments.
* (1 point): `DetermineWinner` prints the winner and returns the correct outcome as a `string`.
* (1 point): `DetermineWinner` is called from somewhere in `main`.
* (1 point): Your program passes the original test cases, but with "rock" "paper" and "scissors" instead of 0 1 2.
