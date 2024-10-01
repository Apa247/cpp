/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:18:36 by daparici          #+#    #+#             */
/*   Updated: 2024/09/30 21:57:24 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &cpy)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = cpy;
}

// Destructor

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

// Operator

Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << "Animal Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

// Member functions

void Animal::makeSound() const
{
	std::cout << this->getType() << " says: ¡¡Animal sound!!" << std::endl;
}

// Getters

std::string Animal::getType() const
{
	return this->_type;
}