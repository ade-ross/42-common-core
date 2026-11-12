
#include "utils.h"

void	print_string_and_pipe(std::string temp)
{
	int	j = 0;

	while(temp[j] && j < 9)
	{
		std::cout << temp[j];
		j++;
	}
	if (j == 9)
		std::cout << ".";
	else
	{
		while(j < 10)
		{
			std::cout << " ";
			j++;
		}
	}
	std::cout << "|";
}

std::string	ask_wich_contact(const std::string& prompt, int size)
{
	std::string input = "0";

	do
	{
		std::cout << prompt;
		if(!std::getline(std::cin, input))
			break;
		else if(input.empty() || (!((input[0] >= '1' && input[0] <= '8') && input.size() == 1)))
		{
				std::cout << "This field must be a number between 1 and 8" << std::endl;
		}
		else if ((input[0] > (size + 48) && input[0] <= '8') && input.size() == 1)
		{
			std::cout << "only " << size << " contacts present" << std::endl;
		}
	} while (input.empty() || !((input[0] >= '1' && input[0] <= (size + 48)) && input.size() == 1));
	return (input);
}

void	print_all_contacts(Contact *contacts, int size)
{
	int			i;
	std::string	temp;

	for (i = 0; i < size; i++)
	{
		std::cout << (i + 1);
		for (int j = 1; j < 10; j++)
			std::cout << " ";
		std::cout << "|";
		temp = contacts[i].getFirstName();
		print_string_and_pipe(temp);
		temp = contacts[i].getLastName();
		print_string_and_pipe(temp);
		temp =  contacts[i].getNickName();
		print_string_and_pipe(temp);
		std::cout << std::endl;
	}
}


void	show_single_contact(Contact *contacts, int i)
{
	std::string	temp;

		std::cout << (i + 1) << std::endl;
		temp = contacts[i].getFirstName();
		std::cout << temp << std::endl;
		temp = contacts[i].getLastName();
		std::cout << temp << std::endl;
		temp =  contacts[i].getNickName();
		std::cout << temp << std::endl;
		temp =  contacts[i].getDarkestSecret();
		std::cout << temp << std::endl;
		temp =  contacts[i].getPhoneNumber();
		std::cout << temp;
		std::cout << std::endl;
}

void	display_contacts(PhoneBook phonebook)
{
	Contact		*contacts;
	int			size;
	std::string	temp;
	int			i = 0;

	contacts = phonebook.getContacts();
	size = phonebook.getSize();
	if (size == 0)
	{
		std::cout << "No contacts are present" << std::endl;
	}
	else
	{
		print_all_contacts(contacts, size);
		temp = ask_wich_contact("Wich contact do you want to see? ", size);
		i = temp[0] - 49;
		if (i >= 0 && i < phonebook.getSize())
			show_single_contact(contacts, i);
	}
}
