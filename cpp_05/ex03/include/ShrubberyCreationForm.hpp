/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:58:27 by daparici          #+#    #+#             */
/*   Updated: 2024/11/10 12:32:33 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

# undef SIGN_GRADE
# define SIGN_GRADE 145
# undef EXEC_GRADE
# define EXEC_GRADE 137

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
	
		// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &cpy);

		// Destructor
		virtual ~ShrubberyCreationForm();

		// Operator
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

		// Member functions
		void executeAction() const;
};