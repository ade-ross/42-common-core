#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>


ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &)
{
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &literal)
{
	double value = 0.0;

	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		value = static_cast<double>(literal[0]);
	}
	else if (literal == "nanf" || literal == "+inff" || literal == "-inff")
	{
		value = static_cast<double>(std::strtof(literal.c_str(), NULL));
	}
	else if (literal == "nan" || literal == "+inf" || literal == "-inf")
	{
		value = std::strtod(literal.c_str(), NULL);
	}
	else
	{
		char *end;
		value = std::strtod(literal.c_str(), &end);
		if (!((*end == 'f' && *(end + 1) == '\0') || *end == '\0'))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}

	if (value < 0 || value > 127 || value != value)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || value != value)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;


	float floatPart;
	int intPart = (int) value;
	floatPart = value - intPart;
	if (floatPart == 0 && (intPart / 1000000 == 0))
		std::cout << "float: " << static_cast<float>(value) << ".0" << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;

	if (floatPart == 0 && (intPart / 1000000 == 0))
		std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(value) << std::endl;
}
