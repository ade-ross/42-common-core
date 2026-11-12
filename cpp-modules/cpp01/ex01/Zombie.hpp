
#include <iostream>

class	Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string new_name);
		~Zombie();
		void	setname(std::string new_name);
		void	announce();
};
Zombie*	zombieHorde(int N, std::string name);