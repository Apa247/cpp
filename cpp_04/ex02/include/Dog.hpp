/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:38:52 by daparici          #+#    #+#             */
/*   Updated: 2024/10/01 22:39:22 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
	
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

		// Getters
		void getIdea(void) const;

		// Setters
		void setIdea(size_t i, std::string idea);
};