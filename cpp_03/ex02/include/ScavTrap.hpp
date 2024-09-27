/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:20:44 by daparici          #+#    #+#             */
/*   Updated: 2024/09/27 18:34:31 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class	ScavTrap:	public ClapTrap
{
	private:
		bool	_GuardGateMode;

	public:
		// Cosntructor
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);

		// Destructor
		virtual	~ScavTrap(void);

		// Overload operator
		ScavTrap &operator=(ScavTrap const & rhs);

		// Member function
		void	attack(std::string const & target);
		void 	guardGate(void);
};
