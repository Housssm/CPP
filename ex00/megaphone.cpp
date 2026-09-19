#include <iostream>

int	main(int ac, char **av){

	if (ac > 2 )
	{
		int j = 1;
		while (av[j])
		{
			int i = 0;
			while (av[j][i])
				std::cout << (char)std::toupper(av[j][i++]);
			j++;
			std::cout << " ";
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
}
