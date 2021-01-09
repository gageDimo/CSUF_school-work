# Lab 05
Now that you have familiarity with `if` `else if` and `else`, you can create more sophisticated logic using `&&` (and), `||` (or), and `!` (not).

# Objectives
* Gain understanding in how to program with `&&`, `||`, `!`
* Begin programming with the `return` statement
* Write more robust code that checks valid/invalid inputs

# Instructions
In this week's lab, you will be interpreting a fun no parking sign I found outside

* No parking anytime Monday
* No parking 9am - 5pm Tuesday
* No parking 8pm - 11pm except Sunday

Determine whether parking is allowed at a specified time, given a day of week and a military time of day, such as Thursday 1400 (2pm).

Assume the end time of the no parking time window is valid to park. For example, 5pm on Tuesday is valid to park, since the no-parking window just ended at that time, while 4:59pm is not.

Follow the `TODOs` and hints in the code to produce a robust no parking sign program that fully understands the rules above.

Remember to `git push` your changes so they can be graded!
# Test Cases
```
lab-05$ ./no_parking Monday 100
No, you may not park.

lab-05$ ./no_parking Monday 2359
No, you may not park.

lab-05$ ./no_parking Tuesday 859
Yes, you may park.

lab-05$ ./no_parking Tuesday 900
No, you may not park.

lab-05$ ./no_parking Tuesday 1659
No, you may not park.

lab-05$ ./no_parking Tuesday 1700
Yes, you may park.

lab-05$ ./no_parking Tuesday 2000
No, you may not park.

lab-05$ ./no_parking Tuesday 2259
No, you may not park.

lab-05$ ./no_parking Wednesday 800
Yes, you may park.

lab-05$ ./no_parking Wednesday 2001
No, you may not park.

lab-05$ ./no_parking Sunday 2200
Yes, you may park.

lab-05$ ./no_parking Squirrel 32
Squirrel is not a valid day of the week.

lab-05$ ./no_parking wednesday 4
wednesday is not a valid day of the week.

lab-05 ./no_parking Thursday -4
Bruh... -4 isn't a time of day! Get with the program!

lab-5 ./no_parking
Usage: ./no_parking <day of week> <military time of day>
```
These test cases are by no means exhaustive, note what about Friday, or Saturday, etc? Hang tight, we will cover automated unit testing in a few weeks!

# Grading
Code that does not compile will receive a score of 0.

1. (1 point): Your code includes your full name and lab section at the top of `no_parking.cpp`.
2. (1 point): Your code uses any combination of `if`, `else if`, `else`, `&&`, `||`, and `!`.
3. (1 point): Your code checks for the correct number of arguments, and prints an error for incorrect number of arguments and an example for how to use the program, and quit.
4. (1 point): Your code checks that the day provided is a valid day of the week with a capital first letter, such as "Tuesday". "tuesday" or "Squirrel" however are not valid, and your code should quit.
5. (1 point): Your code checks that the time provided is sort-of valid military time, e.g. 1559. Don't worry about cases like 1560 which are more difficult to detect, but anything below 0 or over 2359 is obviously invalid.
6. (5 points): Your code passes all the provided test cases.

# Hints
## `&&` Logical "and"
All operands must evaluate to true in order for the whole statement to be true. You can include as many expressions surrounding each `&&`. Think "In order to vote, you must be a citizen of the US, not a felon, and at least 18 years of age".
```
int age = 18;
bool isFelon = false;
bool isCitizen = true;

bool canVote = isCitizen && !isFelon && (age >= 18); // Evaluates to true.
```
## `||` Logical "or"
Any operand evaluates to true in order for the whole statement to be true. You can include as many expressions surrounding each `||` as you need. Think "In order to take CPSC 335, you must have passed the EPP exam, or passed CPSC301"
```
bool passedEPP = false;
bool took301 = true;

bool canTake335 = passedEPP || took301; // Evaluates to true, because took301 is true.
```

## `!` Logical "not"
`true` flips to `false`, and `false` flips to `true`. Think "If you did not pass the EPP exam, you will need to take CPSC301 in order to continue the upper level classes."
```
bool passedEPP = false;

if (!passedEPP) { // If you didn't pass EPP...
  cout << "You need to take CPSC 301" << endl;
}
```

## Making code "quit" or "exit" or "leave" at any point.
There are a few ways to make your code quit in the middle. For now, use the `return` statement if a certain condition is met. For example, if the user didn't specify the correct number of arguments, yell at them and peace out.

```
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    // argc is the number of arguments this program is called with, including the
    // name of the program.
    if (argc != 4) {
        cout << "Expected 4 arguments, but got " << argc << " arguments!" << endl;
        return 0; // This will cause the function "main" to exit immediately.
    }

    // Otherwise, the code continues as normal...
    cout << "La de da..." << endl;
}
```
`return` Causes the calling function to exit immediately, which in this case is `main`. We will cover `return` in much more detail when we learn about functions.
```
$ g++ main.cpp
$ ./a.out way too many arguments
Expected 4 arguments, but got 5!
$
```
"./a.out" is an argument, "way" is another, "too" is another, "many" is another, and "arguments" for a total of 5.

```
$./a.out just enough arguments
La de da...
$
```
"./a.out" is an argument, "just" is another, "enough" is another, "arguments" is another, for a total of 4. The `if` statement's requirement of being "not equal to 4" is not met, so the program continued.


## String comparisons
You can check words have the same value using `==` just like you do with `int`s. Note string comparisons are case sensitive!

```
string word = "hello";
string anotherWord = "world!";

word == anotherWord; // false, because "hello" and "world!" are distinct words.
```
```
string word = "hello";
string anotherWord = "hello";

word == anotherWord; // true, because "hello" and "hello" look the same.
```
```
string word = "hello";
string anotherWord = "Hello";

word == anotherWord; // false. "hello" and "Hello" aren't the same because of "h" vs "H"
```

## Military time
Military time effectively is a numerical representation of every hour and minute of the day, starting with 0 (midnight), up until 2359 (11:59pm). Examples include
* 0: Midnight
* 100: 1am
* 600: 6am
* 1130: 11:30am
* 1200: noon
* 1300: 1pm
* 1459: 2:59pm
* 2345: 11:45pm

Military time can be treated as a number, but with a catch: the 10s place only goes from 0-5! e.g. There is no 1590 time, that would be like saying 3:90pm. Being able to check for that is tricky, so for now just assume the user inputs valid military times.

If you want to pursue the optional challenge of detecting times like 1590, try checking for the 10s digit in the time. The `%` operator is your friend!
