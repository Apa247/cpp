/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:23:50 by daparici          #+#    #+#             */
/*   Updated: 2024/10/01 12:47:16 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>


class Animal
{
	protected:
		std::string _type;
		
	public:

		// Constructors
		Animal();
		Animal(const Animal &cpy);

		// Destructor
		virtual ~Animal();

		// Operator
		Animal &operator=(const Animal &rhs);

		// Member functions
		virtual void makeSound() const;

		// Getters
		std::string getType() const;
};

