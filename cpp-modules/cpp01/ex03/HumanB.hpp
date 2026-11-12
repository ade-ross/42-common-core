
#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string name;
		Weapon* weapon;
	public:
		HumanB(std::string new_name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon& new_weapon);
};