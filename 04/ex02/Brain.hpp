#pragma once
#include "AAnimal.hpp"

class Brain
{
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		virtual ~Brain();

		void		setIdeas(const std::string& idea, int index);
		std::string	getIdeas(int index) const;

	private :
		std::string ideas[100];
};