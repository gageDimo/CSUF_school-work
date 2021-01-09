#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> GetKnownWords(string file_name) {
  vector<string> known_words;
  ifstream words_file(file_name);
  for (string word; getline(words_file, word);) {
    known_words.push_back(word);
  }
  return known_words;
}

int main(int argc, char* argv[]) {
  vector<string> all_words = GetKnownWords("known_words_long.txt");

  // TODO: Repeatedly prompt the user for words, and check what the spelling suggestions are.
  // You may use an infinite loop and exit with ctrl + c.

  return 0;
}
