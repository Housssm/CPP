#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main ()
{

	// AAnimal test;
	// AAnimal*test = new AAnimal();

	const AAnimal* i = new Dog();
	const AAnimal* j = new Cat();
	std::cout << std::endl;

	delete(i);
	delete(j);

	return (0);
}
