#include <iostream>
using namespace std;

int main() {

string name;
name = "Tuffy";

string address = "800 N State College Blvd\nFullerton, CA 92831";

cout << name << endl << address << endl;

int a_number;
a_number = 69;

int the_thing = 420;

cout << endl << a_number << endl << the_thing << endl << endl << "N I C E"
     << endl << endl;

int number1; //variable declaration
int number2;

cout << "Enter the first number: ";
cin >> number1;
cout << endl << "The first number is " << number1 << "." << endl << endl;

cout << "Enter the second number: ";
cin >> number2;
cout << endl << "The second number is " << number2 << "." << endl << endl;

int sum = number1 + number2;
cout << "The sum of the two numbers is " << sum << "." << endl;

return 0;

}
