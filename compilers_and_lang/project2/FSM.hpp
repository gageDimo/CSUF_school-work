// Program name: "FSM". This is a header file that defines the states used in lexical analysis as well as the token object that will be stored for use in syntax analysis.
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


enum FSM_transitions{ // Transition states that will be used
  RESET = 0,
  STRING,
  SEPARATOR,
  OPERATOR,
  INTEGER,
  REAL,
  KEYWORD,
  IDENTIFIER
};

int FSM_table [][7] = {{RESET, STRING, SEPARATOR, OPERATOR, INTEGER, REAL}, // Table for FSM, contains the different states that will be used as well as the default state when everything is a reset
{STRING, STRING, RESET, RESET, STRING, RESET},
{SEPARATOR, RESET, RESET, RESET, RESET, RESET},
{OPERATOR, RESET, RESET, RESET, RESET, RESET},
{INTEGER, RESET, RESET, RESET, INTEGER, REAL},
{REAL, RESET, RESET, RESET, RESET, REAL}};

struct token{ // Token that will be stored in vector
  std::string token;
  int token_info;
  std::string token_name;
};
