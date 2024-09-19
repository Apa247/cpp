/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:17:31 by daparici          #+#    #+#             */
/*   Updated: 2024/09/19 17:08:21 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	testZombie(Zombie *Horde, int N)
{
	for (int i = 0; i < N; i++)
		Horde[i].announce();
}

int 	main(void)
{
	Zombie *Horde;
	int N = 5;

	Horde = zombieHorde(N, "Zombie_");
	if(!Horde)
		return 1;
	testZombie(Horde, N);
	delete [] Horde;
	return 0;
}
