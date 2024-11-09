/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:18:59 by daparici          #+#    #+#             */
/*   Updated: 2024/10/18 16:00:31 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack() const;
		
	private:
		std::string name;
		Weapon 		&weapon;
};