/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:31:49 by daparici          #+#    #+#             */
/*   Updated: 2024/09/30 11:38:43 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	private:
	
	public:

		// Constructors
		Cat();
		Cat(const Cat &cpy);

		// Destructor
		virtual ~Cat();

		// Operator
		Cat &operator=(const Cat &rhs);

		// Member functions
		virtual void makeSound() const;
};