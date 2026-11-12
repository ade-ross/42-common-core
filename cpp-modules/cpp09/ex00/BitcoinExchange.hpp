
#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <limits>
#include <iomanip>
#include <map>

//parseline
bool isValidYear(std::string line);
bool isLeapYear(int year);
bool isValidDay(std::string line, int month);
bool isValidMonthAndDay(std::string line);
bool stringToInt(const std::string s, float &result);
bool parseLine(std::string line, float &lastnumber);

//BitcoinExchange
void searchInDatabase(std::string lineToSearch, std::map<std::string, float> btc_values, float numberToMultiply);
bool loadDatabase(std::map<std::string, float> & db);

#endif
