/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:18:45 by daparici          #+#    #+#             */
/*   Updated: 2024/09/30 21:01:10 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//------------------ Constructors ------------------//

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = cpy;
}

//------------------ Destructor ------------------//

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

//------------------ Operator ------------------//

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << "WrongAnimal Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

//------------------ Member functions ------------------//

void WrongAnimal::makeSound() const
{
	std::cout << this->getType() << " says: ¡¡WrongAnimal sound!!" << std::endl;
}

// Getters

std::string WrongAnimal::getType() const
{
	return this->_type;
}