// Michael Dimapindan CPSC 120 Section 6

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  // TODO: Ensure the user supplied the 2 expected arguments to the program.
  // Output a message on how to use the program if not and bail out.

  if (argc != 3) {

    cout << "Incorrect number of arguments. Exiting program." << endl;
    return 0;

  }

  string multInput = argv[1];
  string valInput = argv[2];

  // TODO: Extract the number of multiples to print from the command line. The
  // first number represents the number of multiples to print, and the second
  // number is the base number that gets multiplied. Name them
  // number_of_multiples and base respectively.

  int number_of_multiples = std::stoi(multInput);
  int base = std::stoi(valInput);

  // TODO: Ensure the number_of_multiples is not negative. If it is, yell at the
  // user and bail out.

  if(number_of_multiples < 0) {

    cout << "Incorrect number of multiples input. Exiting program." << endl;
    return 0;

  }

  // TODO: Create a for loop that prints number_of_multiples multiples of
  // base.

  for (int count = 0; count < number_of_multiples; count++) {

    int multiple = base*count;
    cout << multiple << " ";

  }

  cout << endl;

}
