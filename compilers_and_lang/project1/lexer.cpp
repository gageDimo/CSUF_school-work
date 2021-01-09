// Program name: "Lexer". This program converts the contents of the input file into a series of tokens.
// Copyright (C) 2020 Richard Gobea
// This program is free software: you can redistribute it and/or modify it under the terms
// of the GNU General Public License version 3 as published by the Free Software Foundation.
// This program is distributed in the hope that it will be useful, but without any warranty;
// without even the implied warranty of merchantibility or fitness for a particular purpose.
// See the GNU General Public License for more details.
// A copy of the GNU General Public License v3 is available here:
// <https://www.gnu.org/licenses/>.

// Authors' information:
// Authors' names: Richard Gobea, Armon Rahimi, Gage Dimapindan
// Authors' emails: rgobea@csu.fullerton.edu, Armon16@csu.fullerton.edu,
//                    mdimapindan@csu.fullerton.edu

// Program information:
// Program name: Lexer
// Programming languages with 2 modules in C++
// Date program began 2020/9/21
// Date program completed 2020/10/1

// Project information:
// Files: Token.hpp, Tokenize.cpp, DFSM.hpp, DFSM.cpp, lexer.cpp, main.cpp,
//        test.cpp, test2.cpp, test3.cpp, results.txt (output file)
// Status: Program has been tested and fulfills purpose with no errors

// Translator information:
// Gnu compiler: g++ main.cpp -o test
// Execution:
// ./test

// References and credits
// No references

// Begin code area


#include "DFSM.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <regex>

bool Done = false;
void lexer(std::string file){
  std::regex lit("^[0-9]+$");
  std::ifstream file1(file);
  std::string buffer;

  while(Done == false){
    getline(file1, buffer);
    if(!file1){
      Done = true;
    }
    else if(operators2.find(buffer) != operators2.end()){
      Operator_DFSM(buffer);
    }
    else if(keywords.find(buffer) != keywords.end()){
      Keywords_DFSM(buffer);
    }
    else if(isalpha(buffer[0])){
      Identifier_DFSM(buffer);
    }
    else if(delims2.find(buffer) != delims2.end()){
      Delim_DFSM(buffer);
    }
    else if(std::regex_match(buffer, lit)){
      Int_DFSM(buffer);
    }
    else if(buffer.find(".") != std::string::npos){
      Real_DFSM(buffer);
    }
    else if(buffer[0] == '"'){
      results << buffer << "  ==>  " << "string" << std::endl;
    }
  }
}
