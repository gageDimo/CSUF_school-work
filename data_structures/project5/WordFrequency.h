//Michael Dimapindan CPSC 131

#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <map> //added by Michael

using namespace std; //edited from std::string to namespace std

class WordFrequency {
private:
    // TO BE COMPLETED
    unordered_map<string, size_t> words_map;

    //helper map made to split punctuations from a word
    map<string, vector<string>> words_split;

    string text;
    size_t num_of_occur;

public:
    WordFrequency(); // default constructor
    void readIn(const string & filename); // add words from file to hash table
    size_t numberOfWords(); // return the number of unique words
    size_t wordCount(const string & word); // return the number of occurrences of the given word
    string mostFrequentWord(); // return the most frequent word
    size_t maxBucketSize(); // return the size of the largest bucket in the hash table
};
