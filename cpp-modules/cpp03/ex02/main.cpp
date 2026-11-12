#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap ft("Frag1");
	ft.attack("the pc");
	ft.highFivesGuys();
	ft.takeDamage(40);
	ft.beRepaired(20);

	return 0;
}
