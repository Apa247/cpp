/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:30:57 by daparici          #+#    #+#             */
/*   Updated: 2024/09/27 09:31:05 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class	ClapTrap
{
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
		
	public:

		// Cosntructor
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		
		// Destructor
		~ClapTrap(void);

		// Overload operator
		ClapTrap & operator=(ClapTrap const & rhs);

		// Member function
		void	attack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};