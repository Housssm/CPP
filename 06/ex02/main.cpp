#include "Base.hpp"

int main()
{
	std::srand(std::time(NULL));

	std::cout << "\n-------test pointer-----------\n" << std::endl;
	Base* first = generate();
	identify(first);
	Base* second = generate();
	identify(second);
	Base* third = generate();
	identify(third);

	std::cout << "\n-------test reference---------\n" << std::endl;
	Base* first_bis = generate();
	identify(*first_bis);
	Base* second_bis = generate();
	identify(*second_bis);
	Base* third_bis = generate();
	identify(*third_bis);


	delete (first);
	delete (second);
	delete (third);
	delete (first_bis);
	delete (second_bis);
	delete (third_bis);
	
	return 0;
}