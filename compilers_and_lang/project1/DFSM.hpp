// Program name: "DFSM". This is the header file for the DFSM. More information is included on its cpp file.
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
// Program name: DFSM (header)
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

#ifndef DFSM_H
#define DFSM_H
void Identifier_DFSM(std::string buffer);
void Whitespace_DFSM(std::string buffer);
void Operator_DFSM(std::string buffer);
void Keywords_DFSM(std::string buffer);
void Delim_DFSM(std::string buffer);
void Int_DFSM(std::string buffer);
void Real_DFSM(std::string buffer);

#endif
