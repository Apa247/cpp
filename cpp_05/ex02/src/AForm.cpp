/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:37:31 by daparici          #+#    #+#             */
/*   Updated: 2024/11/09 13:33:59 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//------------------------- constructors --------------------------//

AForm::AForm() : _name("default"), _signed(false), _signGrade(LOWEST_GRADE), _execGrade(LOWEST_GRADE)
{
}

AForm::AForm(const std::string name, unsigned int signGrade, unsigned int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < HIGHtEST_GRADE || execGrade < HIGHtEST_GRADE)
		throw AForm::GradeTooHighException();
	else if (signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
	this->_signed = false;
}

AForm::AForm(const AForm &cpy) : _name(cpy._name + "_copy"), _signed(cpy._signed), _signGrade(cpy._signGrade), _execGrade(cpy._execGrade)
{
	*this = cpy;
}

//-------------------------- destructor ---------------------------//

AForm::~AForm()
{
}

//--------------------------- operator ----------------------------//

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const AForm &rhs)
{
	out << rhs.getName() << ", form signed: " << rhs.getSigned() << ", sign grade: " << rhs.getSignGrade() << ", exec grade: " << rhs.getExecGrade();
	return out;
}

//------------------------- member function ------------------------//

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

unsigned int AForm::getSignGrade() const
{
	return this->_signGrade;
}

unsigned int AForm::getExecGrade() const
{
	return this->_execGrade;
}

//--------------------------- exceptions ---------------------------//

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high for this form...";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low for this form...";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form needs to be signed before executing";
}

//--------------------------- member function ----------------------//

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	else if (this->_signed == true)
		std::cout << this->getName() << " Form already signed" << std::endl;
	else
	{
		std::cout << this->getName() << " Form signed by " << bureaucrat.getName() << std::endl;
		this->_signed = true;
	}
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
}