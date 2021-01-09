// TODO: Include your full name and lab section.
// Michael Dimapindan CPSC 120 Section 06

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main(int argc, char* argv[]) {
  // TODO: Ensure the user supplied the correct number of arguments. If you need
  // a refresher, refer to what you did in lab04. Print a help message if the
  // user gets it wrong and bail out like you did in lab05.

  string inputSec = argv[1];

  if(argc != 2) {

    cout << "Incorrect number of arguments. Exiting program." << endl;
    return 0;

  }

  // TODO: Extract the number of seconds to count down from the command line as
  // an int. If you need a refresher, refer to what you did in lab04.

  int secAmount = std::stoi(inputSec);

  // TODO: Yell at the user if the number of seconds is invalid (e.g. 0 or
  // negative) and bail out.

  if(secAmount < 1) {

    cout << "Invalid amount of seconds. Exiting program." << endl;
    return 0;

  }

  // TODO: Use a while loop to count down from the number of seconds specified
  // and print the countdown. See Hints for how to make a while loop.

  cout << "Starting countdown...\n";

  while(secAmount >= 0) {

    cout << secAmount << "..." << endl;
    --secAmount;

    this_thread::sleep_for(chrono::seconds(1));

  }

  cout << "LIFTOFF!" << endl;

  // TODO: Use the following line somewhere in your while loop to create a
  // 1-second delay between printing the countdown number.
  //this_thread::sleep_for(chrono::seconds(1));
}
