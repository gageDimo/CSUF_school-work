// TODO: Include your name and lab section.
// Michael Dimapindan CPSC 120 Section 06

#include <iostream>
using namespace std;

// TODO: Declare a const int to represent the user's 4-digit PIN (personal
// identification number). Remember to use all caps for const stuff.

  const int PIN_DIGIT_NUM = 6463;

// TODO: Declare a const int to represent the maximum number of tries.

  const int NUM_OF_TRIES = 3;

int main() {
  // TODO: Using a do-while loop, prompt the user for their PIN using cin. Limit
  // the times the do-while loop runs to the maximum number of tries.

  int failAttempt = NUM_OF_TRIES;

  do {

    int pinTrial;

    cout << "Please enter your user PIN number:" << endl;
    cin >> pinTrial;


  // TODO: Check it against the expected PIN you declared in your const int.

  // TODO: Laud the user for getting it right within the 3 attempts and quit
  // the loop.

  // TODO: Make it clear to the user when they get it wrong, and print that they
  // are getting kicked out when they get it wrong too many times.

  if(pinTrial != PIN_DIGIT_NUM) {

    failAttempt--;
    cout << "Your input is incorrect. You have " << failAttempt << " attempts "
    << "remaining. Please be more careful." << endl;

  }
  else {

    cout << "You have correctly inputted your PIN number. Great job!" << endl;
    return 0;

  }

}
while(failAttempt > 0);

  cout << "You have run out of attempts. Exiting program." << endl;
  return 0;

}
