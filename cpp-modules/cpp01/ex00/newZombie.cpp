
#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
    Zombie* zomb = new Zombie(name); // allocate on heap
    return (zomb);                     // return pointer
}
