/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:18:48 by daparici          #+#    #+#             */
/*   Updated: 2024/09/30 21:04:04 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//------------------ Constructors ------------------//

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cpy) : WrongAnimal(cpy)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = cpy;
}

//------------------ Destructor ------------------//

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

//------------------ Operator ------------------//

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "WrongCat Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

//------------------ Member functions ------------------//

void WrongCat::makeSound() const
{
	std::cout << this->_type << " says: ¡¡WrongCat sound!!" << std::endl;
}