/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:15:05 by daparici          #+#    #+#             */
/*   Updated: 2024/09/30 21:46:01 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string _type;
		
	public:

		// Constructors
		WrongAnimal();
		WrongAnimal(const WrongAnimal &cpy);

		// Destructor
		virtual ~WrongAnimal();

		// Operator
		WrongAnimal &operator=(const WrongAnimal &rhs);

		// Member functions
		void makeSound() const;

		// Getters
		std::string getType() const;
};