#pragma once
#include <iostream>
#include <string>

class Zombie
{
	public :

	Zombie();
	~Zombie();
	void 	annonce (void);
	void	SetName(const std::string name);
	
	private : 

	std::string	_name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);
Zombie* zombieHorde( int N, std::string name );
