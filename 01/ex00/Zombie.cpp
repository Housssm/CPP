#include  "Zombie.hpp"


Zombie::Zombie(const std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << "the zombie " << _name << " is dead" << std::endl;
}

void	Zombie::annonce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name)
{
	return new Zombie(name);
}

void	randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.annonce();
}