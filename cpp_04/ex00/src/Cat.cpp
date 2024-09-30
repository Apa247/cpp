/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:18:38 by daparici          #+#    #+#             */
/*   Updated: 2024/09/30 21:02:01 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//------------------ Constructors ------------------//

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = cpy;
}

//------------------ Destructor ------------------//

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

//------------------ Operator ------------------//

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

//------------------ Member functions ------------------//

void Cat::makeSound() const
{
	std::cout << this->_type << " says: ¡¡Miau Miau!!!" << std::endl;
}
