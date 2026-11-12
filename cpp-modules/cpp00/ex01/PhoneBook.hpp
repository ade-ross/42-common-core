
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
	Contact contacts[8];
	int i;
	int size;

	public:
	PhoneBook();
	~PhoneBook();

	void	addContact(Contact new_contact);

	Contact	*getContacts();

	int	getSize();
};

#endif
