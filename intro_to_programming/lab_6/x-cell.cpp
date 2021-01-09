// TODO: Include your full name and lab section.
// Michael Dimapindan CPSC 120 Section 06

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  // TODO: Ensure the user supplied exactly 2 arguments to this program.
  // Remember the name of the program counts as 1 argument, which isn't one of
  // 2 arguments. Print a message how to use this program if they didn't, and
  // bail out. If you need a refresher, refer to what you did in part 1.

  if (argc != 3) {

    cout << "Incorrect number of arguments.\n"
    << "After printing the name of the program,\n"
    << "add 2 new arguments separated by a space, then test it." << endl;

    cout << "Exiting program." << endl;
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

  // TODO: Create a while loop that prints number_of_multiples multiples of
  // base.

  int count = 0;

  while(count < number_of_multiples) {

    count = count + 1;
    int multiple = base * count;

    cout << multiple << " ";

  }

  cout << endl;

}
