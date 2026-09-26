#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie*  horde = new Zombie[N];
	for (int i = 0; i <= N - 1; i++)
		horde[i].SetName(name);
	return horde;

}