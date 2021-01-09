# CPSC 120 - Lab 4
In order for AI to take over the world and render humans obsolete, computers first need to be able to make decisions. Today we will be teaching the computer how to interpret basic data and come to a conclusion, so tomorrow the robot apocalypse can happen.

## Objectives
* Understand how to code using `if`, `else if`, and `else` statements
* Understand some basics of using random numbers
* Understand how to use comparison operators
  * equal `==`
  * greater than or equal to `>=`
  * less than or equal to `<=`
  * greater than `>`
  * less than `<`
* Understand how to pass input using command line arguments

## Instructions
1. Read the instructions.
2. Follow the instructions.
3. Git clone your assignment. If you need a refresher, refer to lab 1 or 3.
4. `cd` into the appropriate directories, and hack away! If you need a refresher, refer to lab 1 or 3.
5. Git push your changes as many times as you'd like, and for sure at least once before you leave or we can't give you credit for all your hard work.

### `part-1/library_fines.cpp`
Here at CSUF, the library likes to get its stuff back on time. According to the library's policy found at https://www.library.fullerton.edu/about/guidelines/fines.php, the fines and penalties for materials being late is:
* 1 day past due: 1st overdue notice
* 30 days past due: 2nd overdue notice
* 60 days past due: 3rd overdue notice
* 90 days past due: bill for replacement

When borrowers fail to return checked-out materials on time, the Library assesses overdue fines:
* $0.25 per day late
* $90 replacement cost

Using a combination of `if` `else if` `else` statements, determine which overdue notice to issue and how much the fine is.

In order to see your changes to `library_fines.cpp` in action, save the file and compile it using
```
part-1$ g++ library_fines.cpp -o library_fines
```

Run your code using
```
part-1$ ./library_fines <the number of days late, such as 5>
```

For example,
```
part-1$ ./library_fines 5
Your book is overdue! This is your first overdue notice. The fine you owe is $1.25.
part-1$
```

After you are done, upload your code changes to `library_fines.cpp` and resulting executable `library_fines` to github. Remember to use `git add`, `git commit -m`, `git push`. If you need a refresher, refer to lab 1's instructions.

#### Test Cases
```
part-1$ ./library_fines -5
Your book was returned on time!
No fine.

part-1$ ./library_fines 0
Your book was returned on time!
No fine.

part-1$ ./library_fines 1
Your book is overdue!
This is your first overdue notice.
The fine you owe is $0.25.

part-1$ ./library_fines 29
Your book is overdue!
This is your first overdue notice.
The fine you owe is $7.25.

part-1$ ./library_fines 30
Your book is overdue!
This is your second overdue notice.
The fine you owe is $7.50.

part-1$ ./library_fines 59
Your book is overdue!
This is your second overdue notice.
The fine you owe is $14.75.

part-1$ ./library_fines 60
Your book is overdue!
This is your third overdue notice.
The fine you owe is $15.00.

part-1$ ./library_fines 89
Your book is overdue!
This is your third overdue notice.
The fine you owe is $22.25.

part-1$ ./library_fines 90
Your book is assumed lost.
This is a bill for replacement.
The fine you owe is $90.
```

### `part-2/rock_paper_scissors.cpp`
A quick and popular game for deciding a winner between two players is Rock, Paper, Scissors. Two players secretly decide which of rock, paper, or scissors they will choose, and simultaneously reveal their choices. A player wins if their choice beats their opponent's choice:
* Rock beats scissors, but loses to paper
* Paper beats rock, but loses to scissors
* Scissors beats paper, but loses to rock
* If the players both make the same choice, the game is a draw.

`part-2/rock_paper_scissors.cpp` is to implement a program that plays a single round of Rock, Paper, Scissors with the user.

After you are done, upload your changes to `rock_paper_scissors.cpp` code and executable `rock_paper_scissors` to github. Remember to use `git add`, `git commit -m`, `git push`. If you need a refresher, refer to lab 1's instructions.

#### Debugging
The nature of using random numbers can make debugging/testing difficult, as each time you run the program it would produce a different result. I recommend starting by hard-coding the computer's choices to make results predictable. Only when you are confident all branches are working as advertised, make the computer's choice random.

#### Test Cases
```
part-2$ ./rock_paper_scissors 0
You chose rock.
The computer chose rock.
Draw!

part-2$ ./rock_paper_scissors 0
You chose rock.
The computer chose paper.
You lose!

part-2$ ./rock_paper_scissors 0
You chose rock.
The computer chose scissors.
You win!

part-2$ ./rock_paper_scissors 1
You chose paper.
The computer chose rock.
You win!

part-2$ ./rock_paper_scissors 1
You chose paper.
The computer chose paper.
Draw!

part-2$ ./rock_paper_scissors 1
You chose paper.
The computer chose scissors.
You lose!

part-2$ ./rock_paper_scissors 2
You chose scissors.
The computer chose rock.
You lose!

part-2$ ./rock_paper_scissors 2
You chose scissors.
The computer chose paper.
You win!

part-2$ ./rock_paper_scissors 2
You chose scissors.
The computer chose scissors.
Draw!

part-2$ ./rock_paper_scissors 44123
I don't know what 44123 is. Rock has been chosen on your behalf.
The computer chose scissors.
You win!
```

After you are done, upload your code changes to `rock_paper_scissors.cpp` and resulting executable `rock_paper_scissors` to github. Remember to use `git add`, `git commit -m`, `git push`. If you need a refresher, refer to lab 1's instructions.

## Grading
By now, you should all be highly familiar with compiling and running your code. Code that doesn't at least compile can't be graded, and will receive a score of 0.

