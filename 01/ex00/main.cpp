#include "Zombie.hpp"

int main()
{
	randomChump("");
	Zombie* Paul = newZombie("paul");

	Paul->annonce();
	delete(Paul);
	return (0);
}