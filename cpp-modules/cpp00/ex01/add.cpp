
#include "utils.h"

std::string	get_validated_phone_number(const std::string& prompt)
{
	std::string input = "+";
	bool valid;

	do
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			break;
		valid = !input.empty();

		// Example validation: allow '+' only as first char, rest must be digits
		if (valid)
		{
			std::size_t i = 0;
			if (input[0] == '+')
				i++;
			while (i < input.size())
			{
				if (!(input[i] >= '0' && input[i] < '9'))
				{
					valid = false;
					break;
				}
				i++;
			}
		}
		if (!valid) {
			std::cout << "Invalid phone number. Please enter digits only (optionally starting with '+')." << std::endl;
		}
	} while (!valid);

	return input;
}

std::string	get_not_empty_input(const std::string& prompt)
{
	std::string input = ".";
	do
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			break;
		if (input.empty())
		{
			std::cout << "This field cannot be empty. Please enter a valid input." << std::endl;
		}
	} while (input.empty());
	return input;
}

Contact	create_contact(void)
{
	Contact newContact;

	newContact.addFirstName(get_not_empty_input("Enter first name: "));
	newContact.addLastName(get_not_empty_input("Enter last name: "));
	newContact.addNickName(get_not_empty_input("Enter nickname: "));
	newContact.addDarkestSecret(get_not_empty_input("Enter darkest secret: "));
	newContact.addPhoneNumber(get_validated_phone_number("Enter phone number: "));

	//std::cout << "Contact added successfully!" << std::endl;
	return (newContact);
}

void	add_contact(PhoneBook& phonebook)
{
	Contact new_contact;

	new_contact = create_contact();
	phonebook.addContact(new_contact);
}
