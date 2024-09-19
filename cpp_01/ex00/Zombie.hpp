/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:41:23 by daparici          #+#    #+#             */
/*   Updated: 2024/09/10 18:01:04 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie(/* args */);
		~Zombie();
		
		void announce(void);
};

Zombie::Zombie(/* args */)
{
}

Zombie::~Zombie()
{
}
