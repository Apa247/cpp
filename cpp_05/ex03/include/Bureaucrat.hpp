/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:30:20 by daparici          #+#    #+#             */
/*   Updated: 2024/11/10 13:10:41 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"	

#define HIGHtEST_GRADE 1
#define LOWEST_GRADE 150

class AForm;

class Bureaucrat
{
	private:
		const std::string 	_name;
		int 		_grade;
		
	public:

		// Constructors
		Bureaucrat();
		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat &cpy);

		// Destructor
		~Bureaucrat();

		// Operator
		Bureaucrat &operator=(const Bureaucrat &rhs);

		// Member functions
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const &form);

		// Getters
		std::string getName() const;
		unsigned int getGrade() const;

		// Exceptions
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
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);
