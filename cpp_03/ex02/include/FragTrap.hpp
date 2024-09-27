/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:20:41 by daparici          #+#    #+#             */
/*   Updated: 2024/09/27 18:33:26 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
	
	public:
	
		//Constructor
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);

		//Destructor
		virtual	~FragTrap(void);

		//Overload operator
		FragTrap & operator=(FragTrap const & rhs);

		//Member function
		void	highFivesGuys(void);
};