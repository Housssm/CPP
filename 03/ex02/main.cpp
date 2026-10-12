#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	// ClapTrap a("Alpha");
	// ClapTrap b("Beta");

	// std::cout << "PV: " << a.getHit() << ", energy: " << a.getEnergy() << std::endl;
	// a.takeDamage(4);
	// a.attack("target");
	// std::cout << "PV: " << a.getHit() << ", energy: " << a.getEnergy() << std::endl;

	// std::cout << "\n--- Test Opérateur d'affectation (b = a) ---" << std::endl;
	// b = a;

	// std::cout << "\n--- Vérification du comportement de b ---" << std::endl;
	// b.attack("un mannequin");
	// b.beRepaired(2);
	// std::cout << "PV: " << b.getHit() << ", energy: " << b.getEnergy() << std::endl;


	// std::cout << "\n--- Test d'auto-assignation  ---" << std::endl;
	// a = a;

	// std::cout << "\n--- Test scavtrap  ---\n" << std::endl;
	
	// ScavTrap sa("Scav");

	// std::cout << "PV: " << sa.getHit() << ", energy: " << sa.getEnergy() << std::endl;
	// sa.guardGate();
	// sa.attack("A");


	std::cout << "\n--- Test fragtrap  ---\n" << std::endl;
	FragTrap fg("Frag");
	fg.highFivesGuys();
	fg.attack("ScavTrap");

	return 0;
}