# Lab 09 - Arrays
Arrays are fundamental building blocks of many data structures (clever "containers" that organize data for storage and retrieval). They are chunks of memory allocated and dedicated to storing multiple instances of a single data type, side by side, and are lightning fast to access each slot within the allotted space.

## Objectives
* Practice declaring and calling functions with various inputs and outputs.
* Understand how to declare, initialize, store, and retrieve primitive data types from statically-allocated arrays
* Understand how to traverse each element of an array
* Understand the boundaries of an array's allocated memory space and operating within those boundaries
* Understand how to pass a statically-allocated array to a function for processing
* Understand how to call functions from other functions
* Understand the use of functions to perform repeated tasks with slightly different input each time
* Understand how to break functions down into helper functions that can be reused elsewhere.
* Understand and debug potential off-by-one errors

## Part-1: `grades.cpp`
Write a program that computes stats for 5 equally-weighted assignment scores worth a maximum of 100 points each, using a function to decide each of the following:
* What is the highest score?
* What is the lowest, which would be proposed to be dropped?
* What is the overall average?
* What is the overall grade these scores would come out to, according to the criteria below?
  * 90%+ = A
  * 80% - 89.99% = B
  * 70% - 79.99% = C
  * 60% - 69.99% = D
  * < 60% = F
* If there were to be a new assignment left, and the lowest existing score were dropped, what minimum score on that new assignment would be needed for an A? B? C? D?

### 1. Get input scores and store them in an array
Read the 5 numbers as `float`s through `argv` into a statically-allocated array of `float`s with overall size 5. A statically-allocated array is one that has a predetermined fixed size and is allocated at compile time (the program has not run yet). If the user fails to supply 5 numbers, assume the scores are 0s. If the user supplies more than 5 numbers, ignore the 6th one onward.

```
#include <iostream>
using namespace std;

const int NUMBER_OF_SCORES = 5;

int main(int argc, char* argv) {
  float scores[NUMBER_OF_SCORES]; // Creates an array of fixed size 5.
}
```

Pre-populate the array `scores` with all `0`s using a function called `Initialize` which you will create (instructions how to are below). In order for `main` to understand it, it will need to be declared anywhere above `main`.
```
// ... Other code ...

// TODO: Create a void function called Initialize that takes an
// array of floats and its size, and sets each value in the array to 0.

int main(int argc, char* argv[]) {
  float scores[NUMBER_OF_SCORES];

  // TODO: Call your Initialize function with scores and the size as input.
}
```

#### What's a `void` function?
A `void` function returns no output, and instead just performs some actions. To declare a `void` function, simply specify `void` as the return type, and don't worry about using `return` to return anything (though often you may want to call `return;` to bail out early in some cases, it's not necessary here).

```
void SomeFunctionThatDoesntReturnAnything(some inputs) {
  // Do things, no need to return anything.
}
```

