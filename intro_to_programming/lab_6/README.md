# Lab 06 - While loops
Doing things over and over are what computers are good at. In this lab we will be implementing several small programs that make the computer perform repeated tasks using only a few lines of code, namely the `while` loop.

# Objective
* Understand how to perform iteration using the `while` and `do-while` statements
* Understand program flow and variable state within loops
* Gain deeper familiarity with the underlying data of `string`
* Gain familiarity with how to use the `char` data type

# Instructions
At this point in the course, you should all be intimately familiar with the terminal, how to use `git` to download your assignment and upload your changes, `cd` to change directories, using `g++ -o` to name your programs, and how to use atom. If you need refreshers on any of these, refer to the previous lab instructions.

As always, snark and sass in output messages are entertaining, but please keep it PG-13.

## `part-1/countdown.cpp`
Elon M's gas-powered countdown machine is broken and he wants a new electric one so he can test his rockets at SpaceY. He has asked his buddy Larry P to make him one, but Larry hasn't coded in a while though. Larry has proposed if anyone can solve it, they can have a job at his newest tech startup Googal (that happens to be disrupting the countdown industry).

Larry has specified the following:
1. Your code must include your full name and lab section so he knows where to send your offer letter.
2. Your code must accept the countdown as an `int` through the command line.
3. Your code must check that the user provided said `int` via the command line (but don't worry about passing `strings` or `floats`) and make it clear that's what is expected if the user doesn't.
4. Your code must check that the provided `int` can be counted down from, aka > 0, and outputs a message when it's not.
4. Your code must use a 1-second delay between printing the countdown seconds. Thankfully Larry is only kinda rusty so at least he got that part working by himself.

### Test cases
```
part-1$ ./countdown 3
3...
2...
1...
0...
LIFTOFF!

part-1$ ./countdown
Houston, we have a problem... countdown expects an argument.
Elon won't be happy with this...

part-1$ ./countdown -1
No. I refuse.

```

## `part-2/x-cell.cpp`
Billy G, founder of Nanosoft, is designing a new piece of revolutionary software called x-cell. x-cell is supposed to be good at printing multiples of numbers, but Billy is stuck getting it to work. Help him finish his code! Nanosoft might be worth a lot someday...

Billy is trying to get it to:
1. Ensure his program takes 2 numbers, and outputs a help message if it doesn't get the right number of arguments.
2. Read the first number as the number of multiples to compute.
3. Read the second number as the number to get multiplied (called the base).
4. Use a while loop to print the multiples of the base. For example, passing 5 and 2 causes 5 multiples of 2 to be printed as 2 4 6 8 10.

### Test cases
```
part-2$ ./x-cell 5 2
2 4 6 8 10

part-2$ ./x-cell 3 1
1 2 3

part-2$ ./x-cell 4 0
0 0 0 0

part-2$ ./x-cell 6 5
5 10 15 20 25 30

part-2$ ./x-cell 0 0

part-2$ ./x-cell -1 4
BSOD! You need to supply a positive number of times to multiply the thing by.

part-2$ ./x-cell
IBM is not impressed that you forgot to supply 2 arguments.
Usage: ./x-cell <number of multiples> <number to be multiplied>
```

## `part-3/twitter.cpp`
Twitter enforces a 140 character limit on all tweets. Anything longer than 140 is fake news and gets truncated. Prompt the user for a tweet and print a preview that will show the tweet with the 140 character limit imposed.

Note the last special character in every string '\0' (called the null-terminator), which indicates the end of the string, is not counted towards the user's limit.

### Test cases
```
part-3$ ./twitter
Enter your tweet: Despite the constant negative press covfefe
Your tweet uses 43 characters.
Preview:
    Despite the constant negative press covfefe

part-3$ ./twitter
Enter your tweet: Once upon a midnight dreary, while I pondered, weak and weary, Over many a quiant and curious volume of forgotten lore - While I nodded, nearly napping, suddenly there came a tapping, As of some one gentrly rapping, rapping at my chamber door.
Your tweet is 103 characters too long!
Preview:
    Once upon a midnight dreary, while I pondered, weak and weary, Over many a quiant and curious volume of forgotten lore - While I nodded, nea

part-3$ ./twitter
Enter your tweet:
Your tweet uses 0 characters.
Preview:
```

## `part-4/enter_pin.cpp`
An Automated Teller Machine (ATM) is a kiosk at a bank that lets you deposit or withdrawal money from your bank account without needing to talk to a bank representative. When you use an ATM, you need to swipe your debit card and enter a Personal Identification Number (PIN) so someone can't just steal your card, pretend to be you, and take all your money.

Sometimes it's easy to type in the wrong number, and the ATM would let you keep trying, but up to a limit. After too many attempts, to protect from someone trying to guess your PIN, it kicks you out.

Use a `do-while` loop and a lot of yelling to prompt the user for the correct PIN until they get it right, or until they get it wrong 3 times.

### Test cases
1. Get it right the first time. Ensure the program prints a message as such and stops.
2. Get it wrong the first time. Ensure the program prints a message that it's wrong, but allows the user to try again.
3. Get it wrong the first time, then right the second time. Ensure the program prints each attempt as wrong or right and stops after the right attempt.
4. Get it wrong 3x in a row. Ensure the program prints as such that the maximum number of attempts has been reached, and disallows any more tries.

## `part-5/pyramid.cpp`
Write a program that prints a pyramid (more like a triangle) of a repeated character such as `*`. You may hard-code any character you wish using `char`.

1. Ensure the user provides the right number of arguments to the program, and yell at them if they don't follow the rules and bail out.
2. Print the number of rows the user specified. For example, if the user specified 3, then there should be 3 rows printed.
3. In each row, print the number of characters corresponding to that row. For example, if the user specified 3, then the first row should have 1 character, the 2nd row should have 2, and the 3rd row should have 3.

### Test cases
```
part-5$ ./pyramid
Usage: To print a pyramid, specify the number of levels you would like.

part-5$ ./pyramid -1

part-5$ ./pyramid 0

part-5$ ./pyramid 1
*

part-5$ ./pyramid 2
*
**

part-5$ ./pyramid 5
*
**
***
****
*****
```

# Hints
## Halp, my program won't stop!
Likely your code is in an infinite loop. In the terminal window, type `ctrl+c` (hold down the `ctrl` key and press `c`). This sends a signal to the program to stop (and works for a lot of other stuff too, not just our programs). If it's really bricked you may have to try a few times or try closing the terminal and re-opening it, but that shouldn't be necessary.

If your loop is running forever, check your code:
1. Is my condition for the while loop actually checking what I think it is?
2. Am I forgetting to do something to make the condition eventually `false` such as incrementing something?

## The `while` loop

The syntax for a while loop is similar to the `if` statement, but unlike the `if` statement, the instructions inside `{}` will execute repeatedly until until <i>condition</i> evaluates to `false`. Should <i>condition</i> evaluate to `false` from the get-go, the statements inside will never execute.

Think "check first, then do."
```
while (<condition>) {
  // Do things. Don't forget to update state variables if needed or you might
  // run into an infinite loop!
}

// Statements continue after while loop is done.
```

For example, printing the numbers 0 - 4:
```
int i = 0;
while (i < 5) {
  cout << i << " ";
  i = i + 1;  // Careful! If something doesn't change or the condition is wrong,
              // the loop could go forever!
}
```
```
> 0 1 2 3 4
```

An example where the statements never execute, because the condition in the `while` statement are `false` to begin with.
```
int i = 3;
while (i == 4) { // Nope, i is 3.
  i = i + 1;  // Not happening.
}
cout << i;  // Still 3!
```
```
> 3
```

## The `do-while` loop
Like the `while` loop, the statements inside `{}` will get executed until the condition supplied to `while` becomes `false`. However, the difference is `do` will cause the contents always to execute <i>at least once</i>.

Think "do first, ask questions later."

```
do {
  // Statements to do that will happen at least once.
} while (<condition>); // <-- don't forget the ;
```

For example,
```
string expected_password = "Googal";
string password;

do {
  cout << "Enter your password: ";
  cin >> password;

  if (password == expected_password) {
    cout << "Access granted." << endl;
  }
  else {
    cout << "DENIED!" << endl;
  }
} while (password != expected_password);
```
```
$ ./a.out
Enter your password: Nanosoft
DENIED!
Enter your password: Facepad
DENIED!
Enter your password: Apul
DENIED!
Enter your password: Netflicks
DENIED!
Enter your password: Googal
Access granted.
```

## Read a whole line using `getline` and `cin`
`cin` can only read 1 word at a time, meaning spaces will cause only the first word to be read if using `cin` directly. To read an entire line including the spaces (until the enter key is pressed), use `std::getline()`.

```
#include <iostream>
using namespace std;

int main() {
  string line_to_read;
  getline(cin, line_to_read);  // Prompts the user for a whole line until enter
                               // is pressed and stores the input in
                               // line_to_read.
}
```

## `char`
A character is its own type called `char`. It can be a letter, a number, or a symbol.
```
char some_letter = 'r'; // Single quotes!
```

Each `char` in C++ corresponds to a number as defined by the American Standard Code for Information Interchange (ASCII, http://www.asciitable.com/. For example, `'a'` has ASCII value 97.

## Null character
The character with ASCII value 0 is a special one, used to signify "nothing" called "null" in C++.

Null is used to signify the end of a `string` 's characters and can be declared using:
```
char c = '\0';
```

Note the use of `\` before `0` to signify it's the character with ASCII value 0, and not the character ``'0'`` that represent the number 0 which has ASCII value 48.

## `string`
A `string` represents words and sentences. Somewhere inside, a `string` manages data that holds the actual string of characters (`char`s) of the string.

```
"Hello, world!"

0  1  2  3  4  5  6  7  8  9  10 11 12 13
H  e  l  l  o  ,     W  o  r  l  d  !  \0
```
Each string always ends with a null "terminator" to signify the end of the string. Even this character takes up storage space, it doesn't count in terms of how many characters are considered in the length of the string.

A `string` allows you to access each character to be read or written to using `[]` and specifying the position, such as 0 (the first character) or 1 (the second character), you would like to read or write to. Using the example above,
```
string hello_world = "Hello, world!";
char first_character = hello_world[0];
cout << first_character;

> H
```
We will cover details about why the index starts counting from 0 instead of the more intuitive 1 when we discuss arrays in a future lecture and lab.

Using the index and searching for `\0` can help determine the number of actual characters in the string.


# Grading
Code that does not compile will receive a 0 on the file that fails to compile. Code submitted without a full name and lab section are impossible to grade and will also receive a 0 for the file missing the information.

* (1 point): `part-1/countdown.cpp` counts down backwards from a positive number using a while loop and stops at 0, including 0.
* (0.5 points): `part-1/countdown.cpp` reads the number to count down from through the command line.
* (0.5 points): `part-1/countdown.cpp` checks that the user supplies a positive integer to count down from and bails out with a usage message otherwise.
* (0.5 points): `part-2/multiples.cpp` uses a while loop to print multiples of a number.
* (0.5 points): `part-2/multiples.cpp` checks that the user supplies a positive number of multiples to print and the right number of arguments.
* (1 point): `part-2/multiples.cpp` passes all the test cases.
* (0.5 point): `part-3/twitter.cpp` uses `getline` correctly to read the tweet through a prompt.
* (0.5 point): `part-3/twitter.cpp` correctly determines whether the tweet is within character limit, excluding the null character, using a while loop.
* (1 point): `part-3/twitter.cpp` correctly displays the preview text using a while loop for all test cases.
* (1 point): `part-4/enter_pin.cpp` uses a do-while loop to prompt the user for their PIN.
* (0.5 points): `part-4/enter_pin.cpp` correctly determines whether the user has hit the attempts limit and disallows further attempts.
* (0.5 points): `part-4/enter-pin.cpp` correctly determines whether the user has entered the correct pin, and stops prompting.
* (0.5 points): `part-5/pyramid.cpp` checks that the user supplied at least 1 argument to represent the height of the pyramid.
* (0.5 points): `part-5/pyramid.cpp` declares the symbol that will be printed using `char`.
* (1 point): `part-5/pyramid.cpp` uses 2 while loops (1 nested inside the other) to pass all the test cases.
