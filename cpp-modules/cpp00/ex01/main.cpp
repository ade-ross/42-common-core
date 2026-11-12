
#include "utils.h"

int main()
{
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		std::cout << "Enter a command: ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "EXIT" << std::endl;
			break;
		}
		if (command == "ADD")
		{
			add_contact(phonebook);
		}
		else if (command == "SEARCH")
		{
			display_contacts(phonebook);
		}
		else if (command == "EXIT")
			break;
		else
		{
			std::cout << "Unknown command. Please enter ADD, SEARCH or EXIT." << std::endl;
		}
	}
	return 0;
}
