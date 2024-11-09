/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:14:10 by daparici          #+#    #+#             */
/*   Updated: 2024/10/18 15:42:12 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie()
{
	std::cout << this->name << " is dead" << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void) const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}