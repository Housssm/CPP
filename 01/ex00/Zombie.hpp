#pragma once
#include <iostream>
#include <string>

class Zombie
{
	public :

	Zombie(std::string name);
	~Zombie();
	void annonce (void);

	private : 

	std::string	_name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);
