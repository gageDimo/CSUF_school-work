// Program name: "Token". This program builds the definitions of 3 of the categories that will be utilized by the DFSMs, namely keywords, operators, and delimiters.
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
// Program name: Token
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


#ifndef TOKENS_H
#define TOKENS_H

#include <unordered_set>
#include <string>
#include<cstddef>

// classifies each token as a specific type
enum class Tokentype{
  Identifier, Keyword, String, Literal, Comment, Operator, Delim, whitespace
};
static const std::unordered_set<std::string> keywords = {"var", "for", "while", "print", "constant","int","float","bool","true","false","if","else","then","endif","whileend","do","doend","forend","input", "and","or","not","output","return"};
static const std::unordered_set<char> operators = {'+', '-', '*', '/', '=','<','>',};
static const std::unordered_set<std::string> operators2 = {"+", "-", "*", "/", "=","<",">",".","<<",">>","+=","-=","==","<=",">=","++","!="};
static const std::unordered_set<char> delims = {'(', ')', ';'};
static const std::unordered_set<std::string> delims2 = {"(", ")", ";","{","}"};
static const std::unordered_set<char> whitespace = {'\n', '\r', '\t', ' ' };
static const std::unordered_set<std::string> whitespace2 = {"\n", "\r", "\t", " " };

struct Token{
public:
  std::string tokenValue;
  Tokentype tokenType;
  Token() = delete;
  Token(const std::string& tokenValue1, Tokentype tokenType1): tokenValue(tokenValue1), tokenType(tokenType1) {}
  Token(const Token& token): tokenValue(token.tokenValue), tokenType(token.tokenType) {}
};

#endif
