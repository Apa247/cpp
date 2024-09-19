/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:32:11 by daparici          #+#    #+#             */
/*   Updated: 2024/09/19 17:04:55 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string intToString(int number) {
    std::ostringstream convert;
    convert << number;
    return convert.str();
}

Zombie*	zombieHorde( int N, std::string name )
{
	if (N < 2)
	{
		std::cout << "Zombie horde must be at least 2" << std::endl;
		return NULL;
	}
	Zombie *zombie = new Zombie[N];
	if (!zombie)
	{
		std::cout << "Horde Memory allocation failed" << std::endl;
		return NULL;
	}
	for (int i = 0; i < N; i++)
		zombie[i].setName(name + intToString(i + 1));
	return zombie;
}