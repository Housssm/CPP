#include "whatever.hpp"

int main( void ) 
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	
	return 0;
}




// int main()
// {
// 	//test niveau 1
// 	std::cout << "--------------TEST SWAP----------" << std::endl;
// 	int a = 3;
// 	int b = 7;
// 	std::cout << "Avant swap (int) : a = " << a << ", b = " << b << std::endl;
// 	::swap(a, b);
// 	std::cout << "Apres swap (int) : a = " << a << ", b = " << b << std::endl;
// 	std::cout << std::endl;

// 	double d1 = 3.5;
// 	double d2 = 7.5;
// 	std::cout << "Avant swap (double) : d1 = " << d1 << ", d2 = " << d2 << std::endl;
// 	::swap(d1, d2);
// 	std::cout << "Apres swap (double) : d1 = " << d1 << ", d2 = " << d2 << std::endl;
// 	std::cout << std::endl;

// 	char c1 = 'g';
// 	char c2 = 'e';
// 	std::cout << "Avant swap (char) : c1 = " << c1 << ", c2 = " << c2 << std::endl;
// 	::swap(c1, c2);
// 	std::cout << "Apres swap (char) : c1 = " << c1 << ", c2 = " << c2 << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "--------------TEST MAX-----------" << std::endl;
// 	std::cout << "Max of 3 and 7 is    : " << max<int>(3, 7) << std::endl;
// 	std::cout << "Max of 3.5 and 7.5 is:" << max<double>(3.5, 7.5) << std::endl;
// 	std::cout << "Max of 'g' and 'e' is: " << max<char>('g', 'e') << std::endl;
// 	std::cout << std::endl;
	
// 	std::cout << "--------------TEST MIN-----------" << std::endl;
// 	std::cout << "Min of 3 and 7 is		: " << min<int>(3, 7) << std::endl;
// 	std::cout << "Min of 3.5 and 7.5 is :" << min<double>(3.5, 7.5) << std::endl;
// 	std::cout << "Min of 'g' and 'e' is	: " << min<char>('g', 'e') << std::endl;
// 	std::cout << std::endl;
	
// 	return 0;
// }
