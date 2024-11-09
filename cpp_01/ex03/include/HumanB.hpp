/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:20:03 by daparici          #+#    #+#             */
/*   Updated: 2024/10/18 16:00:37 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon &weapon);
		~HumanB();
		void setWeapon(Weapon &weapon);
		void attack() const;
		
	private:
		std::string _name;
		Weapon *weapon;
};