1. (1 point): Your full name and lab section are at the top of `library_fines.cpp` and `rock_paper_scissors.cpp`.
2. (1 point): Your executables are uploaded to git in the same directories as your code changes and named correctly (not `a.out`):
  * `rock_paper_scissors` is in the same directory as `rock_paper_scissors.cpp`
  * `library_fines` is in the same directory as `library_fines.cpp`
3. (1 point): `library_fines` reads the number of days late as a command line argument
4. (1 point): `library_fines` prints the correct overdue notice for all test cases.
5. (1 point): `library_fines` prints the correct overdue amount for all test cases.
6. (1 point): `rock_paper_scissors` reads the user's choice as 0, 1, or 2 through the command line
7. (1 point): `rock_paper_scissors` checks for an invalid `int` input, such as 564 when the expected values are 0, 1, or 2.
8. (1 point): `rock_paper_scissors` correctly interprets the user's choice of rock, paper, or scissors.
9. (1 point): `rock_paper_scissors` correctly chooses a computer choice at (pseudo) random.
10. (1 point): `rock_paper_scissors` correctly decides the winner or if the game is a draw for all test cases.

## Hints
### Reading input from the command line
Very often, you will see code
```
int main(int argc, char* argv[]) {
    // Fancy schmancy code in here using argc and argv.
}
```

When `main` executes, such as running `./a.out`, it also reads the words following `./a.out`, separated by spaces. Each "word" is referred to as an "argument". The number of arguments is captured in argc, while the arguments themselves are captured in argv. Don't worry about what `char*` means for now, just assume it is a word and can be treated as a `string`. `char*` will likely be covered in your 121 class.

Each argument can be extracted separately using the position starting from 0:
```
int main(int argc, char* argv[]) {
    string programName = argv[0];   // argv[0] contains the program name.
    string firstArgument = argv[1]; // argv[1] is the first argument, which comes next.
    string secondArgument = argv[2];// argv[2] is the second argument, which comes after that.

    cout << "The program name is: " << programName << endl;
    cout << "The first argument is: " << firstArgument << endl;
    cout << "The second argument is: "<< secondArgument << endl;
}
```

Compiling and running the program would look like:
```
$ g++ main.cpp
$ ./a.out one two
The program name is: a.out
The first argument is: one
The second argument is: two
```

### Converting `string` to `int`
`std` has a built-in function called `stoi`, which converts a `string` to an `int`. For example,

```
string numbersAsString = "01234"; // The word "01234".
int numbersAsInt = std::stoi(numbersAsString);  // Converts "01234" to an int with value 1234.
```

### `if`, `else if`, and `else`
#### The lone `if` statement
Use if only in some cases should something happen, but the program will continue afterwards regardless (well.. most of the time, unless something in the if statement causes an exit or return, but that's a topic for a future lecture and lab). Think "Time to go outside. If it's raining, bring an umbrella. Then go outside."

```
if (expression) {
  // Statements to do only if expression evaluates to true.
}
// Program continues execution.
```

#### The `if-else` statement
Use this if there need to be distinct outcomes should the if statement evaluate to false. Think "Time to go outside. Is there a hurricane? If so, stay inside. Otherwise, go outside."
```
if (expression) {
  // Statements to do only if expression evaluates to true.
}
else {
  // Statements to do only if expression evaluates to false.
}
```
Note the `else` won't make sense without the `if`!

#### The `if-else if-else` statement
Use this if many possibilities can be tried before giving up. Think "The door's locked. I don't know which key is right, but I have a bunch of keys I can try. Is it the first one? How about the second? The third? Etc. Or do I need to call a locksmith?"
```
if (expression1) {  // Try this first.
  // Statements to do if expression1 evaluates to true.
}
else if (expression2) { // Not the first? How about this one?
  // Statements to do if expression1 evaluates to false but expression2 evaluates to true.
}
... // You can have as many else if cases as you need.
else { // None of the above.
  // Statements to do if none of the expressions above evaluates to true.
}
```

### Comparison operators
* `==` Left side is equal to right, not to be confused with `=`, which is for assignment!
* `!=` Left side is not equal to right
* `>=` Left side is greater than or equal to right
* `<=` Left side is less than or equal to right
* `>` Left side is greater than right
* `<` Left side is less than right

Examples
```
if (sum == 21) // Checks if sum has the value 21 (blackjack!)

if (hours > 24) // Checks if hours is more than 24 (It's been more than a day)

if (score <= 60) // Checks if score is 60 or below

if (amountPaid != 50) // Checks if amountPaid is not 50.
```

Remember not to put spaces between `==`, `!=`, `>=`, and `<=` or your code won't compile.

### Random Numbers
There are a variety of ways to implement random numbers in C++. Today's focus isn't on doing it a specific way per say, but just getting some basic random number generator working for this assignment.

`rand()` is a built-in function that returns a "random" positive integer. It's not truly random though, as getting a computer that deals in concrete 0s and 1s to think of a "random" number is difficult. Thus, it's actually reading from a fixed list somewhere and just returning numbers from that list in order. A program that calls `rand()` a bunch of times actually would behave the same time very time, since reading from that list of pre-determined random numbers would start from the beginning each time.

A workaround is to "seed" the random number generator, which is to tell it to start at a different place on that list. In this case, we will use the current time to tell rand() where on that list to begin pulling numbers, to create the illusion of getting different random numbers each time the program is run. This is done using `#include <ctime> ... srand(time(0))` first before calling `rand()` to achieve pseudo-random numbers. Further details aren't necessary for this class.

Since `rand()` returns a pseudo-random positive integer, if you want a random number within a certain range, you can use `%` to take the remainder divided by a number you specify. For example, `rand() % 2` will always give me either a 0, or a 1, since the remainder of any number divided by 2 is either 0 or 1.
