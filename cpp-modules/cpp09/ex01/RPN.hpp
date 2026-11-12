
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stack>

bool checkLineIsValid(std::string & line);
void skipSpaces(std::string line, int & i);
bool getNumFromStack(std::stack<int> & numbers, int & number);
bool executeRPN(std::stack<int> & numbers, std::string & line);

#endif
