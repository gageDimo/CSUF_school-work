// Program name: "Machines". This program defines the functions that will be used to carry out lexical and syntax analysis.
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


#include "FSM.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <vector>

// changed name of results text files match each respective test file
// ie test.cpp goes to results.txt, test2.cpp goes to results2.txt, etc.
std::ofstream output("results3.txt"); // Output file

bool keyword_state(std::string buffer){
  if ((buffer.compare("int") == 0) || (buffer.compare("float") == 0) || (buffer.compare("bool") == 0 ) || (buffer.compare("true") == 0 ) || // Checks buffer to see if it contains a keyword
(buffer.compare("false") == 0 ) || (buffer.compare("if") == 0 ) || (buffer.compare("else") == 0 ) || (buffer.compare("whileend") == 0 )
 || (buffer.compare("do") == 0 ) || (buffer.compare("for") == 0 ) || (buffer.compare("forend") == 0 ) || (buffer.compare("input") == 0 )
 || (buffer.compare("and") == 0 ) || (buffer.compare("or") == 0 )  || (buffer.compare("not") == 0 ) || (buffer.compare("then") == 0 )
 || (buffer.compare("endif") == 0 ) || (buffer.compare("while") == 0 ) || (buffer.compare("whileend") == 0 ) || (buffer.compare("doend") == 0 )
 || (buffer.compare("output") == 0 ) || (buffer.compare("return") == 0 ) || (buffer.compare("function") == 0 )) {
  return true;
}
return false;
}

bool identifier_state(std::string buffer){ // Checks if buffer is identifier
  if(buffer == ""){
    return false;
  }
  if(keyword_state(buffer)){ // In case of false positive
    return false;
  }
  if(isdigit(buffer[0])){
    return false;
  }
  for(int i = 1; i < buffer.length(); i++){
     if(!isalpha(buffer[i]) && !isdigit(buffer[i]) && buffer[i] != '$'){ // Makes sure buffer does not contain characters that are not allowed
      return false;
    }
  }
  return true;
}

bool separator_state(char bufferchar){
  if((bufferchar == '\'') || (bufferchar == '(') || (bufferchar == ')') || (bufferchar == '{') // Checks if char contains separator
  || (bufferchar == '}') || (bufferchar == '[') || (bufferchar == ']') || (bufferchar == ',')
  || (bufferchar == '.') || (bufferchar == ':') || (bufferchar == ';')){
    return true;
}
return false;
}

bool operator_state(char charbuffer){ // Checks if char contains operator
if((charbuffer == '*') || (charbuffer == '+') || (charbuffer == '-') || (charbuffer == '=') || (charbuffer == '/')
|| (charbuffer == '>') || (charbuffer == '<') || (charbuffer == '%')){
  return true;
}
return false;
}

int getChar(int previous, char current){ // Calls previous functions to properly categorize char into string, integer, real, etc
  if (previous == OPERATOR || previous == KEYWORD){
    if(isdigit(current)){
      return INTEGER;
    }
  }
  else if (previous == STRING){
    if(isalpha(current) || current == '$' || isdigit(current)){
      return STRING;
    }
  }

  else if(previous == INTEGER){
    if(isdigit(current)){
      return INTEGER;
    }
    else if(current == '.'){
      return REAL;
    }
  }
  else if(previous == REAL){
    if(isdigit(current)){
      return REAL;
    }
  }
  if(isalpha(current)){ // Block checks for string, separator, operator, or integer after previous block has failed
    return STRING;
  }
  else if(separator_state(current)){
    return SEPARATOR;
  }
  else if(operator_state(current)){
  return OPERATOR;
  }
  else if(isdigit(current)){
    return INTEGER;
  }
  return RESET;
}

std::string getname(int myint){ // Used to convert integer into string that can then be stored in token vector
  switch(myint){
    case KEYWORD:
      return "Keyword";
      break;
    case IDENTIFIER:
      return "Identifier";
      break;
    case SEPARATOR:
      return "Separator";
      break;
    case OPERATOR:
      return "Operator";
      break;
    case INTEGER:
      return "Integer";
      break;
    case REAL:
      return "Real";
      break;
    case STRING:
      return "String";
      break;
    case RESET:
      return "Reset";
      break;
    default:
      return "Error";
      break;
  }
}

