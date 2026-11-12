
#include <string>

#ifndef DATA_HPP
#define DATA_HPP

class Data
{
	private:
		std::string data;
	public:
		Data();
		Data(const std::string& data);
		Data(const Data& other);
		Data& operator=(const Data& other);
		~Data();

	std::string getData();
};

#endif
