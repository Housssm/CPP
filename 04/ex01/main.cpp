#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main ()
{
	std::cout <<std::endl ;
	std::cout << "-------------ARRAY OF ANIMALS----------------"<<std::endl ;
	std::cout <<std::endl ;

	const Animal* animals[10];
	for(int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout <<std::endl ;

	for(int i = 0; i < 10; i++)
	{
		delete(animals[i]);
	}

	std::cout <<std::endl ;
	std::cout << "-------------TEST FOR DEEP COPIES----------------"<<std::endl ;
	std::cout << "-------------------------DOG-----------------"<<std::endl ;
	std::cout <<std::endl ;

	Dog* Medor_O = new Dog();
	Medor_O->setIdea( "Manger un os", 0);
	std::cout << Medor_O->getIdea(0) << std::endl;
	std::cout <<std::endl ;

	Dog* Rex_C = new Dog(*Medor_O);
	Rex_C->setIdea("Cours dans les bois", 0);
	std::cout <<std::endl ;

	std::cout << "Medor: " << Medor_O->getIdea(0) << std::endl;
	std::cout << "Rex  : " << Rex_C->getIdea(0) << std::endl; // preuve de la copie profonde les deux ne sont pas pareil
	std::cout <<std::endl ;

	delete(Medor_O);
	std::cout <<std::endl ;
	delete(Rex_C);

	std::cout <<std::endl ;
	std::cout << "------------CAT-----------------"<<std::endl ;
	std::cout <<std::endl ;

	Cat* Felix = new Cat();
	Felix->setIdea( "Manger un poisson", 0);
	std::cout << Felix->getIdea(0) << std::endl;
	std::cout <<std::endl ;

	Cat* Garfield = new Cat(*Felix);
	Garfield->setIdea("Mange des lasagnes", 0);
	std::cout <<std::endl ;

	std::cout << "Felix        : " << Felix->getIdea(0) << std::endl;
	std::cout << "Garfield     : " << Garfield->getIdea(0) << std::endl; // preuve de la copie profonde les deux ne sont pas pareil
	std::cout <<std::endl ;

	delete(Felix);
	std::cout <<std::endl ;
	delete(Garfield);

	std::cout <<std::endl ;
	std::cout << "-----------------------------"<<std::endl ;
	std::cout <<std::endl ;

	return (0);
}