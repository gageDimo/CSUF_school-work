# Lab 12
Arrays are fast and versatile, but pose many challenges if you're not careful. What if you carve out an array, but later discover you need to put more things in it than there's room for? Without knowledge of dynamic memory management (where you can request and release memory on demand), there isn't much we can do with what we know so far. Dynamic memory management will be covered in CPSC 121.

In the meantime, introducing `std::vector`! A vector is a data structure that manages an array underneath so that you don't have to, and supports a bunch of goodies such as asking for how many things are inside, adding things, removing things, and many many more.


## Objectives
* To gain introductory familiarity with `std::vector` and its basic supported operations
  * `push_back()`
  * `at()`
  * `size()`
* To gain introductory familiarity with C++ containers to store, retrieve, and process data

## Instructions
In this lab you will implement a simple program using `std::vector` to identify low scores from a stream of scores and print them.

### Test Cases
```
$./a.out
The highest score is: 0
The lowest score is: 0

$./a.out 1
The highest score is: 1
The lowest score is: 1
Scores that can use improvement: 1

$./a.out 100
The highest score is: 100
The lowest score is: 100

$./a.out 100 90 80 70 60 50 40 30 20 10
The highest score is: 100
The lowest score is: 10
Scores that can use improvement: 50 40 30 20 10

$./a.out 100 100 100
The highest score is: 100
The lowest score is: 100
```

## Grading
1. (1 point): `grades.cpp` includes the correct directive at or near the top of the file.
2. (1 point): `grades.cpp` code correctly declares a vector
3. (1 point): `grades.cpp` code correctly populates your vector with the arguments from `argv`
4. (1 point): `grades.cpp` correctly identifies the minimum value in the vector
5. (1 point): `grades.cpp` correctly identifies the maximum value in the vector
6. (1 point): `grades.cpp` correctly determines the grade that the average values of the vector represent.
7. (1 point): `grades.cpp` makes use of the `.size()` function to iterate through the vector
8. (1 point): `grades.cpp` makes use of `.at()` to retrieve elements of the vector
9. (2 points): `grades.cpp` passes all the test cases

## Hints
In order to use a vector, you must include the directive for it somewhere before main:
```
#include <vector>  // Tells your code about vectors so you can use them.
...

int main(int argc, char* argv[]) {
  ...
}
```

Once you've included the vector directive, you can declare a vector by specifying the type of the contents between `<>`. Below are several examples of vectors with various types:
```
int main(int argc, char* argv[]) {
  vector<int> numbers; // Declares a vector of type int.

  vector<char> characters; // Declares a vector of type char.

  vector<string> words; // Declares a vector of type string.

  vector<float> scores; // Declares a vector of type float called scores.
}
```

You can add things to the end of vectors using the `push_back()` function.
```
vector<float> v;
v.push_back(3.0); // v now has {3.0}.
v.push_back(4.0); // v now has {3.0, 4.0}.
```

You can also ask a vector how many things it has inside using the `.size()` function:
```
vector<int> v;  // v starts out empty.
cout << v.size();

> 0

v.push_back(4); // Add 4 in, so v is now {4}.
cout << v.size();

> 1

v.push_back(12); // Add 12 in, so v is now {4, 12}.
v.push_back(3);  // Add 3 in, so v is now {4, 12, 3}.
cout << v.size();

> 3
```

You can access elements in a vector either using array-style syntax, `[]`, or using the `.at()` function. `.at()` is nice enough to tell you when you've gone out of bounds of the array, whereas `[]` may or may not just crash with a segmentation fault (trying to access memory way out of bounds that belongs to another program). Like arrays, vectors start from 0!
```
vector<string> days_of_the_week;
words.push_back("Sunday");
words.push_back("Monday");
words.push_back("Tuesday");
words.push_back("Wednesday");
words.push_back("Thursday");
words.push_back("Friday");
words.push_back("Saturday");

cout << words.at(2);

> "Tuesday"

cout << words.at(58394); // Way out of bounds.

> terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 58394) >= this->size() (which is 7)
Aborted (core dumped)
```

Vectors support both pass by reference (just pointing to the original vector), and pass by value (passing a copy of the original). We will only be concerned with passing by value for this assignment. In order to pass a vector to a function, declare it in the parameters as follows:
```
void Print(vector<float> v) { // Passes a vector by value (v will be a copy).
  // ...
}
```

To return a vector from a function, you need to specify both that the return type is a vector, and the type of vector. For example,
```
vector<int> ReturnAVector() {
  vector<int> v;
  return v;
}
```
Creates and returns a vector of type `int`.

For further reading about vectors, refer to http://www.cplusplus.com/reference/vector/vector/.
