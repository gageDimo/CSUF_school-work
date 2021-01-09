// Program name: "Main". This file is the one that compiles the program together.
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
// Program name: Main
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

#include "Tokenize.cpp"
#include "lexer.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <regex>


int main(){ // Main that will call Tokenize function. Included here for testing purposes, will be moved to own file at end of project
  std::string file;
  std::cout << "Input the name of the file to tokenize" << std::endl; // Takes user input for name of file to be tokenized
  std::cin >> file;
  std::cout << "Received input: " << file << ". Opening file" << std::endl;
  std::cout << "Outputting tokenized file." << std::endl;
  Tokenize(file);
  lexer("output.txt");
  std::cout << "Results of the NFSM will be outputted as text file 'results'" << std::endl;
  std::cout << "Program done. Returning 0" << std::endl;
  return 0;
}