void term_function(token token1){ // Checks for syntax in token. If not identifier, returns error
  if(identifier_state(token1.token) || token1.token_name == "Integer"){

    output << "<Term> -> <Factor> <Term Prime> <Factor> -> <Identifier>" << std::endl;
    return;
  }
  else{
    output << "Invalid Syntax (term)" << std::endl;
    exit(0);
  }
}

void term_prime(std::vector<token> token_vector){ // Checks syntax for terms prime. Also calls term function
  if(token_vector[0].token == "*"|| token_vector[0].token == "/") {
    output << "<Empty> -> Epsilon\n<TermPrime> -> * <Factor> <TermPrime> | / <Factor> <TermPrime> | <Empty>" << std::endl;
    token_vector.erase(token_vector.begin());
    term_function(token_vector[0]);
  }
  else{
    output << "<Term Prime> -> Epsilon" << std::endl;
    return;
  }
}

void expressionPrime(std::vector<token> token_vector) // Checks for expresion prime. Also calls term function and term prime
{
	if (token_vector[0].token == "*" || token_vector[0].token == "/" || token_vector[0].token == ";")
	{
    output << "Test 6 Token: " << token_vector[0].token_name << "\t\t" << "Lexeme: " << token_vector[0].token << std::endl;
		term_prime(token_vector);
	}

	if (token_vector[0].token == "+" || token_vector[0].token == "-")
	{
		output << "<ExpressionPrime> -> + <Term> <ExpressionPrime> | - <Term> <ExpressionPrime> | <Empty> " << std::endl;
    token_vector.erase(token_vector.begin());
		output << "Test 4 Token: " << token_vector[0].token_name << "\t\t" << "Lexeme: " << token_vector[0].token << std::endl;
		term_function(token_vector[0]);
    token_vector.erase(token_vector.begin());
		expressionPrime(token_vector);
	}
	else
	{
		output << "<Expression Prime> -> Epsilon" << std::endl;
    return;
	}

}

void expressions(std::vector<token> token_vector) { // Checks for expressions in syntax. Also calls term function and expression prime
	output << "Test 3 Token: " << token_vector[0].token_name << "\t\t" << "Lexeme: " << token_vector[0].token << std::endl;
	output << "<Expression> -> <Term> <Expression Prime>" << std::endl;
	term_function(token_vector[0]);
  token_vector.erase(token_vector.begin());
  output << "Test 3 Token: " << token_vector[0].token_name << "\t\t" << "Lexeme: " << token_vector[0].token << std::endl;
	expressionPrime(token_vector);
	return;
}

void checkSyntax(std::vector<token> token_vector) { // Uses while loop as long as token does not contain identifier
  while(!identifier_state(token_vector[0].token)) {
    output << "Test 1 Token: " << token_vector[0].token_name << "\t\t" << "Lexeme: " << token_vector[0].token << std::endl;
    token_vector.erase(token_vector.begin());
  }
  if(token_vector[0].token_name != " " && token_vector[0].token != "}" && token_vector[0].token != "(" && token_vector[0].token != ";"){
    output << "Test 2 Token: " << token_vector[0].token_name << "\t\t" << "Lexeme: " << token_vector[0].token << std::endl; // Gets to this block if token contains identifier
    output << "<Statement> -> <Assign>\n<Assign> -> <Identifier> = <Expression>" << std::endl;
    token_vector.erase(token_vector.begin());

  if(token_vector[0].token == "=" || token_vector[0].token == "(" || token_vector[0].token == ")" || token_vector[0].token == "+" || token_vector[0].token == "-" || token_vector[0].token == "{" || token_vector[0].token_name == "}"
  || token_vector[0].token == "*" || token_vector[0].token == "/" || token_vector[0].token == ";" || token_vector[0].token == ",") {
      output << "Test 8 Token: " << token_vector[0].token_name << "\t\t" << "Lexeme: " << token_vector[0].token << std::endl;
      token_vector.erase(token_vector.begin());
    }
    else {
      output << "Invalid Syntax (checkSyn)." << std::endl; // Shows invalid syntax if code reaches this point
      exit(0);
    }
}

  expressions(token_vector);

}

void symbolTable(std::vector<token> token_vector) { // Used to store results

  int mem_loc = 5000;
  output << "Symbol Table" << std::endl;
  output << "Identifier\t\t Memory Location\t\t Type";

  while(identifier_state(token_vector[0].token)) {
    mem_loc++;
    output << token_vector[0].token_name << "\t\t" + mem_loc << "\t\t" + token_vector[0].token << std::endl;
  }
}
