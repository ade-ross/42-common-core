
#include <iostream>
#include "Data.hpp"

Data::Data() : data("")
{
}

Data::Data(const Data& other) : data(other.data)
{
}
Data& Data::operator=(const Data& other)
{
	if(this != &other)
	{
		this->data = other.data;
	}
	return *this;
}

Data::Data(const std::string& newData) : data(newData)
{
}

Data::~Data()
{
}

std::string Data::getData()
{
	return this->data;
}
