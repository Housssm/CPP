#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 99;i ++)
		ideas[i] = other.ideas[i];
	std::cout << "Brain copy called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i <= 99;i ++)
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain operator called" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdeas(const std::string& idea, int index)
{
	if(index < 0 || index > 99)
	{
		std::cout << "Invalid idea index!" << std::endl;
		return;
	}
	ideas[index]= idea;
}

std::string Brain::getIdeas(int index) const
{
	if(index < 0 || index > 99)
	{
		std::cout << "Invalid idea index!" << std::endl;
		return "";
	}
	return ideas[index];
}