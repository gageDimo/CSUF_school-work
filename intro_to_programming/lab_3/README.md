# CPSC 120 - Lab 3
In the previous lab, you had practice with coding with `cin`, `cout`, outputting hard-coded strings and variables, and basic operators on `int`. This lab will focus on further variable assignment, `int`, `float`, `string`, and more built-in operators, namely `/`. and `%`

## Objective
* Understand how to code with a combination of `int` and `float` to achieve mathematical precision
* Understand how to use the division `/` and modulo `%` operators
* Understand basic `string` manipulation and common escape sequences
* Understand variable assignment in terms of other variables
* Understand how to name the program produced by `g++` to something other than `a.out`
* Have basic familiarity with type casting
* Be able to navigate different directories in the terminal

## Instructions
This lab is expected to be substantially more challenging than the previous two labs, but lots of hints have been provided! Before you start programming, read these instructions from beginning to end, including the hints at the end.

Just as with the other labs so far, you will need to use `git clone <link to your repository>` to download your assignment.

For example, in the terminal:
```
:~$ ls
Desktop Documents Downloads Music Pictures Public Templates Videos
:~$ cd Desktop
:~/Desktop$ mkdir cpsc120
:~/Desktop$ cd cpsc120
:~/Desktop/cpsc120$ git clone <link to repository copied from the assignment page>
```
Type your username/password, and `cd` into the new directory created running `git clone` successfully. <b>These instructions above are just reminders! They may need tweaking to work in your exact environment, specifically the git clone link!</b>
```
:~/Desktop/cpsc120$ cd lab-03-<your gitub username>
:~/Desktop/cpsc120/lab-03-<your github username>$
```

This will be a 3-part lab. There are 3 files in 3 different folders to modify and submit:
1. `part-1/calculator.cpp`
2. `part-2/hms.cpp`
3. `part-3/the_raven.cpp`

### `part-1/calculator.cpp`
This program is a basic calculator very similar to what you implemented in lab last week, but you will be extending it to perform division using `/` and remainders using `%` as well. Parts of it have already been filled in for you, while others that need to be filled in are marked with `// TODO`. Follow the instructions in each of those, and remove the `TODO` part of the comment when you're done (you can leave the rest of the comment intact, or create your own).

To start, use `cd` to change directories into `part-1/`. This way when you tell `g++` about `calculator.cpp`, it'll know where it is since it's in the same directory.
```
:~/Desktop/cpsc120/lab-03-<your github username>$ cd part-1/
:~/Desktop/cpsc120/lab-03-<your github username>/part-1$
```

Always compile and run your changes, even if they're small! Compile and run your code using
```
:~/Desktop/cpsc120/lab-03-<your github username>/part-1$ g++ calculator.cpp -o calculator
:~/Desktop/cpsc120/lab-03-<your github username>/part-1$ ./calculator
```
-o calculator tells g++ that you want to name the program to something other than `a.out`, namely `calculator`. You can specify anything you like for the name following -o.

#### Test cases
Division has a fundamental caveat: dividing by 0 is undefined! Forcing a divide by 0 will raise a `floating point exception` which causes the program to crash. Since we haven't covered conditionals yet, there's no way to check for this using only what we've learned so far. So for now, make sure the exception is raised when using 0 as the second number.

The addition, subtraction, and multiplication parts were already tested as part of last week's lab and will not be considered for grading this time. Thus, focus on the new stuff around `/` and `%`.

* (any number, 0): Your program exits with `floating point exception`.
* (0, 1) `0 / 1 = 0, or 0r0`
* (1, 1) `1 / 1 = 1, or 1r0`
* (1, 2) `1 / 2 = 0.5, or 0r1`
* (-1, 1) `-1 / 1 = -1 or -1r0`
* (3, 5) `3 / 5 = 0.6 or 0r3`
* (5, 3) `5 / 3 = 1.66667 or 1r2`

