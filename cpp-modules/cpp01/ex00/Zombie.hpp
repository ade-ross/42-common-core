
#include <iostream>

class	Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string new_name);
		~Zombie();
		void	announce();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);