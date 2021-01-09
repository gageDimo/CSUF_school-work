//Michael Dimapindan CPSC 120 Section 6
// TODO: Replace this comment with your full name and lab section

#include <iostream>
using namespace std;

// TODO: Declare global constants here using const int. Name them appropriately,
// and using all upper case letters.

const int HRS_PER_DAY = 24;
const int MIN_PER_HR = 60;
const int SEC_PER_MIN = 60;

int main() {
  // TODO: Prompt the user for an integer (at least 0) to represent the total
  // number of seconds to convert into days, hours, minutes, seconds.

  int seconds;

  cout << "Enter the number of seconds you want to calculate to days, hours, "
       << "and minutes." << endl;
  cin >> seconds;

  // The starting total seconds has days, hours, minutes, and seconds all
  // bundled together into a bunch of seconds.
  // TODO: Deconstruct the total number of seconds into its days, hours, minutes
  // and seconds.

  // HINT: To get the number of days, divide the total seconds by the number of
  // seconds there are in a day. Keep track of the remainder! What's left can be
  // broken down further into hours, minutes, seconds.

  int days = seconds / SEC_PER_MIN / MIN_PER_HR / HRS_PER_DAY;

  // HINT: To get the number of hours, divide the remaining part from above by
  // the number of seconds there are in an an hour. Keep track of the remainder,
  // which can be broken down further into minutes and seconds.

  int hours = seconds / SEC_PER_MIN / MIN_PER_HR % 24;

  // HINT: To get the number of of minutes, divide the remaining part from above
  // by the number of seconds in a minute. Keep track of the remainder!

  int minutes = seconds / SEC_PER_MIN % 60;

  // HINT: What's left from above is your number of seconds.

  int secondsLeft = seconds % 60;

  // TODO: Display the result in a the format "n days h:m:s". For example,
  // "3 days 4:2:45" or "0 days 3:0:0". Don't worry about "day" vs "days," just
  // use "days"

  cout << days << " days " << hours << ":" << minutes << ":" << secondsLeft
       << endl;

  return 0;
}
