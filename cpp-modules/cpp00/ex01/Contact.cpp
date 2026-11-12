
#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::addFirstName(std::string name)
{
	first_name = name;
}

void	Contact::addLastName(std::string name)
{
	nickname = name;
}

void	Contact::addNickName(std::string name)
{
	last_name = name;
}

void	Contact::addDarkestSecret(std::string name)
{
	darkest_secret = name;
}

void	Contact::addPhoneNumber(std::string name)
{
	phone_number = name;
}

std::string	Contact::getFirstName()
{
	return(first_name);
}

std::string	Contact::getLastName()
{
	return(nickname);
}

std::string	Contact::getNickName()
{
	return(last_name);
}

std::string	Contact::getDarkestSecret()
{
	return(darkest_secret);
}

std::string	Contact::getPhoneNumber()
{
	return(phone_number);
}
