/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 01:08:43 by daparici          #+#    #+#             */
/*   Updated: 2024/10/18 15:38:10 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <map>

class	Harl 
{
	public:
		Harl();
		~Harl();
		void complain(std::string level);
		
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};