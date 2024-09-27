/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:41:07 by daparici          #+#    #+#             */
/*   Updated: 2024/09/27 09:15:36 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//-------------------------- Constructor --------------------------

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

//------------------------------- Destructor ------------------------------

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

//----------------------------- Overload operator ----------------------------

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

//--------------------------------- Member function ----------------------------

void	ClapTrap::attack(std::string const & target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << "\033[31m has no energy points left!\033[0m" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << "\033[31m attack " << target << ", causing " << this->_attackDamage << " points of damage!\033[0m" << std::endl;
	this->_energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << "\033[33m is already dead!\033[0m" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << "\033[33m take " << amount << " points of damage!\033[0m" << std::endl;
	this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 10)
	{
		std::cout << "ClapTrap " << this->_name << "\033[32m is already full health!\033[0m" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << "\033[32m be repaired " << amount << " points of health!\033[0m" << std::endl;
	this->_hitPoints += amount;
}

