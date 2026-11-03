#include "Base.hpp"


Base::~Base()
{
	// std::cout << "base destructor called" << std::endl;
}

Base*	generate(void)
{
	int choose = std::rand();

	if (choose % 3 == 0)
		return new A();
	else if (choose % 3 == 1)
		return new B();
	else
		return new C();
}

void	identify(Base* p)
{
	A* test_a = dynamic_cast<A*>(p);
	if (test_a)
		std::cout << "The object pointed to by p is A" << std::endl;

	B* test_b = dynamic_cast<B*>(p);
	if (test_b)
		std::cout << "The object pointed to by p is B" << std::endl;

	C* test_c = dynamic_cast<C*>(p);
	if (test_c)
		std::cout << "The object pointed to by p is C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& test_a = dynamic_cast<A&>(p);
		(void)test_a;
		std::cout << "Type is A" << std::endl;

	}
	catch ( const std::exception&)
	{}

	try
	{
		B& test_b = dynamic_cast<B&>(p);
		(void)test_b;
		std::cout << "Type is B" << std::endl;
	}
	catch ( const std::exception&)
	{}
	try
	{
		C& test_c = dynamic_cast<C&>(p);
		(void)test_c;
		std::cout << "Type is C" << std::endl;
	}
	catch ( const std::exception&)
	{}
}