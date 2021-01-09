// Michael Dimapindan CPSC 120 Section 6
#include <iostream>
#include <ctime>
using namespace std;

const string ROCK = "rock";
const string PAPER = "paper";
const string SCISSORS = "scissors";

string GetPlayerChoice() {

  string player_choice;

  cout << "Will you use rock, paper, or scissors?" << endl;
  cin >> player_choice;

  if(player_choice != ROCK && player_choice != PAPER &&
        player_choice != SCISSORS) {

    cout << "Invalid argument. Automatically assigning player choice"
    " to \'rock.\'" << endl;

    player_choice = ROCK;

  }

  return player_choice;

}

string GetComputerChoice() {

  string comp_choice;

  srand(time(0));
  int comp_decide = rand() % 3;

  if (comp_decide == 0) {
    comp_choice = ROCK;
  }
  else if(comp_decide == 1) {
    comp_choice = PAPER;
  }
  else if(comp_decide == 2) {
    comp_choice = SCISSORS;
  }

  return comp_choice;

}

string DetermineWinner(string player_choice, string comp_choice) {

  string result;

  if ((player_choice == ROCK && comp_choice == PAPER) ||
      (player_choice == PAPER && comp_choice == SCISSORS) ||
      (player_choice == SCISSORS && comp_choice == ROCK)) {

        result = "Computer wins!";

      }
  else if ((player_choice == PAPER && comp_choice == ROCK) ||
          (player_choice == SCISSORS && comp_choice == PAPER) ||
          (player_choice == ROCK && comp_choice == SCISSORS)) {

        result = "Player wins!";

      }
  else if (player_choice == comp_choice ) {
        result = "Draw!";
      }

      return result;

}

int main() {

  string user_choice = GetPlayerChoice();

  cout << "Player used: " << user_choice << endl;

  string opponent_choice = GetComputerChoice();

  cout << "Computer used: " << opponent_choice << endl;

  string result = DetermineWinner(user_choice, opponent_choice);

  cout << result << endl;

  return 0;

}
