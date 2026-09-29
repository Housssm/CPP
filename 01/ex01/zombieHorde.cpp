#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return NULL;

	Zombie*  horde = NULL;
	try 
	{horde = new Zombie[N];}
	catch(const std::bad_alloc&)
	{return NULL;}
	for (int i = 0; i <= N - 1; i++)
		horde[i].SetName(name);
	return horde;
}
