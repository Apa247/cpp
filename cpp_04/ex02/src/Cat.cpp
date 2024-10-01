/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:18:38 by daparici          #+#    #+#             */
/*   Updated: 2024/10/01 23:05:30 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//------------------ Constructors ------------------//

Cat::Cat() : Animal()
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Cat Brain error allocating memory");
		std::cerr << "Exiting..." << std::endl;
		exit(EXIT_FAILURE);
	}
	
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = cpy;
}

//------------------ Destructor ------------------//

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat Destructor called" << std::endl;
}

//------------------ Operator ------------------//

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = new Brain();
		if (this->_brain == NULL)
		{
			perror("Cat Brain error allocating memory");
			std::cerr << "Exiting..." << std::endl;
			exit(EXIT_FAILURE);
		}
		*this->_brain = *rhs._brain;
	}
	return *this;
}

//------------------ Member functions ------------------//

void Cat::makeSound() const
{
	std::cout << this->_type << " says: ¡¡Miau Miau!!!" << std::endl;
}

//------------------ Getters ------------------//

void Cat::getIdea(void) const
{
	for (int i = 0; i < 100; i++)
		if (this->_brain->getIdea(i) != "")
			std::cout << "\tIdea " << i << " of the Cat is: \"" << this->_brain->getIdea(i) << "\" at the address " << this->_brain->getIdeaAdress(i) << std::endl;
} 

//------------------ Setters ------------------//

void Cat::setIdea(const std::string idea, size_t i)
{
	this->_brain->setIdea(i, idea);
}