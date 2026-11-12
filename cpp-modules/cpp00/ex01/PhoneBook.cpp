
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : i(0), size(0) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact(Contact new_contact)
{
	if (i == 8)
		i = 0;
	contacts[i] = new_contact;
	i++;
	if (size < 8)
		size++;
}

Contact	*PhoneBook::getContacts()
{
	Contact *contacts_arr;

	contacts_arr = contacts;
	return(contacts_arr);
}

int	PhoneBook::getSize()
{
	return(size);
}
