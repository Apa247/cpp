/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:18:43 by daparici          #+#    #+#             */
/*   Updated: 2024/09/30 21:02:04 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//------------------ Constructors ------------------//

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
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
}

//------------------ Operator ------------------//

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

//------------------ Member functions ------------------//

void Dog::makeSound() const
{
	std::cout << this->_type << " says: ¡¡Guau Guau!!!" << std::endl;
}