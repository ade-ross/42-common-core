
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
	public:
		MutantStack() : std::stack<T, std::deque<T> >() {}
		MutantStack(const MutantStack& other) : std::stack<T, std::deque<T> >(other) {}
		MutantStack& operator=(const MutantStack& other)
		{
			if (this != &other)
				std::stack<T, std::deque<T> >::operator=(other);
			return *this;
		}
		~MutantStack() {}

		typedef typename std::deque<T>::iterator iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

};

#endif
