//Michael Dimapindan CPSC 120 Section 06

// TODO: Include the vector directive here.
#include <iostream>
#include <vector>
using namespace std;

// TODO: Create a void function called Print that takes a vector of floats and
// prints each value, separated by a space, and a newline at the end.

  void Print(vector<float> vtr) {

    for (int i = 0; i < vtr.size(); i++) {
      cout << vtr[i] << " ";
    }

    cout << endl;

  }

// TODO: Create a function called GetMaximum that takes a vector of floats and
// returns the maximum value inside. If the vector is empty, just return 0.

  float GetMaximum(vector<float> vtr) {

    if (vtr.size() == 0) {
      return 0;
    }

    float maxValue = vtr[0];

      for (int i = 0; i < vtr.size(); i++) {
        if (vtr[i] > maxValue) {
          maxValue = vtr[i+1];
        }
      }

      return maxValue;

  }

// TODO: Create a function called GetMinimum that takes a vector of floats and
// returns the minimum value inside. If the vector is empty, just return 0.

float GetMinimum(vector<float> vtr) {

  if (vtr.size() == 0) {
    return 0;
  }

  float minValue = vtr[0];

    for (int i = 0; i < vtr.size(); i++) {
      if (vtr[i] < minValue) {
        minValue = vtr[i];
      }
    }

    return minValue;

}

// TODO: Create a function called GetLowScores that takes a vector of floats
// and returns another vector containing the values seen in the input vector
// that are below 60.

  vector<float> GetLowScores(vector<float> vtr) {

    vector<float> lowestScore;
    for (int i = 0; i < vtr.size(); i++) {
        if (vtr[i] < 60) {
          lowestScore.push_back(vtr[i]);
        }
    }

    return lowestScore;

  }

int main(int argc, char* argv[]) {
  // TODO: Declare a vector of type float, and name it scores.

  vector<float> scores;

  // TODO: Read the values from argv into scores.

  for (int i = 1; i < argc; i++) {
    string vtrInput = argv[i];
    float vtrElem = stof(vtrInput);
    scores.push_back(vtrElem);
  }

  // TODO: Determine the highest score using GetMaximum and print it.

  float highScore = GetMaximum(scores);
  cout << "The highest score is: " << highScore << endl;

  // TODO: Determine the lowest score using GetMinimum and print it.

  float lowScore = GetMinimum(scores);
  cout << "The lowest score is: " << lowScore << endl;

  // TODO: Get the vector of "failing" scores (those below 60) and print them
  // using the Print function you created along with a message of your choosing.
  // Use .size() to check if there are any scores to bother printing first.

  vector<float> failScores = GetLowScores(scores);
  cout << "The failing scores (below 60) are shown below:\n";
  Print(failScores);

  return 0;
}
