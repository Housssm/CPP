#include "Iter.hpp"


void	add(int &i)
{
	i += 1;
}

void	suffix(std::string &value)
{
	value = value + "ix";
}

template<typename T>
void	Print(const T &value)
{
	std::cout << value << std::endl;
}

int main ()
{
	std::cout << "\n---TEST SIMPLE ---" << std::endl;

	int num[4] = {1,3,5,7};
	std::string word[3] = {"Idef", "Obel", "Panoram"};
	
	iter(num, 4, add);
	iter(word, 3, suffix);
	iter(num, 4, Print<int>);
	iter(word, 3, Print<std::string>);

	std::cout << "\n---TEST TABLEAU CONST/VIDE ---" << std::endl;

	const int num2[4] = {10,30,40,50};
	int	empty_arr[1] = {0};

	iter(empty_arr, 0, add);
	iter(num2, 4, Print<int>);
	iter(empty_arr, 0, Print<int>);
	
	
	return 0;
}