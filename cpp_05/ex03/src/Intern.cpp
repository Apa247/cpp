/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:13:19 by daparici          #+#    #+#             */
/*   Updated: 2024/11/10 16:03:49 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//------------------------ Constructors ------------------------//

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;	
}

Intern::Intern(Intern const & src)
{
	std::cout << "Intern copy constructor called" << std::endl;	
	*this = src;
}

//------------------------ Destructor ------------------------//

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;	
}

//------------------------ Operator ------------------------//

Intern & Intern::operator=(Intern const & rhs)
{
	std::cout << "Intern assignation operator called" << std::endl;	
	if (this != &rhs)
	{
		// copy attributes here
	}
	return *this;
}

//------------------------ Member functions ------------------------//

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	formMaker formMakers[] = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};
	for (int i = 0; i < 3; i++)
	{
		if (form == formNames[i])
		{
			std::cout << "Intern creates " << formNames[i] << " form" << std::endl;
			return (this->*formMakers[i])(target);
		}
	}
	std::cout << "Error: Form name \"" << form << "\" not found." << std::endl;
	return NULL;
}

//------------------------ Form makers ------------------------//

AForm *Intern::makeShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}


