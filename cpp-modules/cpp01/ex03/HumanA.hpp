
#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string name;
		Weapon* weapon;
	public:
		HumanA(std::string new_name, Weapon& new_weapon);
		~HumanA();
		void	attack();
};