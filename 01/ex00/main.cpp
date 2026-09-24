#include "Zombie.hpp"

int main()
{
	randomChump("pierre");
	Zombie* Paul = newZombie("paul");

	Paul->annonce();
	delete(Paul);
	return (0);
}