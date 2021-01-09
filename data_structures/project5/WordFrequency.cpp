//Michael Dimapindan CPSC 131

#include <fstream>

#include "WordFrequency.h"
#include "sanitize.h"

using namespace std;

WordFrequency::WordFrequency() {

  vector<pair<string, size_t>> word_vec;
  string get_text;

  for(int i = 0; i < word_vec.size(); i++) {
    pair<string, size_t> word_pair = word_vec.at(i);

    get_text = word_pair.first;

    if(words_map.find(get_text) == words_map.end()) {
      words_map[get_text] = 1;
    }
    else {
      words_map[get_text] += 1;
    }
  }

  for (pair<string, size_t> umap_data : words_map) {
    text = umap_data.first;
    num_of_occur = umap_data.second;
  }

}

void WordFrequency::readIn(const string &filename) {

      ifstream read_file;
      string prev_word;
      string word;
      read_file.open(filename);
      read_file >> prev_word;

      words_split["^"].push_back(prev_word);

      char end_punc = word.back();

      while (read_file >> word) {
        sanitize(word);
        if (end_punc == '.' || end_punc == '?' || end_punc == '!') {

          string punc(1, word.back());
          word.pop_back();

          words_split[prev_word].push_back(word);
          words_split[word].push_back(punc);
          words_split[punc].push_back("$");
          prev_word = "^";

        }
        else {
          words_split[prev_word].push_back(word);
          prev_word = word;
        }
      }

      //nested for loop transfers each word from helper map to main map
      for (pair<string,vector<string>> set_words : words_split) {
        for(pair<string,size_t> get_words : words_map) {

          string swap_word = set_words.first;
          string get_swap = get_words.first;
          get_swap = swap_word;

        }
      }

      read_file.close();

}

size_t WordFrequency::numberOfWords() {

  size_t unique_count;

  for(pair<string, size_t> get_unique : words_map) {

    if(get_unique.second == 1) {
      unique_count += 1;
    }

  }

  return unique_count;

}

size_t WordFrequency::wordCount(const string &word) {

  return words_map[word];

}

string WordFrequency::mostFrequentWord() {

  string common_word;
  size_t largest_value = 0;

  for(pair<string, size_t> get_most_freq : words_map) {

    if(largest_value < get_most_freq.second) {

      largest_value = get_most_freq.second;
      common_word = get_most_freq.first;

    }

  }

  return common_word;

}

size_t WordFrequency::maxBucketSize() {

  string most_freq = mostFrequentWord();
  return words_map[most_freq];

}
