#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

	std::cout << "---TEST LECTURE ET ECRITURE---" << std::endl;
	Array<int> arr(3);

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;

	std::cout << "arr[0] = " << arr[0] << std::endl;
	std::cout << "arr[1] = " << arr[1] << std::endl;
	std::cout << "arr[2] = " << arr[2] << std::endl;

	arr[0] += 5;
	std::cout << "Apres modification, arr[0] = " << arr[0] << std::endl;


	std::cout << "\n---TEST LECTURE SEULE---" << std::endl;
	const Array<int> const_arr(arr);

	std::cout << "const_arr[0] = " << const_arr[0] << std::endl;
	std::cout << "const_arr[1] = " << const_arr[1] << std::endl;

	return 0;
}