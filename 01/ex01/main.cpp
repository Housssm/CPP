#include "Zombie.hpp"

int main()
{
	Zombie* horde = zombieHorde(5,"Foo");

	for ( int i = 0; i < 5; i++)
		horde[i].annonce();
	delete[] horde;
	return (0);
}