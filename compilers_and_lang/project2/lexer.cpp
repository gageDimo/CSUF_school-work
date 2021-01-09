// Program name: "lexer". This program defines the function used to carry out lexical analysis and store the resulting tokens in a vector.
// Copyright (C) 2020 Richard Gobea
// This program is free software: you can redistribute it and/or modify it under the terms
// of the GNU General Public License version 3 as published by the Free Software Foundation.
// This program is distributed in the hope that it will be useful, but without any warranty;
// without even the implied warranty of merchantibility or fitness for a particular purpose.
// See the GNU General Public License for more details.
// A copy of the GNU General Public License v3 is available here:
// <https://www.gnu.org/licenses/>.

// Author information:
// Author name: Richard Gobea
// Author email: rgobea@csu.fullerton.edu

// Program information:
// Program name: main
// Programming languages with four modules in C++
// Date program began 2020/10/29
// Date program completed 2020/11/08

// Project information:
// Files: Main.cpp, Machines.cpp, FSM.hpp, lexer.cpp
// Status: Program has been tested and fulfills purpose with no errors

// Translator information:
// Gnu compiler: g++ -o main Main.cpp

// Execution:
// ./main

// References and credits
// No references

// Begin code area


#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "Machines.cpp"

std::vector<token> lexer(std::string buffer) {

  token token1; // Token that will be stored in vector
  std::vector<token> token_vec; // Contains tokens that will be read later
  int column = RESET; // Used for FSM table
  int previous_state = RESET; // Initial state
  int current_state = RESET; // Initial state
  char current_cha = ' '; // Will be used when looping through buffer string
  std::string current_str = ""; // Will be used to store in token
  bool ignore = false; // In case of comment block

for(int i = 0; i < buffer.length();i++){
  current_cha = buffer[i];
  if(current_cha == '/' && buffer[i+1] == '*' || current_cha == '*' && buffer[i+1] == '/') { // If comment found, will ignore and move on to rest of file
      ignore = true;
  }

  if(!ignore){
    column = getChar(current_state, current_cha); // Gets column for FSM table
    current_state = FSM_table[current_state][column]; // Finds state in FSM table
    current_str.erase(remove_if(current_str.begin(), current_str.end(), isspace), current_str.end());
    if(keyword_state(current_str)){
      token1.token = current_str;
      token1.token_info = KEYWORD;
      token1.token_name = getname(token1.token_info);
      token_vec.push_back(token1);
      current_str = " "; // Resets current string
    }
    if(current_state == RESET){
        if(previous_state == STRING){
          if(keyword_state(current_str)){ // Checks if current str is keyword
            previous_state = KEYWORD;
          }
          else if(identifier_state(current_str)){ // Checks if current str is identifier
            previous_state = IDENTIFIER;
          }
        }
      if(previous_state != RESET){ // Used to store information in token and add token to vector
        current_str.erase(remove_if(current_str.begin(), current_str.end(), isspace), current_str.end());
        token1.token = current_str;
        token1.token_info = previous_state;
        token1.token_name = getname(token1.token_info);
        token_vec.push_back(token1);
        current_str = ""; // Resets current string
      }
      if(!std::isspace(current_cha)){ // In case of white space
        i--;
      }
    }
    else{
        current_str += current_cha; // Adds current char to string
      }
    previous_state = current_state;
    }
  }
  if(current_str != ""){
      if(previous_state == STRING){ // Checks for keyword in current str
        if(keyword_state(current_str)){
          current_state = KEYWORD;
        }
        else if(identifier_state(current_str)){ // Checks for identifier in current str
          current_state = IDENTIFIER;
        }
        }

      if(current_state != RESET ){ // Adds info to token and adds token to vector
        token1.token = current_str;
        token1.token_info = current_state;
        token1.token_name = getname(token1.token_info);
        token_vec.push_back(token1);
      }
    }
return token_vec; // Returns vector containing tokens
}
