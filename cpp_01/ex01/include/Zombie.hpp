/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:12:05 by daparici          #+#    #+#             */
/*   Updated: 2024/09/19 18:24:18 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream> // Include this at the top of zombieHorde.cpp

class Zombie
{
	private:
		std::string name;
	public:
		void	announce(void) const;
		void	setName(std::string name);
	
		Zombie(void);
		Zombie(std::string name);
		~Zombie();
};

Zombie* 		newZombie( std::string name );
Zombie*			zombieHorde( int N, std::string name );
std::string 	intToString(int number);

