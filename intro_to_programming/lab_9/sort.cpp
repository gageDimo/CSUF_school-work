// Michael Dimapindan CPSC 120 Section 06

#include <iostream>
using namespace std;

// TODO: Declare a const int to represent the size of the array with value 10.

  const int SIZE = 10;

// TODO: Create a function called SelectionSort that takes an array of ints
// and the number of elements in the array and sorts it in ascending order
// using the selection sort algorithm.

void SelectionSort(int array[], int size) {

  int temp; //place-holder for switching elements

  for(int i = 0; i < (size-1); i++) {
    for (int j = i+1; j < size; j++) {
      if (array[j] < array[i]) {
        temp = array[j];
        array[j] = array[i];
        array[i] = temp;
      }
    }
  }

}

int main(int argc, char* argv[]) {
  // TODO: Declare a statically-allocated array with size 10 using the const
  // int above.

  int user_array[SIZE];

  // TODO: Read up to 10 numbers from argv and store them in the array.

  for (int i = 1; i < SIZE; i++) {
    string input_i = argv[i];
    int elem_i = std::stoi(input_i);
    user_array[i] = elem_i;
  }

  // TODO: pass the array to SelectionSort and the number of elements in the
  // array.

    SelectionSort(user_array, SIZE);

  // TODO: Use a loop to print each element of the array on a single line.

    for(int i = 0; i < SIZE; i++) {
      cout << user_array[i] << " ";
    }

    cout << endl;

  return 0;
}
