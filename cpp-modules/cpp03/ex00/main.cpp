#include "ClapTrap.hpp"

int main()
{
	ClapTrap c1("Ciccio1");
	ClapTrap c2("Ciccio2");

	c1.attack("the wall");
	c2.takeDamage(3);
	c2.beRepaired(5);

	for (int i = 0; i < 11; ++i)
		c1.attack("target");

	c1.takeDamage(15);
	c1.beRepaired(3);

	return 0;
}
