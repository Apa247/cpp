/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:37:31 by daparici          #+#    #+#             */
/*   Updated: 2024/11/09 13:10:09 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

//------------------------- constructors --------------------------//

Form::Form() : _name("default"), _signed(false), _signGrade(LOWEST_GRADE), _execGrade(LOWEST_GRADE)
{
	std::cout << "Default Form Constructor called" << std::endl;
}

Form::Form(const std::string name, unsigned int signGrade, unsigned int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "Form Constructor called" << std::endl;
	if (signGrade < HIGHtEST_GRADE || execGrade < HIGHtEST_GRADE)
		throw Form::GradeTooHighException();
	else if (signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	this->_signed = false;
}

Form::Form(const Form &cpy) : _name(cpy._name + "_copy"), _signed(cpy._signed), _signGrade(cpy._signGrade), _execGrade(cpy._execGrade)
{
	std::cout << "Form Copy Constructor called" << std::endl;
	*this = cpy;
}

//-------------------------- destructor ---------------------------//

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

//--------------------------- operator ----------------------------//

Form &Form::operator=(const Form &rhs)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Form &rhs)
{
	out << rhs.getName() << ", form signed: " << rhs.getSigned() << ", sign grade: " << rhs.getSignGrade() << ", exec grade: " << rhs.getExecGrade();
	return out;
}

//------------------------- member function ------------------------//

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

unsigned int Form::getSignGrade() const
{
	return this->_signGrade;
}

unsigned int Form::getExecGrade() const
{
	return this->_execGrade;
}

//--------------------------- exceptions ---------------------------//

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high for this form...";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low for this form...";
}

//--------------------------- member function ----------------------//

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	else if (this->_signed == true)
		std::cout << this->getName() << " Form already signed" << std::endl;
	else
	{
		std::cout << this->getName() << " Form signed by " << bureaucrat.getName() << std::endl;
		this->_signed = true;
	}
}