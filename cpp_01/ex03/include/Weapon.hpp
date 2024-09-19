/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:43:37 by daparici          #+#    #+#             */
/*   Updated: 2024/09/19 19:09:40 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Weapon
{
	public:
		Weapon(std::string type);
		Weapon();
		~Weapon();
		std::string const &getType();
		void setType(std::string type);
		
	private:
		std::string type;
};
