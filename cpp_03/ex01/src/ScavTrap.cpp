/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:31:58 by daparici          #+#    #+#             */
/*   Updated: 2024/09/27 12:00:06 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

//----------------- Constructor -----------------

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << this->_name << " ScavTrap Default constructor" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	_GuardGateMode = false;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << this->_name << " ScavTrap Param constructor" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	_GuardGateMode = false;
}

ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor" << std::endl;
	*this = src;
}

//----------------- Destructor -----------------

ScavTrap::~ScavTrap(void)
{
	std::cout << this->_name << "ScavTrap Destructor" << std::endl;
}

//----------------- Operator -----------------

ScavTrap &ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "ScavTrap Assignation operator" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_HitPoints = rhs._HitPoints;
		this->_EnergyPoints = rhs._EnergyPoints;
		this->_AttackDamage = rhs._AttackDamage;
	}
	return (*this);
}

//----------------- Member function -----------------

void	ScavTrap::attack(std::string const & target)
{
	if (this->_EnergyPoints < 1)
	{
		std::cout << "ScavTrap " << this->_name << "\033[31m is out of energy!\033[0m" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << "\033[31m attack " << target << ", causing " << this->_AttackDamage << " points of damage!\033[0m" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_GuardGateMode)
	{
		std::cout << "ScavTrap " << this->_name << "\033[35m has entered in Gate keeper mode\033[0m" << std::endl;
		this->_GuardGateMode = true;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << "\033[35m has exited from Gate keeper mode\033[0m" << std::endl;
		this->_GuardGateMode = false;
	}
}
