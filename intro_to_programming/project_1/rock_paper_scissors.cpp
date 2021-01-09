// Michael Dimapindan CPSC 120 Section 06
#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]) {

    //checks if there are enough arguments when compiling
    if (argc != 2) {
      cout << "Invalid number of choices. Exiting program." << endl;
      return 0;
    }

    string choice = argv[1];
    //reads the choice the user made
    int user_choice = std::stoi(choice);

    if (user_choice == 0) {
      cout << "You chose rock." << endl;
    }
    else if (user_choice == 1) {
      cout << "You chose paper." << endl;
    }
    else if (user_choice == 2) {
      cout << "You chose scissors." << endl;
    }
    else {
      cout << "Since you can't follow simple instructions clearly, you'll be"
      " assigned \"rock\",\nif only to match your IQ level." << endl;
      user_choice = 0;
    }

    //determines the choice the computer will make
    srand(time(0));
    int computer_choice = rand() % 3; //ensures that the choice is 0, 1, or 2

    string opp_choice;

    if (computer_choice == 1) {
      opp_choice = "paper";
    }
    else if (computer_choice == 2) {
      opp_choice = "scissors";
    }
    else {
      opp_choice = "rock";
    }

    cout << "The computer chose: " << opp_choice << endl;

    //if-statements that determines who wins

    if (user_choice == 0 && computer_choice == 2) {
      cout << "You win!" << endl;
    }
    else if (user_choice == 2 && computer_choice == 0) {
      cout << "You lose!" << endl;
    }
    else if (user_choice < computer_choice) {
      cout << "You lose!" << endl;
    }
    else if (user_choice > computer_choice) {
      cout << "You win!" << endl;
    }
    else {
      cout << "Draw!" << endl;
    }
}