### `part-2/hms.cpp`
HMS generally refers to hours, minutes, seconds (no, we're not talking about the naming for navy ships, "Her Majesty's Ship"). You will be writing a simple program that takes a positive integer number of seconds, and returns the equivalent number of days, hours, minutes, and seconds. For example, 10000 seconds corresponds to 1 day, 3 hours, 46 minutes, and 40 seconds, which should print as `1 days 3:46:40` (don't worry about day vs days, just use days).

Getting hms.cpp to work properly has a variety of approaches, thus this file will start mostly empty. However it must include the following:
* Prompt the user for an `int` to represent seconds.
* Use any combination of the basic operators you've learned thus far to calculate days, hours, minutes, seconds, namely `+-*/%=`. `%` should be particularly useful, but this assignment can technically be done without it.
* Display the result in the format "n days hours:minutes:seconds". For example, `0 days 1:45:30` or `4 days 0:0:51`.
* Define well-named global constants near the top of the file to represent conversion factors between days, hours, minutes, and seconds. See hints for `const`

In the terminal, if you're coming in from part 1, `cd` into `part-2/`
```
:~/Desktop/cpsc120/lab-03-<your github username>/part-1$ cd ..
:~/Desktop/cpsc120/lab-03-<your github username>$ cd part-2/
:~/Desktop/cpsc120/lab-03-<your github username>/part-2$
```

Compile and run your code using
```
:~/Desktop/cpsc120/lab-03-<your github username>/part-2$ g++ hms.cpp -o hms
:~/Desktop/cpsc120/lab-03-<your github username>/part-2$ ./hms
```
#### Test Cases
Assume all inputs are at least 0, so no need to test negative numbers. Note these numbers are carefully chosen to exercise the limits of each component (days, hours, minutes, seconds) specifically and separately. Great software developers are also great at coming up with effective unit tests!

* `0: 0 days 0:0:0` Tests the minimum supported time
* `1: 0 days 0:0:1` Tests the minimum value in the seconds place
* `59: 0 days 0:0:59` Tests the maximum number in the seconds place
* `60: 0 days 0:1:0` Tests the minimum number in the minutes places
* `3540: 0 days 0:59:0` Tests the maximum number in the minutes place
* `3600: 0 days 1:0:0` Tests the minimum number in the hours place
* `82800 0 days 23:0:0` Tests the maximum number in the hours place
* `86399: 0 days 23:59:59` Tests the maximum time in each of hours, minutes, seconds
* `86400: 1 days 0:0:0` Tests the minimum number in the days place
* Once those cases are working, test any `int` above `86400`: it should work with confidence!

### `part-3/the_raven.cpp`
This part of the lab is to get familiar with some basic string manipulation. You are given an excerpt from Edgar Allan Poe's <i>The Raven</i>

Fill in the `// TODO:` parts in the starter code.

In the terminal, if you're coming in from part 1 or part 2, `cd` into `part-3/`
```
:~/Desktop/cpsc120/lab-03-<your github username>/part-2$ cd ..
:~/Desktop/cpsc120/lab-03-<your github username>$ cd part-3/
:~/Desktop/cpsc120/lab-03-<your github username>/part-3$
```

Compile and run your code using
```
:~/Desktop/cpsc120/lab-03-<your github username>/part-3$ g++ -o edgar_allan_poe the_raven.cpp
:~/Desktop/cpsc120/lab-03-<your github username>/part-3$ ./edgar_allan_poe
```

#### Test Cases
Ensure the output looks as described:

```
Once upon a midnight dreary, while I pondered, weak and weary,
Over many a quaint and curious volume of forgotten lore-
While I nodded, nearly napping, suddenly there came a tapping,
As of some one gently rapping, rapping at my chamber door.
"Tis some visitor," I muttered, "tapping at my chamber door-
                          Only this and nothing more."
```


### Upload your assignment to github (as usual)

Remember to use `git` to upload your assignment!
1. In the directory that has your code repository, run `git status` to ensure the file(s) you've modified are there. If there are edits since the last commit, they will show up in red.
2. For each file you modified that you would like to submit, run `git add <name of the file you want to commit>`
3. When you've added the files you want to commit, run `git commit -m <some useful message about what you changed since the last commit>`
4. Run `git push`, followed by your username and password

As always, when you are done writing, formatting, cleaning up, and testing the living daylights out of your code, raise your hand to demo your code and verify with the professor or lab assistant that you've checked all the boxes under grading, can see your latest code in github, and you're free to go early!

## Grading
1. (1 point): Your code has your name and lab section in a comment at the top in each of `calculator.cpp`, `hms.cpp`, and `the_raven.cpp`.
2. (1 point): Your programs each compile without errors or warnings.
3. `calculator.cpp` Correctly calculates floating point quotients to at least 4 decimals of accuracy, e.g . `1 / 3 = 0.33333`
4. `calculator.cpp` Correctly calculates integer division with integer remainders printed, e.g. `3 / 2 = 1r3`.
5. `hms.cpp` passes all the test cases provided.
6. `hms.cpp` makes correct use of either `/`, `%`, or ideally, both operators (it can be done with just `/`, but `%` is highly recommended).
7. `hms.cpp` defines well-named meaningful global constants near the top of the file.
8. `the_raven.cpp` correctly stores strings with multiple lines using the correct escape sequence.
9. `the_raven.cpp` correctly renders tabs and double quotes in the string.
10. `the_raven.cpp` correctly concatenates strings into a single variable and outputs that variable.

## Hints
### cin
Just as `cout` supports printing multiple things in 1 statement, such as
```
cout << 5 << " + " << 8 << " = " << 13 << endl;
```

`cin` supports multiple inputs as well, separated by spaces:

```
int first_number;
int second_number;

// Allows the user to enter first_number followed by second_number, separated by a space.
cin >> first_number >> second_number;
```
### Arithmetic Operators
#### Order of operations
C++ arithmetic operators follow your normal PEMDAS (parenthesis, exponents, multiplication, division, addition, subtraction) order of operations, just like in algebra.

* `10 / 2 + 3 * 4 - 5` would be equivalent to `(10 / 2) + (3 * 4) - 5`, or `5 + 12 - 5` which evaluates to `12`
* `10 / (2 + 3) * (4 - 5)` would have the expressions in the parenthesis operate first, resulting in `10 / 5 * -1`, which evaluates to `-2`.

##### Division `/`
`/` has different behavior depending on the type it's being used with.
* `int / int` will produce an `int`, with decimals omitted. For example, `5 / 2` is technically 2.5, but if both 5 and 2 are represented using `int`, then the result will just be `2`
* `int / float` or `float / int` will promote the `int` to a `float`, and result in a `float`
* `float / float` will produce a `float` to some degree of accuracy representing the quotient

##### Modulo `%`
`%` is meant to be used on whole numbers such as `int` to take the remainder of the first `int` divided by the second `int` Code that attempts to use `%` on anything else will not compile.
* `5 % 2` is 1, because the remainder of 5 divided by 2 is 1.
* `2 % 5` is 2, because 2 can't divide by 5 as an `int` and 2 is left over
* `20 % 4` is 0, because 20 divided by 4 is 5 with no remainder.
* `%` works with negative numbers as well.

### Declaring constants
`int x = 5;` declares an integer and initializes it to `5`. However, as an `int`, x can be changed at any future point in the program for as long as it is still in scope (more on scope in a future lecture). What if you want x to stay the same throughout? Use the `const` keyword.

When declaring a `const`, it must be initialized as well in 1 statement.
```
const int x;

error: uninitialized const ‘x’ [-fpermissive]
   const int x;
```

Once it's been declared, it stays!
```
const int x = 5;  // Declare and initialize x to 5, which now can't be changed.
x = 6;  // Try to change it anyway.

error: assignment of read-only variable ‘x’
   x = 6;
```

Just like with variables, it's generally a good idea to name your constants for what they represent. Typically, developers use ALL_CAPS to name constants, so someone else reading/modifying the code wouldn't try to change it, only to run into compile errors.
```
const int NUMBER_OF_DAYS_PER_WEEK = 7;
const double PI = 3.14159265358979; // double is the 64-bit version of float for more precision.
```

Typically, constants are defined either in libraries or at the file-level so they can be used in a bunch of places.
```
#include <iostream>
using namespace std;

const float PI = 3.14159; // Declare a constant called PI with value 3.14159 with global scope.

int main() {
  float radius;
  cout << "Enter radius: ";
  cin >> radius;

  cout << "The area of the circle is " << PI * radius * radius << endl;
  return 0;
}
```
### `string`
#### Escape Sequences
`Hello world\n` contains what we call an "escape sequence," namely the `\n` to indicate "new line."

Common escape sequences include:
* `\n` "Newline" causes the cursor to go to the next line for subsequent printing
* `\t` "Horizontal tab" causes the cursor to skip over to the next tab stop
* `\a` "Alarm" Causes the computer to beep
* `\b` "Backspace" Causes the cursor to back up one position
* `\r` "Return" Causes the cursor to go to the beginning of the current line, not the next line
* `\\` "Backslash" Causes a backslash to be printed
* `\'` "Single quote" Causes a single quotation mark to be printed
* `\"` "Double quote" Causes a double quotation mark to be printed

#### Concatenation
strings can be combined/concatenated using the `+` operator just like with integers.

```
string first_name = "Jane"
string last_name = "Doe"
string full_name = first_name + " " + last_name; // Concatenate strings using +.
cout << "My full name is: " << full_name << endl;

> "My full name is: Jane Doe"
```
