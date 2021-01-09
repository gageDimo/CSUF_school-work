// Michael Dimapindan CPSC 120 Section 06

#include <iostream>
using namespace std;

// TODO: Declare a const int representing the number of expected values, e.g. 5
// called NUMBER_OF_SCORES.

const int NUMBER_OF_SCORES = 5;

// TODO: Create a void function called Initialize that takes an array of floats
// and its size, and sets each value in the array to 0.

void Initialize(float array[], int size) {
  for (int i = 0; i < size; i++) {
    array[i] = 0;
  }
}

// TODO: Create a function called GetMaximum that takes an array of floats and
// the size of the array, and returns the highest float in that array.

  float GetMaximum(float array[], int size) {
    float highestVal = array[1];
    for(int i = 2; i < (size+1); i++) {
      if(array[i-1] < array[i]) {
        highestVal = array[i];
      }
    }
    return highestVal;
  }

// TODO: Create a function called GetMinimum that takes an array of floats and
// the size of that array, and returns the lowest float in that array.
// 1 2 4 3
  float GetMinimum(float array[], int size) {
    float lowestVal = array[1];
    for(int i = 2; i < (size+1); i++) {
       if(array[i-1] > array[i]) {
        lowestVal = array[i];
      }
    }
    return lowestVal;
  }

// TODO: Create a function called CalculateTotal that takes an array of floats
// and the size of that array, and calculates the total inside. This function
// will be useful for determining the average and score needed for certain
// grades.

  float CalculateTotal(float array[], int size) {

    float getSum = 0;
    for (int i = 2; i < (size+1); i++) {
      getSum += array[i];
    }

    return getSum;

  }

// TODO: Create a function called CalculateAverage that takes an array of floats
// and the size of the array, and returns the average of all the values in the
// array as a float. HINT: Recycling is environmentally friendly! Call your
// existing CalculateTotal function somewhere in there to avoid re-inventing the
// wheel.

  float CalculateAverage(float array[], int size) {

    float average = 0;
    average = (CalculateTotal(array, size) / (float) size);

    return average;

}

// TODO: Create a function called GetCutoffScoreForGrade that takes a char,
// which represents the desired letter grade, and determines what the minimum
// overall score corresponding to that grade is as follows:
// A: 90.0
// B: 80.0
// C: 70.0
// D: 60.0
// Assume the letter is capitalized, and other letter grades don't need to be
// checked for, e.g. 'F' or 'w'.

  char GetCutoffScoreForGrade(float score) {

    char grade;

    if(score >= 90 && score <= 100) {
      grade = 'A';
    }
    else if(score >= 80 && score <= 89.99) {
      grade = 'B';
    }
    else if(score >= 70 && score <= 79.99) {
      grade = 'C';
    }
    else if(score >= 60 && score <= 69.99) {
      grade = 'D';
    }
    else {
      grade = 'F';
    }

    return grade;

  }

// TODO: Create a function called GetGradeForScore that takes a float and
// returns a char representing the grade for that score as follows:
// 90.0 or higher: 'A'
// 80.0 <= score < 90: 'B'
// 70.0 <= score < 80: 'C'
// 60 <= score < 70: 'D'
// < 60: 'F'

  char GetGradeForScore(float studentGrade) {

    return GetCutoffScoreForGrade(studentGrade);

  }

// TODO: (Optional challenge, 1 extra point) Create a function called
// GetMinimumScoreForGrade that takes an array of floats, the size of that
// array, and the target grade as a char. Determine the score that would be
// needed on a hypothetical assignment that would tak the place of the lowest
// score in the array in order to achieve a certain overall average score.

int main(int argc, char* argv[]) {
  // TODO: declare an array of type float, called scores and size
  // NUMBER_OF_SCORES.

    int size = NUMBER_OF_SCORES;
    float scores[size];

  // TODO: Initialize each value in the scores array to 0 using the Initialize
  // function you created above.

    Initialize(scores, size);

  // TODO: Read the appropriate number of values from argv into scores. Watch
  // out for off-by-1 errors.

  for (int i = 1; i < (size+1); i++) {
    scores[i] = stof(argv[i]);
  }

    if((argc+1) < NUMBER_OF_SCORES) {
      size = (argc+1);
    }

    cout << "The size of the array is " << size << endl;

  // TODO: Determine the highest score using GetMaximum and print it.

    float highScore = GetMaximum(scores, size);
    cout << "Highest Score: " << highScore << endl;

  // TODO: Determine the lowest score using GetMinimum and print it.

    float lowScore = GetMinimum(scores, size);
    cout << "Lowest Score: " << lowScore << endl;

  // TODO: Determine the overall average using CalculateAverage and print it.

    float average = CalculateAverage(scores, size);
    cout << "Average: " << average << endl;

  // TODO: Print the overall grade using GetGradeForScore and passing it the
  // overall average determined above.

    char grade = GetGradeForScore(average);
    cout << "Overall Grade: " << grade << endl;

  // TODO: If going for the Optional challenge extra credit, call
  // GetMinimumScoreForGrade and print its results for each of an 'A', 'B', 'C',
  // and 'D'.

  return 0;
}
