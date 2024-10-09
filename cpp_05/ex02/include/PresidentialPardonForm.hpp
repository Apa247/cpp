/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:59:58 by daparici          #+#    #+#             */
/*   Updated: 2024/10/09 23:08:39 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

# undef SIGN_GRADE
# define SIGN_GRADE 25
# undef EXEC_GRADE
# define EXEC_GRADE 5

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;

	public:
	
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &cpy);

		// Destructor
		virtual ~PresidentialPardonForm();

		// Operator
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

		// Member functions
		void execute(Bureaucrat const &executor) const;
};