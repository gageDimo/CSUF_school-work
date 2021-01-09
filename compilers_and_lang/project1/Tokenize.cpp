// Program name: "Tokenize". This program takes an input file and returns it as a vector of tokens. Tokens are not categorized, as this is done later by the DFSMs.
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
// Program name: Tokenize
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



#include "Token.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
using LineNo = unsigned int;
std::vector<Token> Tokenize (std::string filename){
  std::ifstream file(filename); // Opens file
  if(file.fail()){ // Error message if file fails to open
    std::cout << "Error. Unable to open file" << std::endl;
    exit(0);
  }

  char cha1;
  bool isString = false;
  char previous;
  std::vector<Token> vec1; // Iterates through file
  while (file  >> std::noskipws >> cha1){
    if(isString == false && cha1 == '"' && !isalpha(previous)){
      vec1.push_back(Token(std::string(1,'\n'), Tokentype::whitespace));
      vec1.push_back(Token(std::string(1,cha1), Tokentype::String));
      isString = true;
    }
    else if(isalpha(cha1) && delims.find(file.peek()) != delims.end()){
      vec1.push_back(Token(std::string(1,cha1), Tokentype::Keyword));
      vec1.push_back(Token(std::string(1,'\n'), Tokentype::whitespace));
    }
    else if(isString == true && operators.find(file.peek()) != operators.end()){
      vec1.push_back(Token(std::string(1,'\n'), Tokentype::whitespace));
    }
    else if(isString == true && cha1 != '"'){
      vec1.push_back(Token(std::string(1,cha1), Tokentype::String));
    }
    else if(isString == true && cha1 == '"'){
      vec1.push_back(Token(std::string(1,cha1), Tokentype::String));
      isString = false;
    }
    else if(whitespace.find(cha1) != whitespace.end()){
      vec1.push_back(Token(std::string(1,'\n'), Tokentype::whitespace));
    }
    else if(delims.find(cha1) != delims.end()){ // Different cases for comparing to definitions of delims and operators. Will return vector containing tokens
      vec1.push_back(Token(std::string(1,'\n'), Tokentype::whitespace));
      vec1.push_back(Token(std::string(1,cha1), Tokentype::Delim));
      vec1.push_back(Token(std::string(1,'\n'), Tokentype::whitespace));
    }
    else if(delims.find(cha1) != delims.end()){
      vec1.push_back(Token(std::string(1,'\n'), Tokentype::whitespace));
      vec1.push_back(Token(std::string(1,cha1), Tokentype::whitespace));

    }
    else if(isString == false && operators.find(cha1) != operators.end() && operators.find(file.peek()) != operators.end()){
      vec1.push_back(Token(std::string(1,'\n'), Tokentype::whitespace));
      vec1.push_back(Token(std::string(1,cha1), Tokentype::Operator));
    }
    else if(operators.find(cha1) != operators.end()){
      vec1.push_back(Token(std::string(1,cha1), Tokentype::Operator));
      vec1.push_back(Token(std::string(1,'\n'), Tokentype::whitespace));;
    }
    else{
      vec1.push_back(Token(std::string(1,cha1), Tokentype::Keyword));

    }
    previous = cha1;
  }
  std::ofstream output("output.txt");
  for(auto x: vec1){
    output << x.tokenValue;
  }



return vec1;

}
