#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <iostream>
# include <iterator>

class Span {
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		~Span();

		Span&	operator=(const Span& other);

		void	addNumber(int number);

		template <typename InputIterator>
		void	addNumbers(InputIterator begin, InputIterator end) {
			if (std::distance(begin, end) + _numbers.size() > _maxSize)
				throw std::runtime_error("Adding range would exceed max size");
			_numbers.insert(_numbers.end(), begin, end);
		}

		int		shortestSpan() const;
		int		longestSpan() const;
};

#endif
