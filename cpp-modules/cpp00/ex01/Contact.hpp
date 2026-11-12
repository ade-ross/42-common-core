
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	darkest_secret;
	std::string	phone_number;

	public:
	Contact();
	~Contact();

void	addFirstName(std::string name);

void	addLastName(std::string name);

void	addNickName(std::string name);

void	addDarkestSecret(std::string name);

void	addPhoneNumber(std::string name);

std::string	getFirstName();

std::string	getLastName();

std::string	getNickName();

std::string	getDarkestSecret();

std::string	getPhoneNumber();

};

#endif
