/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:31:10 by daparici          #+#    #+#             */
/*   Updated: 2024/09/27 11:12:44 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//-------------------------- Constructor --------------------------

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
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
		this->_HitPoints = rhs._HitPoints;
		this->_EnergyPoints = rhs._EnergyPoints;
		this->_AttackDamage = rhs._AttackDamage;
	}
	return (*this);
}

//--------------------------------- Member function ----------------------------

void	ClapTrap::attack(std::string const & target)
{
	if (this->_EnergyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << "\033[31m has no energy points left!\033[0m" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << "\033[31m attack " << target << ", causing " << this->_AttackDamage << " points of damage!\033[0m" << std::endl;
	this->_EnergyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << "\033[33m is already dead!\033[0m" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << "\033[33m take " << amount << " points of damage!\033[0m" << std::endl;
	this->_HitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_HitPoints == 10)
	{
		std::cout << "ClapTrap " << this->_name << "\033[32m is already full health!\033[0m" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << "\033[32m be repaired " << amount << " points of health!\033[0m" << std::endl;
	this->_HitPoints += amount;
}