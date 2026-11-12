
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>
#include <stdint.h>

//parsing
void skipSpaces(char * line, int & i);
bool parsing(char** argv, std::vector<int> & numbersv, std::deque<int> & numbersd);

//sortVector
void binaryInsert(std::vector<int> & numbers, std::vector<int> & temp, int max, int level);
void insertLosers(std::vector<int> & numbers, int level, int *jacobsthal);
std::vector<int> sortVector(std::vector<int> numbers, int *jacobsthal, size_t level);

//sortDeque
void binaryInsertDeq(std::deque<int> & numbers, std::deque<int> & temp, int max, int level);
void insertLosersDeq(std::deque<int> & numbers, int level, int *jacobsthal);
std::deque<int> sortDeque(std::deque<int> numbers, int *jacobsthal, size_t level);

//PmeergeMe
int *Jacobsthal(int *arr, int size);
int64_t timeInMicroseconds(const timeval& t);

#endif
