
#include "Zombie.hpp"

int	main()
{
	Zombie* horde = zombieHorde(5, "ciccio");
	horde[3].announce();
	delete[] horde;
}