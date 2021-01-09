// TODO: Include your full name and class section.
// Michael Dimapindan CPSC 120 Section 06

#include <iostream>
#include <ctime>
using namespace std;

/*
Plays a game of Rock, Paper, Scissors. The user can enter one of 0, 1, or 2 to
represent rock, paper, and scissors respectively.
*/
int main(int argc, char* argv[])
{
    // TODO: Extract the user's choice from argv.

    string choice;
    choice = argv[1];

    int rpsChoice = std::stoi(choice);

    // TODO: If the user enters an invalid choice, such as -4 or 56, yell at
    // them with a sassy message and assign them rock. Inform them the choice
    // of rock has been made on their behalf for not following instructions.

    if(rpsChoice == 0) {

      cout << "You chose rock." << endl;

    }
    else if(rpsChoice == 1) {

      cout << "You chose paper." << endl;

    }
    else if(rpsChoice == 2){

      cout << "You chose scissors." << endl;

    }

    else {

      cout << "Since you can't follow simple instructions clearly, you'll be"
      " assigned \"rock\", if only to match your IQ level." << endl;

      rpsChoice = 0;

    }
    // TODO: The following code will pick a random positive integer to represent
    // the computer's choice, but as-is it chooses a big number! Convert that
    // big number to either 0 for rock, 1 for paper, or 2 for scissors.
    srand(time(0)); // Don't touch this line.
    int computerChoice = rand() % 3; // Change this line to get 0, 1, or 2 HINT: use %.

    // TODO: This code as it is now prints the computer's choice as a number.
    // Instead of printing computerChoice (which is a number), print some string
    // with the word "rock", "paper", or "scissors" according to the value of
    // computerChoice.
    // HINT: Use an if-else if-else statement to check the value computerChoice
    // and print accordingly.

    string compHand;

    if(computerChoice == 1) {

      compHand = "paper";

    }
    else if(computerChoice == 2) {

      compHand = "scissors";

    }
    else
      compHand = "rock";

    cout << "The computer chose: " << compHand << endl;

    // TODO: Compare the user's choice (0, 1, or 2) to the computer's choice
    // (also either 0, 1 or 2) using an if-else if-else statement to go
    // account for each of the possibilities. In each branch, determine
    // who won, or if it's a tie, and print as such.

    if(rpsChoice == 0 && computerChoice == 1) {

      cout << "You lose!" << endl;

    }
    else if(rpsChoice == 1 && computerChoice == 2) {

      cout << "You lose!" << endl;

    }
    else if(rpsChoice == 2 && computerChoice == 0) {

      cout << "You lose!" << endl;

    }
    else if(rpsChoice == 0 && computerChoice == 0) {

      cout << "Draw!" << endl;

    }
    else if(rpsChoice == 1 && computerChoice == 1) {

      cout << "Draw!" << endl;

    }
    else if(rpsChoice == 2 && computerChoice == 2) {

      cout << "Draw!" << endl;

    }
    else if(rpsChoice == 0 && computerChoice == 2) {

      cout << "You win!" << endl;

    }
    else if(rpsChoice == 2 && computerChoice == 1) {

      cout << "You win!" << endl;

    }
    else
      cout << "You win!" << endl;

}
