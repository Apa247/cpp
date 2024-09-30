/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:38:52 by daparici          #+#    #+#             */
/*   Updated: 2024/09/30 11:41:33 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
	private:
	
	public:

		// Constructors
		Dog();
		Dog(const Dog &cpy);

		// Destructor
		virtual ~Dog();

		// Operator
		Dog &operator=(const Dog &rhs);

		// Member functions
		virtual void makeSound() const;
};