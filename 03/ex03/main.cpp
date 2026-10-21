#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "\n------------------------" << std::endl;
	std::cout << "--- Test diamondtrap ---" << std::endl;
	std::cout << "------------------------" << std::endl;

	DiamondTrap dt("Dia");
	DiamondTrap dt_copy("Clone");

	std::cout << "\n--- Test whoAmI ---" << std::endl;
	dt.whoAmI();

	std::cout << "\n--- Statistiques de DiamondTrap ---" << std::endl;
	std::cout << "PV: " << dt.getHit() << ", energy: " << dt.getEnergy() << ", attack: " << dt.getAttack() << std::endl;

	std::cout << "\n--- Test Attaque & Aptitudes speciales ---" << std::endl;
	dt.attack("cible d'entrainement");
	std::cout << "PV: " << dt.getHit() << ", energy: " << dt.getEnergy() << std::endl;

	// Test des deux aptitudes héritées
	dt.guardGate();
	dt.highFivesGuys();

	// Test dégâts et réparation
	dt.takeDamage(25);
	dt.beRepaired(10);
	std::cout << "PV: " << dt.getHit() << ", energy: " << dt.getEnergy() << std::endl;

	std::cout << "\n--- Test affectation DiamondTrap ---" << std::endl;
	dt_copy = dt;
	dt_copy.whoAmI();
	std::cout << "PV copie: " << dt_copy.getHit() << ", energy copie: " << dt_copy.getEnergy() << std::endl;

	// Test DiamondTrap détruit (0 PV)
	std::cout << "\n--- Test DiamondTrap PV a 0 ---" << std::endl;
	dt.takeDamage(150);
	std::cout << "PV: " << dt.getHit() << ", energy: " << dt.getEnergy() << std::endl;
	dt.attack("cible");
	dt.beRepaired(10);

	std::cout << "\n--- Fin des tests (Destructions LIFO) ---" << std::endl;
	return 0;
}