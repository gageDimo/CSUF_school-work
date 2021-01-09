// Michael Dimapindan CPSC 120 Section 6

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main(int argc, char* argv[]) {
  // TODO: Ensure the user supplied the correct number of arguments. Print a
  // help message if the user gets it wrong and bail out.

  if(argc != 2) {

    cout << "Incorrect number of arguments. Exiting program." << endl;
    return 0;

  }

  string secInput = argv[1];

  // TODO: Extract the number of seconds to count down from the command line as
  // an int.

  int seconds = std::stoi(secInput);

  // TODO: Yell at the user if the number of seconds is invalid (e.g. 0 or
  // negative) and bail out.

  if (seconds <= 0) {

    cout << "Error: enter a number greater than 0. Exiting program." << endl;
    return 0;

  }

  // TODO: Use a for loop to count down from the number of seconds specified
  // and print the countdown. See Hints for how to make a for loop.

  for (int i = seconds; i >= 0; i--) {

    cout << i << "..." << endl;
    this_thread::sleep_for(chrono::seconds(1));

  }

  cout << "LIFTOFF!" << endl;

}
