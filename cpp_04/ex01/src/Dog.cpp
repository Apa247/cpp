/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:18:43 by daparici          #+#    #+#             */
/*   Updated: 2024/10/01 20:02:03 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//------------------ Constructors ------------------//

Dog::Dog() : Animal()
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Dog Brain error allocating memory");
		std::cerr << "Exiting..." << std::endl;
		exit(EXIT_FAILURE);
	}
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = cpy;
}

//------------------ Destructor ------------------//

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->_brain;
}

//------------------ Operator ------------------//

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = new Brain();
		if (this->_brain == NULL)
		{
			perror("Dog Brain error allocating memory");
			std::cerr << "Exiting..." << std::endl;
			exit(EXIT_FAILURE);
		}
		*this->_brain = *rhs._brain;
	}
	return *this;
}

//------------------ Member functions ------------------//

void Dog::makeSound() const
{
	std::cout << this->_type << " says: ¡¡Guau Guau!!!" << std::endl;
}

//------------------ Getters ------------------//

void	Dog::getIdea(void) const
{
	for (int i = 0; i < 3; i++)// change the 3 to 100 to show all ideas
		if (this->_brain->getIdea(i).length() > 0)
			std::cout << "\tIdea " << i << " of the Dog is: \"" << this->_brain->getIdea(i) << "\" at the address " << this->_brain->getIdeaAdress(i) << std::endl;
}

//------------------ Setters ------------------//

void	Dog::setIdea(std::string idea, size_t i)
{
	this->_brain->setIdea(i, idea);
}