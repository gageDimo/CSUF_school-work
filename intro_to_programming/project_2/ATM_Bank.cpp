// Michael Dimapindan CPSC 120 Section 06
#include <iostream>
#include <string>

using namespace std;

  float deposit(float add, float curBal) {
    float newBal = add+curBal;
    return newBal;
  }

  float withdraw(float take, float curBal) {
    float newBal = curBal-take;
    return newBal;
  }

int main(int argc, char* argv[]) {

  if(argc != 3) {
    cout << "Incorrect number of arguments. Exiting program." << endl;
    return 0;
  }

  string user_pin = argv[1];
  string cashInput = argv[2];
  int pin_num = std::stoi(user_pin);
  float cashAmount = std::stof(cashInput);

  // checks if PIN number is exactly 4 digits
  if(pin_num < 1000 || pin_num > 9999) {
    cout << "Error: PIN number does not have 4 digits or"
    " it has 0 as the first digit. Try again later.\nExiting program." << endl;
        return 0;
  }
  // checks if account does not have less than $0
  if(cashAmount < 0) {
    cout << "Error: Amount cannot store anything less than 0. Try again later."
        << endl << "Exiting program." << endl;
        return 0;
  }

  int pin_check;
  cout << "Please enter your 4 digit PIN number: ";
  cin >> pin_check;
  cout << endl;

  int trialCount = 3;
  while(pin_check != pin_num) {
    trialCount--;
    cout << "Incorrect PIN number try again or input -1 to quit program."
        << endl << "You have " << trialCount << " attempt(s) left." << endl;
    cin >> pin_check;
        if(pin_check == -1) {
          cout << "Exiting program. Have a nice day!" << endl;
          break;
        }
        if(trialCount == 1) {
        cout << "You have run out of attempts. Exiting program." << endl;
        break;
        }
  }

  while (pin_check == pin_num) {
    int menu_choice;
    cout << "What would you like to do?" << endl;
    cout << "\t1) Check Balance\n\t2) Deposit Cash\n\t3) "
        "Withdraw from Account\n\t4) Quit Program" << endl;
    cin >> menu_choice;

  if(menu_choice == 1) {
    cout << "Your current balance is: $" << cashAmount << "." << endl;
  }
  else if(menu_choice == 2) {
    float addMoney;
    cout << "How much would you like to add?" << endl;
    cin >> addMoney;

    float addUpdate = deposit(addMoney,cashAmount);
    cout << "You have successfully deposited your money!" << endl;
    cashAmount = addUpdate; //updates current balance

  }
  else if(menu_choice == 3) {
    float takeMoney;
    cout << "How much money would you like to withdraw?" << endl;
    cin >> takeMoney;

    while(takeMoney > cashAmount) {
      cout << "Error: Cannot withdraw more than $" << cashAmount
        << ". Please withdraw an acceptable amount or press 0 to cancel."
        << endl;
        cin >> takeMoney;
    }
    float takeUpdate = withdraw(takeMoney,cashAmount);
    cout << "You have successfully withdrew from your account!" << endl;
    cashAmount = takeUpdate; //updates current balance

  }
  else if(menu_choice == 4) {
    cout << "You have $" << cashAmount << " left in your account."
        << " Exiting program. Have a nice day!" << endl;
    break;
  }
  else {
    cout << "Error: You have made an incorrect choice. Please choose one of "
     "the four options." << endl;
  }
}
  return 0;
}