In our case,
```
// ... Other code ...

void Initialize(float scores[], int number_of_scores) {
  // TODO: Use a loop of some sort to go through scores[] and set each element
  // to 0. Remember in arrays, the first element starts at 0. scores[] is the
  // array that will have its elements set to 0, while number_of_scores tells
  // this function the total number of many spots exist in scores[].
}

int main(int argc, char* argv[]) {
  float scores[NUMBER_OF_SCORES];
  Initialize(scores, NUMBER_OF_SCORES);
}
```
Next, use an `if` statement involving `argc` and `NUMBER_OF_SCORES` as the cutoff point to decide too many or too few arguments were supplied. If too many, your program should ignore the values after the 5th number after the name of the program. If too few, assume 0s (which should already be taken care of by `Initialize` by this point. With the cutoff determined, use that value and a loop of some sort to read the appropriate number of values from `argv` and store each one into a spot in `scores[]`. Watch out for off-by-1 errors!
```
int main(int argc, char* argv[]) {
  float scores[NUMBER_OF_SCORES];
  Initialize(scores, NUMBER_OF_SCORES);

  // TODO: Determine how many values in argv will actually get copied.

  // TODO: Use a loop of some sort to go through argv[] and store each one in
  // a spot in scores[]. Careful of being off by 1!
}
```

### 2. GetMaximum
Write a function that takes a `float` array of `floats` that represents scores and an `int` indicating how many spots are in the `scores[]` array, identifies the highest value present, and returns it.

```
float GetMaximum(float scores[], int number_of_scores) {
  // HINT: Declare a "candidate" highest float so far. Initialize it to the
  // first element in scores[].

  // Examine what's in scores[], 1 by 1 in order by position, and determine
  // which is highest. When examining each element, check it against the
  // candidate. If higher than the candidate, then update the candidate to this
  // value.

  // By the time each element in scores[] is considered, what's left in the
  // candidate variable is the highest, and should be returned.
}
```

### 3. GetMinimum
Almost identical to `GetMaximum`, but check for smaller than the candidate rather than larger. You may copy and paste what you have in `GetMaximum` as a starting point.

### 4. CalculateTotal
Write a function called `CalculateTotal` that takes an array of `float`s and the number of elements in that array as input, adds each value up, and returns that value as a `float`. If you are stuck, refer to what you did in lab 7 when you calculated the average of numbers entered in `argv`.

### 4. CalculateAverage
Write a function called `CalculateAverage` that takes an array of `floats` and the number of elements in that array as input, and determines the average of all the numbers in it. In order to avoid re-inventing the wheel, reuse your `CalculateTotal` function by calling into it, and dividing its return value by the number of elements.

### 5. GetCutoffScoreForGrade
Write a function called `GetCutoffScoreForGrade` that takes a `char` and determines the corresponding numerical score needed for that grade as follows:
```
'A' : 90.0
'B': 80.0
'C': 70.0
'D': 60.0
```

### 6. GetGradeForScore
Write a function that does sort of the opposite of `GetCutoffScoreForGrade`, but instead takes an average score as a `float` and determines what the corresponding grade is, according to the criteria:
* Anything over 90 is an A
* Anything over 80 but below 90 is a B
* Anything over 70 but below 80 is a C
* Anything over 60 but below 70 is a D
* Anything below 60 is an F

### 7. (Optional challenge, 1 extra credit point) GetMinimumScoreForGrade
Write a function called `GetMinimumScoreForGrade` that takes an array of `float`s, the number of elements in that array, and the target grade:
1. Determine the lowest score in the array
2. If that score were to be ignored, what is the minimum score that would be needed on a hypothetical next score in order to achieve the input score?

For example, if the scores so far are 90, 90, 90, 90, and 0, the 0 would be dropped, and if another assignment were to be given, its score would have to be a 90 order for the overall score to average to an A.

Reuse as many of your other functions as possible to avoid reinventing the wheel.

Tip: Try solving this by hand first using algebra, before attempting it in code.


### Test cases
You may use any output message you like (keep it PG13) that must clearly indicate what each message represents. The output below is just for example purposes.
```
./grade 90 90 90 60 70
Average: 66
Highest score: 90
Lowest score: 0
Grade so far: D
Dropping the minimum,and replacing it with a new assignment would need the score:
  A: 110
  B: 60
  C: 10
  D: -40
```

## Part-2: Selection Sort
Often to process numerical data, sorting is needed. While there are some sophisticated sorting algorithms that are efficient, they can be challenging to implement. Instead, we will implement an algorithm that is somewhat slower, but is easy to understand.

The strategy for selection sort is effectively as follows, assuming 6 numbers need to be sorted in ascending order:
* Start with the first number, and compare it to every number that comes after it.
  * If the first number is bigger than the <i>smallest</i> number to the right, swap them. This way, the smallest number is now the first number, and that bigger number is now somewhere later in the list.
  * Otherwise (it's smaller), then the first number must be the smallest in the list, and is already in the right place!
* Repeat for the second number, third number, etc.
* The resulting numbers should now be in ascending order!

For example, sort `8 5 7 1 9 3` ascending using selection sort:
```
8 5 7 1 9 3
^     ^
Looking at 8, we find that 1 is the smallest number after it, so swap them. Note the 1 is now in the perfect spot!
```
```
1 5 7 8 9 3
  ^       ^
The next number is 5. The smallest number after it is 3, so swap them. 3 is now in the perfect spot!
```
```
1 3 7 8 9 5
    ^     ^
The next number is 7. The smallest number after it is 5, so swap them.
```
```
1 3 5 8 9 7
      ^   ^
The next number is 8. The smallest number after is 7, so swap them.
```
```
1 3 5 7 9 8
        ^ ^
The next number is 9. The smallest number after is 8, so swap them.
```
```
1 3 5 7 8 9
          ^
The next number is 9 again, but there's nothing after. We're done!
```

### Test cases
```
$./sort
$

$./sort 1
1

$./sort 1 2
1 2

$./sort 2 1
1 2

$ ./sort 1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10

$ ./sort 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10

$ ./sort 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

$ ./sort -1 5 39 6 1000 4 3 -45 0 5
.-45 -1 0 3 4 5 5 6 39 1000
```

Write a program that takes 10 `int`s via `argv`, stores them in a statically allocated array and sorts them in ascending order using the selection sort as described above.

## Grading (11 possible points of 10)
* (1 point): `part-1/grades.cpp` correctly declares an array of type `float` with size 5 and stores the required 5 input numbers from `argv`.
* (1 point): `part-1/grades.cpp` correctly implements an `Initialize` function that sets the array to all 0s, and calls it from `main`.
* (0.5 points): `part-1/grades.cpp` correctly implements the `GetMaximum` function and displays its output in `main`.
* (0.5 points): `part-1/grades.cpp` correctly implements the `GetMinimum` function and displays its output in `main`.
* (1 point): `part-1/grades.cpp` correctly implements the `GetTotal` function to sum the elements in an array of `float`s
* (1 point): `part-1/grades.cpp` correctly implements `CalculateAverage` to determine the average of the input numbers via an array of `float`s.
* (0.5 poinst): `part-1/grades.cpp` correctly implements `GetCutoffScoreForGrade`.
* (0.5 points): `part-1/grades.cpp` correctly implements `GetGradeForScore`.
* (1 point extra credit): `part-1/grades.cpp` correctly determines the necessary score for a certain grade given the initial grades and dropping the lowest.
* (0.5 point): `part-2/sort.cpp` correctly declares an array of type `int` with size 10, and reads 10 `int`s through the command line, and stores them in the array.
* (0.5 point): `part-2/sort.cpp` declares a `void` function that takes an `int` array and `int` size, and calls it from `main.`
* (3 points): `part-2/sort.cpp` correctly implements selection sort in accordance with the test cases using the algorithm described.
