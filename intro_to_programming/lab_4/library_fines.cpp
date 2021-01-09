// TODO: Include your full name and section number.
// Michael Dimapindan CPSC 120 Section 06

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  // TODO: extract the number of days late from argv, which comes in as a
  // string. Turn it into an int to represent the number of late days using the
  // hints in the lab assignment.

  string daysLateInput;
  daysLateInput = argv[1];

  int daysLateNum = std::stoi(daysLateInput);

  const float PENALTY_FINE = 0.25;

  // TODO: Determine the type of late message that is printed and the fine that
  // is owed using an if, else if, and else. HINT: The order of if, else if, and
  // can be done in numerous ways, each manipulating the logic differently to
  // achieve the same result. With what we've learned in class so far, try
  // starting with checking the longest overdue period branch first and working
  // your way down for the most clear and concise code.

  if(daysLateNum >= 90) {

    cout << "Your book is assumed lost.\nThis is a bill for replacement\n"
            "The fine you owe is $90." << endl;

  }

  else if(daysLateNum <= 89 && daysLateNum >= 60) {

    cout << "Your book is overdue!\nThis is your third overdue notice.\n"
            "The fine you owe is: $" << daysLateNum * PENALTY_FINE << "."
            << endl;

  }

  else if(daysLateNum <= 59 && daysLateNum >= 30) {

    cout << "Your book is overdue!\nThis is your second overdue notice.\n"
            "The fine you owe is: $" << daysLateNum * PENALTY_FINE << "."
            << endl;

  }

  else if(daysLateNum <= 29 && daysLateNum >= 1) {

    cout << "Your book is overdue!\nThis is your first overdue notice.\n"
            "The fine you owe is: $" << daysLateNum * PENALTY_FINE << "."
            << endl;

  }

  else

    cout << "Your book was returned on time!\nNo fine." << endl;

}
