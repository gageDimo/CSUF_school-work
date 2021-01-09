# Lab 07 - For loops

In addition to the `while`/`do-while` loops, C++ supports yet another type of iteration: the `for` loop. `for` loops allow for a more concise and specifically-controlled iteration style from what we've seen in `while` loops, and are particularly common when a programs need to perform iterations a specific number of times.

# Objectives
* Understand how to perform iteration using the `for` loop
* Gain familiarity with taking existing code and modifying it slightly
* Gain introductory familiarity with variable scope
* Understand using variable numbers of arguments in `argv`

# Instructions
Many parts of this lab are very similar to Lab-06, which was achieved using `while` loops. In this lab, you will re-implement parts of Lab-06, but using `for` loops instead.

## `part-1/countdown.cpp`
Re-implement `countdown.cpp` from lab-06, but this time using a `for` loop to count down instead of a `while` loop. You may copy and paste what you submitted in lab-06 as a starting point if you prefer.

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
Re-implement `x-cell.cpp` from lab-06, but this time using a `for` loop to print the multiples instead of a `while` loop. You may copy and paste what you submitted in lab-06 as a starting point.

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

## `part-3/prank_twitter.cpp`
Re-implement `twitter.cpp` from lab-06, but this time using `for` loops instead of `while` loops. You may copy and paste what you submitted in lab-06 as a starting point.

However, as an early April fools prank, twitter has decided it would keep overly active tweeters from over tweeting, and the best way to accomplish this would be by previewing their tweets backwards. Your tweet preview should implement this feature, and only print the <i>last</i> 140 characters (excluding `\0`).

### Test cases
```
part-3$ ./prank_twitter
Enter your tweet: Despite the constant negative press covfefe
Your tweet uses 43 characters.
Preview:
    efefvoc sserp evitagen tnatsnoc eht etipseD

part-3$ ./prank_twitter
Enter your tweet: Once upon a midnight dreary, while I pondered, weak and weary, Over many a quiant and curious volume of forgotten lore - While I nodded, nearly napping, suddenly there came a tapping, As of some one gently rapping, rapping at my chamber door.
Your tweet is 102 characters too long!
Preview:
    .rood rebmahc ym ta gnippar ,gnippar yltneg eno emos fo sA ,gnippat a emac ereht ylneddus ,gnippan ylraen ,deddon I elihW - erol nettogrof f


part-3$ ./prank_twitter
Enter your tweet:
Your tweet uses 0 characters.
Preview:
```

## `part-4/pyramid.cpp`
Re-implement `pyramid.cpp` using 2 nested `for` loops instead of `while` loops. You may copy and paste what you had submitted in part-5 of lab-06 as a starting point.

```
part-4$ ./pyramid
Usage: To print a pyramid, specify the number of levels you would like.

part-4$ ./pyramid -1

part-4$ ./pyramid 0

part-4$ ./pyramid 1
*

part-4$ ./pyramid 2
*
**

part-4$ ./pyramid 5
*
**
***
****
*****
```

## `part-5/average.cpp`
The average of numbers is the sum of all the numbers divided by the total number of numbers. For example, the average of 8 and 10 is (8 + 10) / 2, which comes out to 9. Implement a program to read any number of floating-point numbers via the command line, and print the average of all of them.

## Test cases
```
part-5$./average 0
0

part-5$./average 0 1
0.5

part-5$./average 1 2 3
2

part-5$./average 10 10 10 9
9.75
```

# Hints
## The `for` loop
```
for (initialization; condition; increment) {
  // Statements to iterate on.
}
```
For example, to print the numbers from 1 through 5 in ascending order,
```
for (int i = 1; i <= 5; i ++) { // Increment i after each iteration of the body.
  cout << i << " ";
}
```

Note in the above case due to the <b>scope</b> of the local variable `i` being created inside the `for` loop declaration, `i` can only be used within the `for` loop. After the `for` loop is done executing, `i` is gone!
```
for (int i = 0; i < 1; i ++) {
  // Do stuff.
}
cout << i;

> error: use of undeclared identifier 'i'
```

If you still want to use `i` for anything after the `for` loop is done, you would have to declare it beforehand as follows:

```
int i; // Declare the existence of i beforehand.
for (i = 5; i > 1; i --) { // Decrement the existing variable i after each iteration of the body.
  // Do stuff.
}
cout << i; // i still exists so can continue to be used.

> 2
```
This way, the scope of `i` is local to the part of the code that creates the `for` loop.

## Reading `float` from the command line.
Just as you have used `std::stoi()` to convert a `string` into an `int`, an existing function exists to convert a `string` to `float`, using `std::stof`.

For example,
```
string some_string_containing_a_float = "3.14"; // The word "3.14"
float the_actual_float = stof(some_string_containing_a_float); // 3.14 as a float.
```

For complete reference to `string` and what it can do, refer to http://www.cplusplus.com/reference/string/
# Grading
1. (1 point): `part-1/countdown.cpp` uses a `for` loop to count down backwards from the user-specified number in the command line.
2. (1 point): `part-1/countdown.cpp` passes all test cases.
3. (1 point): `part-2/x-cell.cpp` uses a `for` loop to iterate over the number of multiples to print.
4. (1 point): `part-2/x-cell.cpp` passes all test cases.
5. (1 point): `part-3/prank_twitter.cpp` uses a `for` loop to determine the length of the string.
6. (1 point): `part-3/prank_twitter.cpp` uses a `for` loop to print the appropriate preview, backwards, of the tweet in accordance with the test cases.
7. (1 point): `part-4/pyramid.cpp` uses 2 nested `for` loops to print the pyramid.
8. (1 point): `part-4/pyramid.cpp` passes all test cases.
9. (1 point): `part-5/average.cpp` uses a `for` loop to parse `argv` for the numbers to average
10. (1 point): `part-5/average.cpp` passes all test cases.
