/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:41:23 by daparici          #+#    #+#             */
/*   Updated: 2024/10/18 15:41:31 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		
		void announce(void) const;
};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );
