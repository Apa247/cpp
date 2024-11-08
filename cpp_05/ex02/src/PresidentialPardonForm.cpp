/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:57:01 by daparici          #+#    #+#             */
/*   Updated: 2024/11/07 20:06:15 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PresidentialPardonForm.hpp"

//------------------------- constructors --------------------------//

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", SIGN_GRADE, EXEC_GRADE), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", SIGN_GRADE, EXEC_GRADE), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy._name, cpy._signGrade, cpy._execGrade), _target(cpy._target)
{
	*this = cpy;
}

//-------------------------- destructor ---------------------------//

PresidentialPardonForm::~PresidentialPardonForm()
{
}

//--------------------------- operator ----------------------------//

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

//------------------------- member function ------------------------//

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
