//Michael Dimapindan CPSC 120 Section 6

#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <ctime>

using namespace std;

pair <string, string> GetVote(string line) {
  int position_of_comma = line.find_first_of(",");
  string voter = line.substr(0, position_of_comma);
  string candidate = line.substr(position_of_comma + 1, line.length());
  return make_pair(voter, candidate);
}

vector< pair<string, string> > GetVotes() {
  vector< pair<string, string> > votes;
  ifstream votes_file("votes.csv");
  string line;
  for (string line; getline(votes_file, line);) {
    votes.push_back(GetVote(line));
  }

  return votes;
}

int main(int argc, char* argv[]) {

  vector < pair <string, string> > votes = GetVotes();
  unordered_map <string, int> results;
  unordered_map <string, int> audit; //checks for voter fraud

  for (int i = 0; i < votes.size(); i++) {
    pair <string, string> voter_candidate = votes.at(i);

    string voter = voter_candidate.first;

    //extracts the candidate from pair "voter_candidate"
    string candidate = voter_candidate.second;

    //checks if voter has already voted
    if (audit.find(voter) == audit.end()) {

      //checks if candidate exists
      if (results.find(candidate) == results.end()) {
        //candidate gets exactly one vote if never encountered in middle of map
        results[candidate] = 1;
      }
      else {
        results[candidate] += 1;
      }
      audit[voter] = 1;
    }
    else {
      audit[voter] += 1;
    }
}

  string winner;
  int highest_votes = 0;

  // the ":" in the for loop creates an iterator
  for (pair <string, int> candidate_votes : results) {

    cout << candidate_votes.first << " got " << candidate_votes.second
         << " votes." << endl;

    if (candidate_votes.second > highest_votes) {
      winner = candidate_votes.first;
      highest_votes = candidate_votes.second;
    }
  }

  cout << endl;

  for (pair <string,int> voter_stickers : audit) {
    if (voter_stickers.second > 1) {
      cout << voter_stickers.first << " voted " << voter_stickers.second - 1
      << " times too many." << endl;
    }
  }

  // TODO: Determine who won the election.
  cout << endl << winner << " won with " << highest_votes << " votes." << endl;


}
