/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:30:34 by daparici          #+#    #+#             */
/*   Updated: 2024/11/10 14:00:00 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//------------------------- constructors --------------------------//

Bureaucrat::Bureaucrat() : _name("default"), _grade(LOWEST_GRADE)
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	
	if (grade < HIGHtEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name + ("_copy")), _grade(cpy._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = cpy;
}

//-------------------------- destructor ---------------------------//

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

//--------------------------- operator ----------------------------//

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &rhs)
		_grade = rhs._grade;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return out;
}

//------------------------- member function ------------------------//

void Bureaucrat::incrementGrade()
{
	if (_grade <= HIGHtEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
}

void	Bureaucrat::signForm(AForm &form)
{
    try
	{
        form.beSigned(*this);  // Throws an exception if the bureaucrat can't sign the form
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
	catch (const std::exception &e)
	{
        std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executes " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " can't execute " << form.getName() << " because " << e.what() << std::endl;
	}
	
}

//----------------------------- getters ----------------------------//

std::string Bureaucrat::getName() const
{
	return this->_name;
}

unsigned int Bureaucrat::getGrade() const
{
	return this->_grade;
}

//--------------------------- exceptions ---------------------------//

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}
