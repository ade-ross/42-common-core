
#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string new_name)
{
	name = new_name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " destroyed!" << std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setname(std::string new_name)
{
	name = new_name;
}