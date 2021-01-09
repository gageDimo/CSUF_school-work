// Michael Dimapindan, Section 06, CSPC 120

#include <iostream>
using namespace std;

int main() {
  int first_number;
  int second_number;

  // TODO: Prompt the user for first_number and second_number in a single
  // command, separated by a space. See Hints in README.md for how to do this.
  cout << "Enter two integers, separated by a space: ";

  cin >> first_number;
  cin >> second_number;

  // TODO: Initialize sum using first_number and second_number instead of 12345.
  int sum = first_number + second_number;

  // TODO: Initialize difference using first_number and second_number instead
  // of 12345.
  int difference = first_number - second_number;

  // TODO: Initialize product busing first_number and second_number instead of
  // 12345.
  int product = first_number * second_number;

  // TODO: Declare 'quotient' as a float and initialize it using first_number,
  // second_number, the division sign (/), and type casting. Treat first_number
  // as the numerator (number that goes on top of division), and second_number
  // as the denominator (number that goes on the bottom of division). To get it
  // to work properly, either one or both of the ints should be type casted to a
  // float.

  float quotient;
  quotient = float(first_number) / second_number;

  // TODO: Declare 'remainder' as an int and initialize it using first_number,
  // second_number, and the modulo operator (%).

  int remainder = first_number % second_number;

  cout << first_number << " + " << second_number << " = " << sum << endl;
  cout << first_number << " - " << second_number << " = " << difference << endl;
  cout << first_number << " * " << second_number << " = " << product << endl
       << endl;

  // TODO: Output the float version of quotient of first_number divided by
  // second_number, accurate to a few decimal places.
  // For example, 1 / 3 = 0.333333. Follow the cout pattern above.

  cout << first_number << " / " << second_number << " = " << quotient << endl;

  // TODO: Output a "pretty" version of the first number divided by the second,
  // with a remainder. For example, "3 / 3 = 1r0", "3 / 2 = 1r1". Follow the
  // cout pattern above.

  cout << first_number << " / " << second_number << " = " << int(quotient) << "r"
       << remainder << endl;

}
