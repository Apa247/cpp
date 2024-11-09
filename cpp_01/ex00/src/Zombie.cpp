/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:41:26 by daparici          #+#    #+#             */
/*   Updated: 2024/10/18 15:41:02 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("Zombie")
{
}

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie()
{
	std::cout << this->name << " is dead" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
