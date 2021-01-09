// Program name: "main". This program calls the functions required to complete the program's task of lexical analysis and syntax analysis.
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

#include <string>
#include <fstream>
#include <iostream>
#include "lexer.cpp"

int main(){

  std::ifstream test_file("test3.cpp"); // Opens test file that will be read
  std::ofstream test("test.txt"); // Outputs text file with results from lexer and checkSyntax
  std::string read_line; // Used with getline to read test file
  std::vector<token> token_vector; // Used to store tokens

  while(getline(test_file,read_line)) {
    token_vector = lexer(read_line);
    checkSyntax(token_vector);
  }
  std::cout << "Done" << std::endl; // Used to show that vector has been read successfully
  return 0;

}
