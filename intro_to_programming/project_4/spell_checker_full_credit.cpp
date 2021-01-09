//Michael Dimapindan CPSC 120 Section 06

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

vector<string> correction(string word) {
  vector<string> suggestions;
  for(int i = 0; i < word.length(); i++) {
    string copy_word = word;
    copy_word[i] = '*';
    suggestions.push_back(copy_word);
  }
  return suggestions;
}

int main(int argc, char* argv[]) {
  vector<string> known_words = GetKnownWords("known_words_short.txt");

  unordered_map<string,bool> words_list;
  unordered_map<string,string> spell_checked;

  for (string word : known_words) {
    words_list[word] = true;
    vector<string> possibilities = correction(word);
    for (string suggestion : possibilities) {
      spell_checked[suggestion] = word;
    }
  }

  while (true) {
    cout << "Press ctrl+c to quit program, otherwise...\n";
    string input;
    cout << "Enter a word: ";
    cin >> input;
    if (words_list.find(input) != words_list.end()) {
      cout << input << " is a known word." << endl << endl;
    }
    else if (words_list.find(input) == words_list.end()) {
      cout << input << " is misspelled." << endl << endl;
      vector<string> possible_words = correction(input);
      for (string spell_check : possible_words) {
        if (spell_checked.find(spell_check) != spell_checked.end()) {
          cout << "Did you mean: \"" << spell_checked[spell_check] << "\"?"
               << endl << endl;
        }
      }
    }
  }

  return 0;
}
