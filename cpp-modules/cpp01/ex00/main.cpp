
#include "Zombie.hpp"

int main()
{
    randomChump("ciccio1");
    Zombie* zomb = newZombie("ciccio2");
    zomb->announce();
    delete zomb;
}
