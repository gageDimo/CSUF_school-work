// TODO: Include your full name and lab section.
// Michael Dimapindan CPSC 120 Section 06

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  // TODO: prompt the user for a tweet.

  cout << "Enter your tweet: ";

  string tweetInput;
  int count = 0;

  // TODO: Read the tweet through cin. Note cin >> won't work this time
  // becase of the potential spaces in the tweet (see HINTS for getline).

  getline(cin, tweetInput);

  // TODO: Use a while loop to count the number of characters in the tweet,
  // excluding the null Schwarzneggar I mean null terminator
  // (see HINTS for char and string).

  char nullChar = '\0';

  while(tweetInput[count] != nullChar) {
      count++;
  }

  cout << "Your tweet is " << count << " characters long." << endl;

  // TODO: Determine whether the user is above or below the character limit. The
  // null terminator does not count against their limit! If they are above the
  // limit, tell them how much. Otherwise, tell them how many characters their
  // tweet uses.

  if(count > 140) {

    cout << "Your message is over 140 characters. It is too long to tweet."
        << endl << endl;

  }

  // TODO: Preview (print) what the user's tweet would look like if the
  // character limit were imposed, using a while loop. Tweets below the limit
  // should appear unchanged, but tweets past the limit should be truncated
  // (don't print anything past the limit).

  cout << "Preview:\n\t"

  count = 0;

  while(tweetInput[count] != nullChar) {

    count++;

    if(count <= 140) {

      cout << tweetInput[count-1];

    }

  }

  cout << endl;

}
