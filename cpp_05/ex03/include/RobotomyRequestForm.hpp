/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:54:23 by daparici          #+#    #+#             */
/*   Updated: 2024/11/10 12:32:29 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

# undef SIGN_GRADE
# define SIGN_GRADE 72
# undef EXEC_GRADE
# define EXEC_GRADE 45

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
	
		// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);

		// Destructor
		virtual ~RobotomyRequestForm();

		// Operator
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

		// Member functions
		void executeAction() const;
};