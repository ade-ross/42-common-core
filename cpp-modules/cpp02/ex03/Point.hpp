#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();                            // Default constructor
	Point(const float x, const float y); // Param constructor
	Point(const Point& other);         // Copy constructor
	Point& operator=(const Point& other); // Copy assignment
	~Point();                          // Destructor

	Fixed getX() const;
	Fixed getY() const;
};

#endif
