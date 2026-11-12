
#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data randomData("random wordss");

	std::cout << &randomData << std::endl;
	uintptr_t pointer = Serializer::serialize(&randomData);
	std::cout << pointer << std::endl;
	Data* deserialized_ptr = Serializer::deserialize(pointer);
	std::cout << deserialized_ptr << std::endl;
	std::cout << "data in deserialized pointer: " << deserialized_ptr->getData() << std::endl;
}
