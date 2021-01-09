//Michael Dimapindan CPSC 120 Section 06

#include <iostream>
using namespace std;

/*
* No parking anytime Monday
* No parking 9am - 5pm Tuesday
* No parking 8pm - 11pm except Sunday
*/
int main(int argc, char* argv[]) {
    // TODO: Check for exactly 3 arguments, which will correspond to the name
    // of the program, the day of week specified, and the time of day specified.
    // Exit if there aren't exactly 3 arguments. see the Hints section of the
    // instructions for how to do this, using a return statement to exit.

    string dayInput = argv[1];
    string timeInput = argv[2];

    if(argc != 3) {

      cout << "Incorrect number of arguments. Exiting program." << endl;
      return 0;

  }

    // TODO: Extract the day of week from the command line. Asusme it begins
    // with a capital letter, such as "Monday". "monday" would be considered
    // invalid. Check that it is either Monday, Tuesday, Wednesday, Thursday,
    // Friday, Saturday, or Sunday. Anything else would be considered invalid,
    // such as "tuesday" or "moose".

    string Mon = "Monday";
    string Tue = "Tuesday";
    string Wed = "Wednesday";
    string Thu = "Thursday";
    string Fri = "Friday";
    string Sat = "Saturday";
    string Sun = "Sunday";

    // TODO: If the day of week is invalid, yell at the user with a sassy
    // message and exit the program with a return statement.

    if (dayInput != Mon && dayInput != Tue && dayInput != Wed && dayInput != Thu
      && dayInput != Fri && dayInput != Sat && dayInput != Sun) {

      cout << "Invalid day chosen. Exiting program." << endl;
      return 0;

    }

    // TODO: Extract the time of day specified. Assume it's an integer, so
    // convert it using stoi like you did in Lab04 (no "moose" or -3.45).

    int timeOfDay = std::stoi(timeInput);

    // TODO: Check the time of day is "valid" military time. Checking "valid"
    // military time is trickier than it sounds! For example, 199 would mean
    // 1:99am which is fake news. Full credit will be given for just checking
    // it's between 0 and 2359, and assume the user won't use numbers like 199.
    // Exit the program with a return statement should the time be invalid, like
    // 6002. OPTIONAL CHALLENGE: how would you detect true invalid military time
    // like 199 or 1386?

    if(timeOfDay < 0 || timeOfDay > 2359) {

      cout << "Invalid time chosen. Exiting program." << endl;
      return 0;

    }

    int timeCheck = timeOfDay % 100;

    if (timeCheck >= 60) {

      cout << "Invalid time chosen. Exiting program." << endl;
      return 0;

    }

    // TODO: Print whether parking at the user-specified time is allowed
    // according to the 3 rules in the instructions. All conditions must be met
    // in order for the user to be allowed to park. For example, Tuesday 2100
    // (9pm) is not allowed because of the 3rd condition.

    if(dayInput == Mon) {

      cout << "No parking anytime on Monday." << endl;
      return 0;

    }
    else if(dayInput == Tue && timeOfDay >= 900 && timeOfDay < 1700) {

      cout << "No parking on Tuesday from 9am - 5pm." << endl;
      return 0;

    }
    else if(dayInput != Sun && timeOfDay >= 2000 && timeOfDay <= 2300) {

      cout << "No parking from 8pm - 11pm except Sunday." << endl;
      return 0;

    }
    else
      cout << "Your parking is valid. Enjoy your day." << endl;
      return 0;

}
