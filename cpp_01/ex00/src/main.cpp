/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:41:07 by daparici          #+#    #+#             */
/*   Updated: 2024/09/19 16:05:59 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *z = newZombie("Zombie2");
	if (!z)
		return 1;
	z->announce();
	randomChump("Zombie1");
	delete z;
	randomChump("Zombie3");
	return 0;
}