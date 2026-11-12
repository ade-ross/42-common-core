
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	const int size = 6;
	Animal* animals[size];

	for (int k = 0; k < size; k++)
	{
		if (k < size / 2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}

	animals[2]->Animal::makeSound();

	for (int k = 0; k < size; k++)
		delete animals[k];

	Dog originalDog;
	originalDog.setIdea(0, "viva i cani");
	Dog copiedDog = originalDog;

	originalDog.setIdea(0, "bu i gatti");
	std::cout << "modified idea: " << originalDog.getIdea(0) << std::endl;
	std::cout << "original copied idea: " << copiedDog.getIdea(0) << std::endl;

	return 0;
}
