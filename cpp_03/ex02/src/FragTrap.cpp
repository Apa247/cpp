/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:20:49 by daparici          #+#    #+#             */
/*   Updated: 2024/09/28 00:22:16 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//------------------ Constructors ------------------//

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << this->_name << " : FragTrap default constructor" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << this->_name << " : FragTrap param constructor" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
	std::cout << this->_name << " : FragTrap copy constructor" << std::endl;
	*this = src;
}

//------------------ Destructor ------------------//

FragTrap::~FragTrap(void)
{
	std::cout << this->_name << " : FragTrap destructor" << std::endl;
}

//------------------ Operators ------------------//

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << this->_name << " : FragTrap assignation operator" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_HitPoints = rhs._HitPoints;
		this->_EnergyPoints = rhs._EnergyPoints;
		this->_AttackDamage = rhs._AttackDamage;
	}
	return (*this);
}

//------------------ Member function ------------------//

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << " : Give me a high five!!!\n\t¡¡¡¡WHASSSS!!!!*\n" << std::endl;
}