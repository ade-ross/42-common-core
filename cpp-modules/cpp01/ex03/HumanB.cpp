
#include "HumanB.hpp"

HumanB::HumanB(std::string new_name) : name(new_name), weapon(NULL) {}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon& new_weapon)
{
	weapon = &new_weapon;
}

void	HumanB::attack()
{
	if (weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon" << std::endl;
}