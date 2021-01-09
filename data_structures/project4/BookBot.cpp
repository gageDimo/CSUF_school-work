// Michael Dimapindan CPSC 131

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

#include "BookBot.h"
#include "sanitize.h"

int rand();

// made additional function for project
string BookBot::convertToString(char x) {
  string s(1,x);
  return s;
}

BookBot::BookBot(const unsigned int seed) {

  srand(seed);

}

void BookBot::readIn(const string &filename) {

    ifstream read_file;
    string prev_word;
    string word;
    read_file.open(filename);
    read_file >> prev_word;

    markov_chain["^"].push_back(prev_word);

    while (read_file >> word) {
      sanitize(word);
      if (isEndPunctuation(word.back())) {

        string punc(1, word.back());
        word.pop_back();

        markov_chain[prev_word].push_back(word);
        markov_chain[word].push_back(punc);
        markov_chain[punc].push_back("$");
        prev_word = "^";

      }
      else {
        markov_chain[prev_word].push_back(word);
        prev_word = word;
      }
    }

    read_file.close();

}

bool BookBot::isEndPunctuation(const char character) {

  char period = '.';
  char question = '?';
  char ex_point = '!';

  if(character == period) {
    return true;
  }
  if(character == question) {
    return true;
  }
  if(character == ex_point) {
    return true;
  }
  else {
    return false;
  }

}

vector<string> BookBot::getValues(const string &key) {

  return markov_chain[key];

}

string BookBot::generateSentence() {

  string prev_word = "^";
  string sentence = "";
  vector<string> words_list;
  string choose_word;

  while (prev_word != "$") {

    words_list = getValues(prev_word);
    choose_word = words_list[rand() % words_list.size()];
    sentence = sentence + choose_word + " ";
    prev_word = choose_word;

  }

  return sentence;

}
