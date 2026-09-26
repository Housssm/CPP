#include  "Zombie.hpp"


Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << "the zombie " << _name << " is dead" << std::endl;
}

void	Zombie::annonce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Zombie* newZombie(std::string name)
// {
// 	return new Zombie(name);
// }

// void	randomChump(std::string name)
// {
// 	Zombie zombie(name);
// 	zombie.annonce();
// }

void Zombie::SetName(std::string name)
{
	_name = name;
}
