/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:03:32 by daparici          #+#    #+#             */
/*   Updated: 2024/11/10 15:41:34 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:

		typedef AForm *(Intern::*formMaker)(const std::string &target);

		AForm *makeShrubberyCreationForm(const std::string &target);
		AForm *makeRobotomyRequestForm(const std::string &target);
		AForm *makePresidentialPardonForm(const std::string &target);

	public:
	
		// Constructor
		Intern();
		Intern(Intern const & src);

		// Destructor
		~Intern();
		
		// Operator
		Intern & operator=(Intern const & rhs);

		// Member functions
		AForm *makeForm(const std::string &form, const std::string &target);
};