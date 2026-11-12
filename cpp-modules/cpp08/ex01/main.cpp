
#include "Span.hpp"
#include <list>
int main() {

	//subject test
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl; // Should print 2
	std::cout << sp.longestSpan() << std::endl;  // Should print 14


	//test with 10000 numbers
	Span bigSpan(10000);
	std::vector<int> manyNumbers;
	
	for (int i = 0; i < 10000; ++i)
		manyNumbers.push_back(i * 3);

	bigSpan.addNumbers(manyNumbers.begin(), manyNumbers.end());

	std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;


	return 0;
}
