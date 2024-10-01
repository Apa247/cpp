/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:04:10 by daparici          #+#    #+#             */
/*   Updated: 2024/10/01 19:44:04 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string _ideas[100];
		
	public:

	// Constructors
		Brain();
		Brain(const Brain &cpy);

	// Destructor
		virtual ~Brain();

	// Operator
		Brain &operator=(const Brain &rhs);

	// Getters
		const std::string getIdea(int idx) const;
		const std::string *getIdeaAdress(size_t i) const;

	// Setters
		void setIdea(size_t i, std::string idea);
};