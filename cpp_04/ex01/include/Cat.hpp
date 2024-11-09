/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:31:49 by daparici          #+#    #+#             */
/*   Updated: 2024/11/01 14:04:31 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
	
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

		// Getters
		void getIdea(void) const;

		// Setters
		void setIdea(std::string idea, size_t i);
		
};