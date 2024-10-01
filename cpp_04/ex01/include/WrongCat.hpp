/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:16:33 by daparici          #+#    #+#             */
/*   Updated: 2024/09/30 20:16:56 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
	
	public:

		// Constructors
		WrongCat();
		WrongCat(const WrongCat &cpy);

		// Destructor
		virtual ~WrongCat();

		// Operator
		WrongCat &operator=(const WrongCat &rhs);

		// Member functions
		void makeSound() const;
};