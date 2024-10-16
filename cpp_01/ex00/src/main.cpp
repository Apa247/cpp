/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:41:07 by daparici          #+#    #+#             */
/*   Updated: 2024/10/17 01:07:22 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << " -> Create the Zombie Riri." << std::endl;
	Zombie riri = Zombie("Riri");
	riri.announce();

	std::cout << " -> Create the Zombie Fifi with newZombie()." << std::endl;
	Zombie*	fifi = newZombie("Fifi");
	fifi->announce();
	delete fifi;

	std::cout << " -> Create the Zombie Loulou with randomChump()." << std::endl;
	randomChump("Loulou");

	return 0;
}

/*
int	main(void)
{
	std::cout << "============= stackZombies =============" << std::endl;
	Zombie	zombie1("Zombie1");
	Zombie	zombie2("Zombie2");
	Zombie	zombie3;

	zombie1.announce();
	zombie2.announce();
	zombie3.announce();
	randomChump("randomChumpZ");

	std::cout << std::endl;
	std::cout << "============= heapZombies ==============" << std::endl;
	Zombie	*heapZ;

	heapZ = newZombie("HeapZ");
	heapZ->announce();
	delete(heapZ);

	return (0);
}

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
*/