#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap st("Scav1");
	st.attack("the chair");
	st.takeDamage(20);
	st.beRepaired(10);
	st.guardGate();

	return 0;
}

