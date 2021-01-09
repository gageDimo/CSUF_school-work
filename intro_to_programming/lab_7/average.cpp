// Michael Dimapindan CPSC 120 Section 6

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  // TODO: Declare a float that will eventually hold the sum of all the values.
  // Initialize it to 0 so you can add to it as the numbers come in.

  float sumVal = 0;

  // TODO: Create a for loop to read each argument in argv. Remember the name of
  // the program is in argv too, so watch out where your loop starts.

  for(int i = 1; i < argc; i++) {

    // TODO: Within your loop, convert each argument to a float.
    // TODO: Add each float to the running sum.

    float convFlo = atof(argv[i]);
    sumVal += convFlo;

}

  // TODO: After the loop has processed all the numbers, divide the total sum by
  // the number of numbers the user entered. Print this value.

  float avg;
  avg = sumVal/argc;

  cout << "The sum of the integers is " << sumVal << endl;
  cout << "And the average of the numbers is " << avg << endl;

}
