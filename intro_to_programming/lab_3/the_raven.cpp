//Michael Dimapindan, CPSC 120, Section 06
#include <iostream>
using namespace std;

int main() {
  // TODO: Convert each line of the following cout statements into its own
  // string variable. Instead of endl, add the newline character to the end of
  // each string.
  /*cout << "Once upon a midnight dreary, while I pondered, weak and weary," << endl;
  cout << "Over many a quaint and curious volume of forgotten lore-" << endl;
  cout << "While I nodded, nearly napping, suddenly there came a tapping," << endl;
  cout << "As of some one gently rapping, rapping at my chamber door." << endl;
  */
  // TODO: In the original poem, These two lines show up as
  //
  // "Tis some visitor," I muttered, "tapping at my chamber door-
  //                           Only this and nothing more."
  //
  // Note the spacing and double quotes! Use the appropriate escape characters
  // to get the tabs and quotes to show up.
  /*cout << "Tis some visitor, I muttered, tapping at my chamber door-" << endl;
  cout << "Only this and nothing more." << endl;
  */

  // TODO: Concatenate line variable into a single string variable.
  // (Alternatively, you may also start with a string builder and concatenate
  // each line as you go if you don't want to create a variable for each line.
  // If you aren't sure what this means, don't worry about it and go with a
  // variable per line approach).

  string firstLine = "Once upon a midnight dreary, while I pondered, weak and"
                      " weary,\n";
  string sndLine = "Over many a quaint and curious volume of forgotten lore-\n";
  string trdLine = "While I nodded, nearly napping, suddenly there came a tapping,\n";
  string frthLine = "As of some one gently rapping, rapping at my chamber door.\n";

  string quote = "\"Tis some visitor,\" I muttered, \"tapping at my chamber door-\n"
           "\t\t\tOnly this and nothing more.\"\n";

  string paragraph = firstLine + sndLine + trdLine + frthLine + quote;

  // TODO: cout the concatenated variable that has the full (what's included) poem.

  cout << paragraph << endl;

}
