/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:37:28 by daparici          #+#    #+#             */
/*   Updated: 2024/11/10 13:50:12 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;

	protected:
		virtual void executeAction() const = 0;
	public:
	
		// Constructors
		AForm();
		AForm(const std::string name, unsigned int signGrade, unsigned int execGrade);
		AForm(const AForm &cpy);

		// Destructor
		virtual ~AForm();

		// Operator
		AForm &operator=(const AForm &rhs);

		// Getters
		std::string getName() const;
		bool getSigned() const;
		unsigned int getSignGrade() const;
		unsigned int getExecGrade() const;

		// Setters

		void	setIsSigned(bool isSigned);

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
		
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

    	class FormSignedException : public std::exception
		{
        	public:
				const char *what() const throw();
		};
		
		

		// Member functions
		void beSigned(Bureaucrat &bureaucrat);
		void execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &out, const AForm &rhs);