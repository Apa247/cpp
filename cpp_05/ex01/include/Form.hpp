/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:37:28 by daparici          #+#    #+#             */
/*   Updated: 2024/10/08 23:50:33 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;

	public:
		// Constructors
		Form();
		Form(const std::string name, unsigned int signGrade, unsigned int execGrade);
		Form(const Form &cpy);

		// Destructor
		virtual ~Form();

		// Operator
		Form &operator=(const Form &rhs);

		// Getters
		std::string getName() const;
		bool getSigned() const;
		unsigned int getSignGrade() const;
		unsigned int getExecGrade() const;

		// exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		// Member functions
		void beSigned(Bureaucrat &bureaucrat);
};

std::ostream	&operator<<(std::ostream &out, const Form &rhs);