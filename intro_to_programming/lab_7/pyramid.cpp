// Michael Dimapindan CPSC 120 Section 6

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  // TODO: Ensure the user supplied the right number of arguments (at least 1)
  // and print a message how to use this program if they get it wrong. The first
  // argument after the program name will represent the height of the pyramid.
  // OPTIONAL CHALLENGE: Allow the user to specify any symbol they want as a
  // char through the command line as the second argument.

  if (argc != 2) {

    cout << "Incorrect number of arguments.\nPlease enter the height" <<
    " after typing the filename." << "\nExiting program." << endl;

    return 0;

  }

  // TODO: Read the height of the pyramid through the command line.

  string heightInput = argv[1];
  int height = std::stoi(heightInput);

  // TODO: Declare the symbol that will be printed as a char (ignore this if
  // going for the optional challenge).

    char symbol = '*';

  // TODO: Use a nested for loop to print each level of the pyramid.

  for(int row = 0; row < height; row++) {

    for(int rowDigit = 0; rowDigit <= row; rowDigit++) {

      cout << symbol << " ";

    }

    cout << endl;

  }

}
